using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Text.RegularExpressions;
using System.IO;
using System.Xml;
using System.Threading;
using System.Reflection;

namespace Cybop.Designer.IntellisenseEditor
{
    public partial class EditorTextbox : UserControl
    {
        #region global class vars
        static Regex highLightRegexXmlBrackets1 = new Regex("</|<|/>|>", RegexOptions.Compiled);
        static Regex highLightRegexXmlTagContent = new Regex("[>]{1,1}[a-zA-Z0-9\\.\\ ]{1,1337}[<]{1,1}", RegexOptions.Compiled);
        static Regex highLightRegexXmlAttribute = new Regex("[\\ ]{1,1}[a-zA-Z0-9\\.\\ \\-_]{1,15}[=]{1,1}[\"]{1,1}[a-zA-Z0-9_:,;=\\?#~\\*\\\\\\-\\/\\.\\ .]{0,1227}[\"]{1,1}", RegexOptions.Compiled);
        static Regex highLightRegexXmlComments = new Regex("<!--[a-zA-Z0-9_:,;=\\?#~\\*\\\\\\-\\/\\.\\ .\\d\\D\\w\\W\\s\\S]{1,}-->", RegexOptions.Compiled);

        public delegate void TextChangedProcessedHandler(object sender, EventArgs e);
        public TextChangedProcessedHandler TextChangedProcessed;
        public EventHandler TextStatsChanged;

        public Color XmlBracketsColor = Color.Gold;
        public Color XmlAttributeValueColor = Color.Blue;
        public Color XmlAttributeKeyColor = Color.Pink;
        public Color XmlAttributeMarkUpColor = Color.Red;
        public Color XmlTagContentColor = Color.DarkCyan;
        public Color XmlCommentColor = Color.Olive;

        public string SelectedText
        {
            get { return richTextBoxEditor.SelectedText; }
            set { richTextBoxEditor.SelectedText = value; }
        }

        public TimeSpan HighLightTimeout = new TimeSpan(0, 0, 1);
        private DateTime? lastKeyEvent = null;
        bool suppressTimer = false;
        private int lastPaintedNumber = -1;

        public string StatTextLength
        {
            get { return labelStatLength.Text; }
        }

        public string StatTextLines
        {
            get { return labelStatLines.Text; }
        }

        public string StatTextPosition
        {
            get { return labelStatCurrentPos.Text; }
        }

        // this is used instead of \t when entering a tab to prevent ugly formatting
        public string TabReplacer = "    ";

        // this switch controls, whether auto completion of xml tags in next TextChanged is applied or not
        private bool suppressXmlTagComplete = false;

        // i heard u like dictionaries...
        // so i put a dictionary in your dictionary
        public Dictionary<string, Dictionary<string, IEnumerable<string>>> TagAttributeValueMapping = new Dictionary<string, Dictionary<string, IEnumerable<string>>>();

        bool isAutoCompleteActive = false;
        bool isTagFillActive = false;
        bool isRefPickerActive = false;

        private string textWhileAutoComplete
        {
            get { return _textWhileAutoComplete; }
            set { _textWhileAutoComplete = value;}
        }

        private string textWhileTagPicker { get; set; }

        public List<string> AutoCompleteWords = new List<string> { };

        string _textWhileAutoComplete;
        #endregion

        #region "Properties"

        public string Text {
            get
            {
                return this.richTextBoxEditor.Text;
            }
            set
            {
                this.richTextBoxEditor.Text = value;
            }
         }

        public Color BackcolorTextEditor
        {
            get
            {
                return this.richTextBoxEditor.BackColor;
            }
            set
            {
                this.richTextBoxEditor.BackColor = value;
            }
        }
        #endregion

        public EditorTextbox()
        {
            InitializeComponent();

            textWhileTagPicker = "";
            textWhileAutoComplete = "";
            this.TextChangedProcessed += new TextChangedProcessedHandler(OnTextChangedProcessed);
            textBoxLineNumbers.Font = new Font(richTextBoxEditor.Font.FontFamily, richTextBoxEditor.Font.Size); //+ 1.019f);
            richTextBoxEditor.Focus();
            timer1.Interval = 200;
            timer1.Start();

        }

        private void splitContainer1_SizeChanged(object sender, EventArgs e)
        {
            textBoxLineNumbers.Height = richTextBoxEditor.Height;
        }


        /// <summary>
        /// Malt die TextBox bunt an
        /// </summary>
        public static void HighLight(Color xmlBracketsColor, Color xmlAttributeValueColor, 
            Color xmlAttributeKeyColor, Color xmlAttributeMarkupColor, Color xmlTagContentColor, Color xmlCommentColor, ref RichTextBox target )
        {
            target.Enabled = false;
            MatchCollection mColBrackets = highLightRegexXmlBrackets1.Matches(target.Text);
            MatchCollection mColAttributes = highLightRegexXmlAttribute.Matches(target.Text);
            MatchCollection mColXmlContent = highLightRegexXmlTagContent.Matches(target.Text);
            MatchCollection mColXmlComments = highLightRegexXmlComments.Matches(target.Text);

            int resetPos = target.SelectionStart;
            int resetLength = target.SelectionLength;

            if (mColAttributes.Count > 0 || mColBrackets.Count > 0 || mColXmlContent.Count > 0 || mColXmlComments.Count > 0)
            {
                // reset complete coloring
                target.Select(0, target.Text.Length);
                target.SelectionColor = target.ForeColor;
            }

            if (mColBrackets.Count > 0)
            {
                // < > </ />
                foreach (Match m in mColBrackets)
                {
                    target.Select(m.Index, m.Length);
                    target.SelectionColor = xmlBracketsColor;

                }

                target.SelectionStart = resetPos;
                target.SelectionLength = resetLength;
            }
            if (mColAttributes.Count > 0)
            {
                // foo="bar"
                foreach (Match m in mColAttributes)
                {
                    string txt = m.ToString();
                    int indexOfEqual = txt.IndexOf("=");
                    // alles mit ValueColor anmalen
                    target.Select(m.Index, m.Length);
                    target.SelectionColor = xmlAttributeValueColor;

                    target.Select(m.Index + indexOfEqual, 2);
                    // =" anmalen
                    target.SelectionColor = xmlAttributeMarkupColor;
                    int lastIndex = txt.LastIndexOf('"');
                    // finales " anmalen
                    target.Select(m.Index + lastIndex, 1);
                    target.SelectionColor = xmlAttributeMarkupColor;

                    //key anmalen
                    target.Select(m.Index, indexOfEqual);
                    target.SelectionColor = xmlAttributeKeyColor;

                }

                target.SelectionStart = resetPos;
                target.SelectionLength = resetLength;
            }

            if (mColXmlContent.Count > 0)
            {
                // >bar<
                foreach (Match m in mColXmlContent)
                {
                    // finding still contains the < and > so cut that shit off
                    target.Select(m.Index + 1, m.Length - 2);
                    target.SelectionColor = xmlTagContentColor;

                }

                target.SelectionStart = resetPos;
                target.SelectionLength = resetLength;
            }
            if (mColXmlComments.Count > 0)
            {
                // <!-- foo bar -->
                foreach ( Match m in mColXmlComments)
                {
                    target.Select(m.Index, m.Length);
                    target.SelectionColor = xmlCommentColor;
                }

                target.SelectionStart = resetPos;
                target.SelectionLength = resetLength;
            }
            target.Enabled = true;
            target.Focus();
            target.SelectionStart = resetPos;
            target.SelectionLength = resetLength;
            target.SelectionColor = target.ForeColor;
        }

        /// <summary>
        /// Selects the part of the textbox' text specified, beginning at Index with the 
        /// length of Length
        /// </summary>
        /// <param name="Index"></param>
        /// <param name="Length"></param>
        public void SelectText(int Index, int Length)
        {
            richTextBoxEditor.Select(Index, Length);
        }

        /// <summary>
        /// Replace all occurencies of the specified string in the textbox' text
        /// with the specified replacement string
        /// </summary>
        /// <param name="replaceThis"></param>
        /// <param name="withThis"></param>
        public void ReplaceText(string replaceThis, string withThis)
        {
            richTextBoxEditor.Text = richTextBoxEditor.Text.Replace(replaceThis, withThis);
        }

        /// <summary>
        /// Cuts the currently selected Text out of the TextBox, throws it to Clipboard
        /// and returns the cutted string
        /// </summary>
        /// <returns></returns>
        public string CutText()
        {
            int resetPos = richTextBoxEditor.SelectionStart;
            string txt = richTextBoxEditor.SelectedText;
            if (!string.IsNullOrEmpty(txt))
            {
                Clipboard.SetText(txt);
                richTextBoxEditor.SelectedText = string.Empty;
                richTextBoxEditor.SelectionStart = resetPos;
            }
            return txt;
        }

        /// <summary>
        /// Copies the selected text of the textbox to Clipboard and returns the
        /// copied text
        /// </summary>
        /// <returns></returns>
        public string CopyText()
        {
            int resetPos = richTextBoxEditor.SelectionStart;
            string txt = richTextBoxEditor.SelectedText;
            if (!String.IsNullOrEmpty(txt))
            {
                Clipboard.SetText(txt);
            }
            return txt;
        }

        /// <summary>
        /// Fügt den angegebenen Text an die aktuelle Markierungsposition der Textbox ein
        /// </summary>
        /// <param name="text">Der Einzufügende Text</param>
        /// <param name="throwOnSelectedText">Legt fest, ob eine InvalidOperationException ausgelöst werden soll,
        /// wenn in der Textbox Text ausgewählt ist und überschrieben werden würde</param>
        public void PasteText(string text, bool throwOnSelectedText = false)
        {
            if (throwOnSelectedText)
            {
                if (richTextBoxEditor.SelectionLength > 0)
                {
                    throw new InvalidOperationException("In der Textbox wurde ein Text selektiert!");
                }
            }
            int resetPos = richTextBoxEditor.SelectionStart + text.Length - richTextBoxEditor.SelectionLength;
            richTextBoxEditor.SelectedText = text;
            richTextBoxEditor.SelectionStart = resetPos;
        }

        private void MatchLineNumbers()
        {
            //we get index of first visible char and 
            //number of first visible line
            Point pos = new Point(0, 0);
            int firstIndex = richTextBoxEditor.GetCharIndexFromPosition(pos);
            int firstLine = richTextBoxEditor.GetLineFromCharIndex(firstIndex);

            //now we get index of last visible char 
            //and number of last visible line
            pos.X = splitContainer1.Location.X + splitContainer1.Panel1.Width + (splitContainer1.Width - splitContainer1.Panel1.Width - splitContainer1.Panel2.Width);
            pos.Y = ClientRectangle.Height;
            int lastIndex = richTextBoxEditor.GetCharIndexFromPosition(pos);
            int lastLine = richTextBoxEditor.GetLineFromCharIndex(lastIndex);

            //this is point position of last visible char, we'll 
            //use its Y value for calculating numberLabel size
            pos = richTextBoxEditor.GetPositionFromCharIndex(lastIndex);

            textBoxLineNumbers.Enabled = false;
            textBoxLineNumbers.SuspendLayout();
            textBoxLineNumbers.ResetText();
            for (int i = firstLine; i <= lastLine + 1; i++)
            {
                textBoxLineNumbers.Text += i + 1 + Environment.NewLine;
            }
            textBoxLineNumbers.ResumeLayout();
            textBoxLineNumbers.Enabled = true;
        }

        #region Process Special Keys
        private void ProcessTab(out bool wasAction)
        {
            if (!String.IsNullOrEmpty(richTextBoxEditor.SelectedText))
            {
                int resetPoint = richTextBoxEditor.SelectionStart;
                int selLength = richTextBoxEditor.SelectionLength;
                richTextBoxEditor.SelectedText = TabReplacer + richTextBoxEditor.SelectedText;
                richTextBoxEditor.SelectionStart = resetPoint + 1;
                richTextBoxEditor.SelectionLength = selLength;
                wasAction = true;
            }
            else
            {
                int selStart = richTextBoxEditor.SelectionStart;
                // make a tab 4 " "s as otherwise tab looks ugly
                richTextBoxEditor.SelectedText = TabReplacer;
                // suppress further processing of key
                wasAction = true;
            }
        }

        private void ProcessShiftTab(out bool wasAction)
        {
            //if (!String.IsNullOrEmpty(richTextBoxEditor.SelectedText))
            {
                int pos = richTextBoxEditor.SelectionStart;
                int length = richTextBoxEditor.SelectionLength;
                if (pos > 3)
                {
                    string textLeft = "";
                    for (int i = 1; i <= 4; i++)
                    {
                        textLeft = richTextBoxEditor.Text.ElementAt<char>(pos - 1) + textLeft;
                    }
                    if (textLeft == "    ")
                    {
                        richTextBoxEditor.Select(pos - 4, 4);
                        richTextBoxEditor.SelectedText = String.Empty;
                        //string text = richTextBoxEditor.SelectedText;
                        //int resetPos = richTextBoxEditor.SelectionStart - 1;
                        //richTextBoxEditor.SelectionStart = pos - 1;
                        //int selLength = richTextBoxEditor.SelectionLength;
                        //richTextBoxEditor.SelectedText = text;
                        //int resetPoint = richTextBoxEditor.SelectionStart;
                        //richTextBoxEditor.Text = richTextBoxEditor.Text.Remove(pos - 1 + length, 1);
                        //if (resetPoint < richTextBoxEditor.TextLength - 1)
                        //{
                        //    richTextBoxEditor.SelectionStart = resetPoint;
                        //}
                        //else
                        //{
                        //    richTextBoxEditor.SelectionStart = resetPoint - 1;
                        //}

                        //richTextBoxEditor.SelectionStart = resetPos;
                        //richTextBoxEditor.SelectionLength = selLength;
                    }
                    else
                    {
                        System.Media.SystemSounds.Beep.Play();
                    }
                }
                wasAction = true;
            }
            //else
            //{
            //    wasAction = false;
            //}



        }

        private void ProcessXMLOpen()
        {
            //Point pt = textBoxKeyIn.GetPositionFromCharIndex(textBoxKeyIn.SelectionStart);
            //pt.Y += ((int)Math.Ceiling(this.textBoxKeyIn.Font.GetHeight())) * 2;
            //this.listBox1.Location = pt;
            //this.listBox1.Visible = true;

            //int xPos = listBox1.Location.X + listBox1.Width;
            //if (xPos > textBoxKeyIn.Width + textBoxKeyIn.Location.X)
            //{
            //    Point newLocation = new Point(textBoxKeyIn.Width + textBoxKeyIn.Location.X - listBox1.Width, listBox1.Location.Y);
            //    listBox1.Location = newLocation;
            //}
            
            textWhileAutoComplete = "";
            listBoxAutoComplete.Location = GetOffsetForAutoCompleteBox(ref listBoxAutoComplete);
            listBoxAutoComplete.Visible = true;
            FillAutoCompleteElements();
            listBoxAutoComplete.BringToFront();
        }

        private void ProcessXMLClose()
        {
            // dunno y, but its here, its linked, feel free to use it...
        }
        #endregion

        #region Fill AutoComplete Boxes
        private void FillAutoCompleteElements()
        {
            listBoxAutoComplete.Items.Clear();

            string[] itemsRaw = AutoCompleteWords.Where<string>(t => t.StartsWith(textWhileAutoComplete)).ToArray<string>();
            Array.Sort(itemsRaw);

            foreach (string vorschlag in itemsRaw)
            {
                listBoxAutoComplete.Items.Add(vorschlag);
            }
            if (itemsRaw.Count<string>() < 1)
            {
                listBoxAutoComplete.Visible = false;
            }
        }

        private void FillTagCompleteBox(IEnumerable<string> values)
        {
            listBoxTagFiller.Items.Clear();
            foreach (string element in values)
            {
                listBoxTagFiller.Items.Add(element);
            }

        }

        private void ReMatchTagPicker()
        {
            List<string> fit = new List<string>();
            List<string> noFit = new List<string>();
            foreach (object x in listBoxTagFiller.Items)
            {
                string s = (string)x;
                if (!s.StartsWith(textWhileTagPicker))
                {
                    noFit.Add(s);
                }
                else
                {
                    fit.Add(s);
                }
            }
            string[] fitA = fit.ToArray();
            string[] noFitA = noFit.ToArray();

            Array.Sort(fitA);
            Array.Sort(noFitA);

            string selThis = (string)listBoxTagFiller.SelectedItem;
            listBoxTagFiller.Items.Clear();
            foreach (string s in fitA)
            {
                listBoxTagFiller.Items.Add(s);
            }
            foreach (string s in noFitA)
            {
                listBoxTagFiller.Items.Add(s);
            }
            listBoxTagFiller.SelectedItem = selThis;
        }
        #endregion

        #region Editor TextBox Event Handlers
        private void textBoxKeyIn_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.OemBackslash ||
              e.KeyValue == 226)
            {
                if (e.KeyCode == (Keys.OemBackslash & Keys.Shift) ||
                    (e.KeyCode == (Keys.OemBackslash & Keys.LShiftKey)) ||
                    (e.KeyCode == (Keys.OemBackslash & Keys.RShiftKey)) ||
                    (e.KeyCode == (Keys.OemBackslash & Keys.ShiftKey)) ||
                    (e.KeyCode == Keys.OemBackslash && e.Shift == true)
                    )
                {


                    //
                }
            }
            suppressTimer = false;
        }

        private void textBoxKeyIn_TextChanged(object sender, EventArgs e)
        {
            if (richTextBoxEditor.Lines.Count() != lastPaintedNumber)
            {
                MatchLineNumbers();
                lastPaintedNumber = richTextBoxEditor.Lines.Count();
            }
            int prePos = richTextBoxEditor.SelectionStart;
            if (richTextBoxEditor.Text.Length < 2 || richTextBoxEditor.SelectionStart < 2)
            {
                TextChangedProcessed(this, e);
                return;
            }
            char lastChar = richTextBoxEditor.Text.ElementAt<char>(richTextBoxEditor.SelectionStart - 1);
            if (lastChar != '>')
            {
                TextChangedProcessed(this, e);
                return;
            }

            if (suppressXmlTagComplete)
            {
                suppressXmlTagComplete = false;
                TextChangedProcessed(this, e);
                return;
            }

            int cursorPos = richTextBoxEditor.SelectionStart;
            bool isCursorAtEnd = false;

            if (cursorPos == richTextBoxEditor.Text.Length)
            {
                isCursorAtEnd = true;
            }

            if (isCursorAtEnd || true)
            {
                int posCounter = cursorPos - 1;
                if (richTextBoxEditor.Text.ElementAt<Char>(posCounter) == '>')
                {
                    posCounter--;
                }
                bool foundAny = false;
                char found = ' ';

                string processedString = "";

                while (!foundAny && posCounter != -1)
                {
                    char character = richTextBoxEditor.Text.ElementAt<Char>(posCounter);
                    processedString = character + processedString;
                    if (character == '<')
                    {
                        foundAny = true;
                        found = '<';
                    }
                    if (character == '>')
                    {
                        foundAny = true;
                        found = '>';
                    }
                    posCounter--;
                }

                if (!foundAny || processedString.EndsWith("/"))
                {

                    richTextBoxEditor.SelectionStart = prePos;
                    richTextBoxEditor.Focus(); TextChangedProcessed(this, e); return;
                }

                // letztes xml tag zeichen ist open 
                if (found == '<')
                {
                    string xmlTag = GetXmlTagOpen(processedString);
                    if (xmlTag.StartsWith("</"))
                    {
                        richTextBoxEditor.SelectionStart = prePos;
                        richTextBoxEditor.Focus(); TextChangedProcessed(this, e); return;
                    }
                    string closeTag = "</" + xmlTag.Substring(1) + ">";
                    closeTag = closeTag.Replace(" ", "");
                    int pos = richTextBoxEditor.SelectionStart;

                    string followingText = richTextBoxEditor.Text.Substring(pos);
                    if (!followingText.Contains("</") || followingText.IndexOf("</") != followingText.IndexOf(closeTag))
                    {
                        richTextBoxEditor.SelectionColor = richTextBoxEditor.ForeColor;
                        if (isCursorAtEnd)
                        {
                            
                            richTextBoxEditor.Select(richTextBoxEditor.Text.Length,0);
                            richTextBoxEditor.SelectedText =  closeTag;
                            richTextBoxEditor.SelectionStart = pos;
                            richTextBoxEditor.SelectionLength = 0;
                            richTextBoxEditor.Focus();
                        }
                        else
                        {
                            int pos2 = richTextBoxEditor.SelectionStart;
                            richTextBoxEditor.SelectedText = closeTag;
                            richTextBoxEditor.SelectionStart = pos2;
                            richTextBoxEditor.SelectionLength = 0;
                            richTextBoxEditor.Focus();
                        }
                        listBoxAutoComplete.Visible = false;
                    }
                }
            }
            TextChangedProcessed(this, e);
        }

        private void textBoxKeyIn_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (isAutoCompleteActive)
            {
                textWhileAutoComplete += e.KeyChar;
                // backspace
                if (e.KeyChar == (char)8)
                {
                    if (textWhileAutoComplete.Length > 1)
                    {
                        textWhileAutoComplete = textWhileAutoComplete.Remove(textWhileAutoComplete.Length - 2);
                    }
                    else
                    {
                        textWhileAutoComplete = "";
                    }
                }
                FillAutoCompleteElements();
            }
            if (isTagFillActive)
            {
                textWhileTagPicker += e.KeyChar;
                // backspace
                if (e.KeyChar == (char)8)
                {
                    if (textWhileTagPicker.Length > 1)
                    {
                        textWhileTagPicker = textWhileTagPicker.Remove(textWhileTagPicker.Length - 2);
                    }
                    else
                    {
                        textWhileTagPicker = "";
                    }
                }
                ReMatchTagPicker();
            }
        }

        private void textBoxKeyIn_KeyDown(object sender, KeyEventArgs e)
        {
            suppressTimer = true;
            richTextBoxEditor.SelectionColor = richTextBoxEditor.ForeColor;
            #region < & >
            if (e.KeyCode == Keys.OemBackslash ||
            e.KeyValue == 226)
            {
                if (e.KeyCode == (Keys.OemBackslash & Keys.Shift) ||
                    (e.KeyCode == (Keys.OemBackslash & Keys.LShiftKey)) ||
                    (e.KeyCode == (Keys.OemBackslash & Keys.RShiftKey)) ||
                    (e.KeyCode == (Keys.OemBackslash & Keys.ShiftKey)) ||
                    (e.KeyCode == Keys.OemBackslash && e.Shift == true)
                    )
                {
                    ProcessXMLClose();
                }
                else
                {
                    ProcessXMLOpen();
                }
            }
            #endregion

            #region [tab]
            if (e.KeyCode == Keys.Tab || e.KeyValue == 9)
            {
                if (e.KeyCode == (Keys.Tab & Keys.Shift) ||
                    (e.KeyCode == (Keys.Tab & Keys.LShiftKey)) ||
                    (e.KeyCode == (Keys.Tab & Keys.RShiftKey)) ||
                    (e.KeyCode == (Keys.Tab & Keys.ShiftKey)) ||
                    (e.KeyCode == Keys.Tab && e.Shift == true)
                    )
                {
                    bool handled;
                    ProcessShiftTab(out handled);
                    e.Handled = handled;
                    e.SuppressKeyPress = handled;
                }
                else
                {
                    bool handled;
                    ProcessTab(out handled);
                    e.Handled = handled;
                    e.SuppressKeyPress = handled;
                }
            }
            #endregion

            #region [ctrl]+[space]
            if (e.KeyCode == Keys.Space && e.Control == true)
            {
                e.Handled = true;
                e.SuppressKeyPress = true;
                //if (textBoxKeyIn.SelectionLength > 0)
                //{
                //    return;
                //}

                MatchCollection mCol = highLightRegexXmlAttribute.Matches(richTextBoxEditor.Text);
                Match m = null;
                int cPos = richTextBoxEditor.SelectionStart;

                foreach (Match match in mCol)
                {
                    if (match.Index <= cPos && (match.Index + match.Length >= cPos))
                    {
                        m = match;
                        break;
                    }
                }


                #region stuff down here is ...

                string textLeftToXmlKey = "";
                string textRightToXmlKey = "";
                int startPos = richTextBoxEditor.SelectionStart;


                bool selIsEnd = false;
                if (startPos >= richTextBoxEditor.Text.Length)
                {
                    selIsEnd = true;
                }
                int pos = startPos;
                if (selIsEnd)
                {
                    pos--;
                }
                char c = richTextBoxEditor.Text.ElementAt<char>(pos);
                char keyLeft = ' ';
                char keyRight = ' ';
                int wentLeft = 0;
                int wentRight = 0;

                while (c != '<' && c != '>' && pos != 0)
                {
                    textLeftToXmlKey = c + textLeftToXmlKey;
                    pos--;
                    wentLeft++;
                    c = richTextBoxEditor.Text.ElementAt<char>(pos);
                }
                keyLeft = c;
                c = ' ';

                pos = startPos;
                while (c != '<' && c != '>' && pos < richTextBoxEditor.Text.Length)
                {
                    textRightToXmlKey += c;
                    pos++;
                    wentRight++; try
                    {
                        c = richTextBoxEditor.Text.ElementAt<char>(pos);
                    }
                    catch (ArgumentOutOfRangeException)
                    {
                        break;
                    }
                }
                keyRight = c;
                if (keyRight != '>' && keyRight != '<')
                {
                    keyRight = ' ';
                }

                if (keyLeft == '<' && (keyRight == ' ' || keyRight == '>'))
                {
                    int posC = richTextBoxEditor.SelectionStart;
                    //if (textBoxKeyIn.SelectionLength > 0)
                    //{
                    //    return;
                    //}
                    string tagString = richTextBoxEditor.Text.Substring(richTextBoxEditor.SelectionStart - wentLeft, wentLeft + wentRight).TrimStart();
                    if (tagString.Contains(" "))
                    {
                        tagString = tagString.Substring(0, tagString.IndexOf(" ") + 1).Replace("<", "").Trim();
                    }
                    // tagString is "foobar" of "<foobar "   hopefully...

                    if (m != null)
                    {
                        string matchText = richTextBoxEditor.Text.Substring(m.Index, m.Length).TrimStart();
                        int indexOfFirstStringOpener = matchText.IndexOf('"');
                        int lastIndexOfStringOpener = matchText.LastIndexOf('"');

                        string attributeName = matchText.Substring(0, indexOfFirstStringOpener - 1);
                        IEnumerable<string> values = LookupAttributeValues(tagString, attributeName);
                        // TODO: throw values to special ListBox, together with Selection Parameters
                        // TODO: hide new ListBox on KeyPress
                        richTextBoxEditor.Enabled = true;
                        FillTagCompleteBox(values);
                        listBoxTagFiller.Visible = true;
                        listBoxTagFiller.Location = GetOffsetForAutoCompleteBox(ref listBoxTagFiller);
                        listBoxTagFiller.BringToFront();
                    }
                }
                #endregion
                richTextBoxEditor.Enabled = true;
            }

            #endregion

            #region Pfeil runter
            if (e.KeyCode == Keys.Down)
            {
                if (isAutoCompleteActive && listBoxAutoComplete.Visible)
                {
                    e.Handled = true;
                    e.SuppressKeyPress = true;
                    listBoxAutoComplete.Focus();

                    listBoxAutoComplete.SelectedIndex = 0;
                }
                if (isTagFillActive && listBoxTagFiller.Visible)
                {
                    e.Handled = true;
                    e.SuppressKeyPress = true;
                    listBoxTagFiller.Focus();
                    listBoxTagFiller.SelectedIndex = 0;
                }
                if (isRefPickerActive)
                {
                    e.Handled = true;
                    e.SuppressKeyPress = true;
                    listBoxRefPicker.Focus();
                    listBoxRefPicker.SelectedIndex = 0;
                }
            }

            #endregion

            if (e.KeyCode == Keys.Back)
            {
                suppressXmlTagComplete = true;
            }

        }

        private void textBoxKeyIn_Click(object sender, EventArgs e)
        {
            if (isAutoCompleteActive)
            {
                listBoxAutoComplete.Visible = false;
            }
            if (isTagFillActive)
            {
                listBoxTagFiller.Visible = false;
            }
            richTextBoxEditor.Focus();
        }

        public void OnTextChangedProcessed(object sender, EventArgs e)
        {
            //HighLight(XmlBracketsColor, XmlAttributeValueColor, XmlAttributeKeyColor,
            //    XmlAttributeMarkUpColor, XmlTagContentColor, XmlCommentColor, ref richTextBoxEditor);
            if (richTextBoxEditor.Lines.Count() != lastPaintedNumber)
            {
                MatchLineNumbers();
                lastPaintedNumber = richTextBoxEditor.Lines.Count();
            }
            FillStats();
            lastKeyEvent = DateTime.Now;
        }
        #endregion

        #region Helper Functions
        string GetXmlTagOpen(string processedString)
        {
            string tag = "";
            int startPos = processedString.IndexOf('<');
            char read = '<';

            while (read != ' ' && startPos != processedString.Length)
            {
                read = processedString.ElementAt<char>(startPos);
                tag += read;
                startPos++;

            }

            return tag;
        }

        /// <summary>
        /// Formattiert den XML-Text
        /// </summary>
        /// <param name="xml"></param>
        /// <returns></returns>
        private static string IndentXMLString(string xml)
        {
            string outXml = string.Empty;
            MemoryStream ms = new MemoryStream();
            // Create a XMLTextWriter that will send its output to a memory stream (file)
            XmlTextWriter xtw = new XmlTextWriter(ms, Encoding.Unicode);
            xtw.IndentChar = ' ';
            xtw.Indentation = 4;
            XmlDocument doc = new XmlDocument();

            try
            {
                // Load the unformatted XML text string into an instance 
                // of the XML Document Object Model (DOM)
                doc.LoadXml(xml);

                // Set the formatting property of the XML Text Writer to indented
                // the text writer is where the indenting will be performed
                xtw.Formatting = Formatting.Indented;

                // write dom xml to the xmltextwriter
                doc.WriteContentTo(xtw);
                // Flush the contents of the text writer
                // to the memory stream, which is simply a memory file
                xtw.Flush();

                // set to start of the memory stream (file)
                ms.Seek(0, SeekOrigin.Begin);
                // create a reader to read the contents of 
                // the memory stream (file)
                StreamReader sr = new StreamReader(ms);
                // return the formatted string to caller
                return sr.ReadToEnd();
            }
            catch (Exception ex)
            {
                throw;
            }
        }



        /// <summary>
        /// Gibt eine Liste von Zeichenketten zurück, die als Werte für das angegebene Attribut im angegebenen Tag in Frage kommen
        /// </summary>
        /// <param name="xmlTag">Das XML-Tag, in dem nach Wertem für das Attribut gesucht werden soll.</param>
        /// <param name="Attribute">Das XML-Attribut, nach dessen Werten gesucht werden soll.</param>
        /// <returns></returns>
        private IEnumerable<string> LookupAttributeValues(string xmlTag, string Attribute)
        {
            try
            {
                Dictionary<string, IEnumerable<string>> dict;
                TagAttributeValueMapping.TryGetValue(xmlTag, out dict);
                return dict.First(z => z.Key == Attribute).Value;
            }
            catch
            {
                return new string[0];
            }
        }
        #endregion

        private void buttonFormat_Click(object sender, EventArgs e)
        {
            try
            {
                string newText = IndentXMLString(richTextBoxEditor.Text);
                if (newText != "")
                {
                    richTextBoxEditor.Text = newText;
                }
            }
            catch
            {
                MessageBox.Show("What ever you entered there, it is definitly NOT valid XML.");
            }
        }

        #region List Box stuff

        #region List Boxes Visible Changed
        private void listBoxTagFiller_VisibleChanged(object sender, EventArgs e)
        {
            if (listBoxTagFiller.Visible)
            {
                listBoxTagFiller.BringToFront();
                isTagFillActive = true;
                if (isAutoCompleteActive)
                {
                    listBoxAutoComplete.Visible = false;
                }
                if (isRefPickerActive)
                {
                    listBoxRefPicker.Visible = false;
                }
                if (listBoxTagFiller.Items.Count < 1)
                {
                    listBoxTagFiller.Hide();
                }
            }
            else
            {
                isTagFillActive = false;
                textWhileTagPicker = "";
            }

        }

        private void listBoxRefPicker_VisibleChanged(object sender, EventArgs e)
        {
            if (listBoxRefPicker.Visible)
            {
                listBoxRefPicker.BringToFront();
                isRefPickerActive = true;
                if (isAutoCompleteActive)
                {
                    richTextBoxEditor.Visible = false;
                }
                if (isTagFillActive)
                {
                    listBoxTagFiller.Visible = false;
                }
            }
            else
            {
                isRefPickerActive = false;
            }
        }

        private void listBox1_VisibleChanged(object sender, EventArgs e)
        {
            if (richTextBoxEditor.Visible)
            {
                richTextBoxEditor.BringToFront();
                this.isAutoCompleteActive = true;
                if (isTagFillActive)
                {
                    listBoxTagFiller.Visible = false;
                }
                if (isRefPickerActive)
                {
                    listBoxRefPicker.Visible = false;
                }
            }
            else
            {
                this.isAutoCompleteActive = false;
                textWhileAutoComplete = string.Empty;
            }
        }
        #endregion

        #region List Boxes DoubleClick
        private void listBoxTagFiller_DoubleClick(object sender, EventArgs e)
        {
            if (listBoxTagFiller.SelectedItem != null)
            {
                string txt = listBoxTagFiller.SelectedItem as string;
                richTextBoxEditor.SelectedText = txt;
                richTextBoxEditor.SelectionLength = 0;
                listBoxTagFiller.Hide();
                richTextBoxEditor.Focus();
            }
        }

        private void listBox1_DoubleClick(object sender, EventArgs e)
        {
            if (listBoxAutoComplete.SelectedItem != null)
            {
                string txt = listBoxAutoComplete.SelectedItem as string;
                richTextBoxEditor.SelectedText = txt.Substring(textWhileAutoComplete.Length);
                richTextBoxEditor.SelectionLength = 0;
                listBoxAutoComplete.Hide();
            }
        }
        #endregion

        #region List Boxes Key Press
        private void listBoxTagFiller_KeyPress(object sender, KeyPressEventArgs e)
        {
            // if char != [Enter]
            if (e.KeyChar != (char)13)
            {
                return;
            }
            if (listBoxTagFiller.SelectedItem != null)
            {
                listBoxTagFiller_DoubleClick(sender, new EventArgs());
            }
        }

        private void listBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            // if char != [Enter]
            if (e.KeyChar != (char)13)
            {
                return;
            }
            if (listBoxAutoComplete.SelectedItem != null)
            {
                listBox1_DoubleClick(sender, new EventArgs());
            }
        }
        #endregion

        // enables top and bottom "overflow" when scrolling through content of listbox with arrow keys
        private void listBoxGeneric_KeyDown(object sender, KeyEventArgs e)
        {
            ListBox lb = sender as ListBox;
            if (e.KeyCode == Keys.Up)
            {
                if (lb.SelectedIndex == 0)
                {
                    lb.SelectedIndex = lb.Items.Count - 1;
                    e.SuppressKeyPress = true;
                    e.Handled = true;
                }
            }
            else if (e.KeyCode == Keys.Down)
            {
                if (lb.SelectedIndex == lb.Items.Count - 1)
                {
                    lb.SelectedIndex = 0;
                    e.SuppressKeyPress = true;
                    e.Handled = true;
                }
            }
        }

        #endregion

        public void SetFocus(){
            this.richTextBoxEditor.Focus();
         }

        private void textBoxKeyIn_VScroll(object sender, EventArgs e)
        {
            //move location of numberLabel for amount of pixels caused by scrollbar
            int d = richTextBoxEditor.GetPositionFromCharIndex(0).Y % (richTextBoxEditor.Font.Height + 1);
            //textBoxLineNumbers.Location = new Point(0, d);
            MatchLineNumbers();
        }

        private void textBoxKeyIn_FontChanged(object sender, EventArgs e)
        {
            // sync fonts of both text boxes
            textBoxLineNumbers.Font = new Font(richTextBoxEditor.Font.FontFamily, richTextBoxEditor.Font.Size);
        }

        private Point GetOffsetForAutoCompleteBox(ref ListBox listBox)
        {
            Point pt;
            pt = richTextBoxEditor.GetPositionFromCharIndex(richTextBoxEditor.SelectionStart);
            pt.Y += Convert.ToInt32(((int)Math.Ceiling(this.richTextBoxEditor.Font.GetHeight())) ); // * 1.25);
            int xPos = listBox.Location.X + listBox.Width;
            //pt.X += richTextBoxEditor.Location.X + splitContainer1.Panel1.Width + splitContainer1.SplitterWidth;
            //xPos += richTextBoxEditor.Location.X;
            if (xPos > richTextBoxEditor.Width + richTextBoxEditor.Location.X)
            {
                Point newLocation = new Point(richTextBoxEditor.Width + richTextBoxEditor.Location.X - listBox.Width, listBox.Location.Y);
                return newLocation;
            }


            return pt;
        }

        private void EditorTextbox_Load(object sender, EventArgs e)
        {
            this.ActiveControl = richTextBoxEditor;
        }

        // cut
        private void toolStripMenuItem3_Click(object sender, EventArgs e)
        {
            ContextMenuCut();
        }

        public void ContextMenuCut()
        {
            int resetPos = richTextBoxEditor.SelectionStart;
            string txt = richTextBoxEditor.SelectedText;
            if (!string.IsNullOrEmpty(txt))
            {
                Clipboard.SetText(txt);
                richTextBoxEditor.SelectedText = string.Empty;
                richTextBoxEditor.SelectionStart = resetPos;
                contextMenuStrip1.Hide();
            }            
        }

        // copy
        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            ContextMenuCopy();
        }

        public void ContextMenuCopy()
        {
            int resetPos = richTextBoxEditor.SelectionStart;
            string txt = richTextBoxEditor.SelectedText;
            if (!String.IsNullOrEmpty(txt))
            {
                Clipboard.SetText(txt);
                contextMenuStrip1.Hide();
            }
        }

        // paste
        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {
            ContextMenuPaste();
        }

        public void ContextMenuPaste()
        {
            string txt = Clipboard.GetText();
            richTextBoxEditor.SelectedText = txt;
            contextMenuStrip1.Hide();
        }

        // undo
        private void toolStripMenuItem5_Click(object sender, EventArgs e)
        {
            ContextMenuUndo();
        }

        public void ContextMenuUndo()
        {
            richTextBoxEditor.Undo();
        }

        private void contextMenuStrip1_VisibleChanged(object sender, EventArgs e)
        {
            if (contextMenuStrip1.Visible)
            {
                toolStripMenuItem5.Enabled = richTextBoxEditor.CanUndo;
                toolStripMenuItem3.Enabled = richTextBoxEditor.SelectionLength > 0;
                toolStripMenuItem1.Enabled = richTextBoxEditor.SelectionLength > 0;
                this.contextMenuStrip1.BringToFront();

            }
            else
            {

            }
        }
        // format
        private void toolStripMenuItem4_Click(object sender, EventArgs e)
        {
            try
            {
                string newText = IndentXMLString(richTextBoxEditor.Text);
                if (newText != "")
                {
                    richTextBoxEditor.Select(0, richTextBoxEditor.Text.Length);
                    richTextBoxEditor.SelectionColor = richTextBoxEditor.ForeColor;
                    richTextBoxEditor.Text = newText;
                }
            }
            catch
            {
                MessageBox.Show("What ever you entered there, it is definitly NOT valid XML.");
            }
        }

        private void FillStats()
        {
            int length = richTextBoxEditor.Text.Length;
            int lines = richTextBoxEditor.Lines.Count<string>();
            int cLine = richTextBoxEditor.GetLineFromCharIndex(richTextBoxEditor.SelectionStart);
            int cRow = richTextBoxEditor.GetFirstCharIndexOfCurrentLine() * -1 + richTextBoxEditor.SelectionStart;

            labelStatLength.Text = length+ " Zeichen";
            labelStatLines.Text = lines + " Zeilen";
            labelStatCurrentPos.Text = "Zeile: " + (cLine + 1) + "; Position: " + (cRow+1);
            labelStatCurrentPos.BringToFront();
            labelStatLength.BringToFront();
            labelStatLines.BringToFront();
            try
            {
                TextStatsChanged(this, new EventArgs());
            }
            catch (NullReferenceException)
            {

            }
        }

        private void richTextBoxEditor_SelectionChanged(object sender, EventArgs e)
        {
            FillStats();
        }

        private void richTextBoxEditor_SizeChanged(object sender, EventArgs e)
        {
            FillStats();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if ( lastKeyEvent != null && !suppressTimer && (DateTime.Now > (lastKeyEvent + HighLightTimeout)))
            {
                Thread worker = new Thread(new ThreadStart(ThreadedHighLight));
                worker.Priority = ThreadPriority.Highest;

                worker.Start();

                //HighLight(XmlBracketsColor, XmlAttributeValueColor, XmlAttributeKeyColor,
                //    XmlAttributeMarkUpColor, XmlTagContentColor, XmlCommentColor, ref richTextBoxEditor);
                
                
                lastKeyEvent = null;
            }
        }

        void ThreadedHighLight()
        {
            //this.Invoke(new Action( this.SuspendLayout));
            SetControlPropertyThreadSafe(richTextBoxEditor, "Enabled", false);
            string rtfToFormat = (string)richTextBoxEditor.Invoke(new Func<string>(() => richTextBoxEditor.Rtf));
            int resetPos = (int)richTextBoxEditor.Invoke(new Func<int>(() => richTextBoxEditor.SelectionStart));
            RichTextBox rtb = new RichTextBox();
            rtb.Rtf = rtfToFormat;
            rtb.SuspendLayout();
            HighLight(XmlBracketsColor, XmlAttributeValueColor, XmlAttributeKeyColor,
                    XmlAttributeMarkUpColor, XmlTagContentColor, XmlCommentColor, ref rtb);
            SetControlPropertyThreadSafe(richTextBoxEditor, "Rtf", rtb.Rtf);

            SetControlPropertyThreadSafe(richTextBoxEditor, "Enabled", true);
            //this.Invoke(new Action(this.ResumeLayout));
            SetControlPropertyThreadSafe(richTextBoxEditor, "SelectionStart", resetPos);
            richTextBoxEditor.Invoke(new FocusDelegate(richTextBoxEditor.Focus));
        }

        private delegate bool FocusDelegate();

        private delegate void SetControlPropertyThreadSafeDelegate(Control control, string propertyName, object propertyValue);

        public static void SetControlPropertyThreadSafe(Control control, string propertyName, object propertyValue)
        {
            if (control.InvokeRequired)
            {
                control.Invoke(new SetControlPropertyThreadSafeDelegate(SetControlPropertyThreadSafe), new object[] { control, propertyName, propertyValue });
            }
            else
            {
                control.GetType().InvokeMember(propertyName, BindingFlags.SetProperty, null, control, new object[] { propertyValue });
            }
        }

        private void EditorTextbox_VisibleChanged(object sender, EventArgs e)
        {
            if (this.Visible)
            {
                timer1.Start();
            }
            else
            {
                timer1.Stop();
            }
        }

        private void listBoxAutoComplete_DoubleClick(object sender, EventArgs e)
        {
            if (listBoxAutoComplete.SelectedItem != null)
            {
                string txt = listBoxAutoComplete.SelectedItem as string;
                richTextBoxEditor.SelectedText = txt.Substring(textWhileAutoComplete.Length);
                richTextBoxEditor.SelectionLength = 0;
                listBoxAutoComplete.Hide();
                lastKeyEvent = DateTime.Now;
            }
        }

        private void listBoxAutoComplete_KeyPress(object sender, KeyPressEventArgs e)
        {
            // if char != [Enter]
            if (e.KeyChar != (char)13)
            {
                return;
            }
            if (listBoxAutoComplete.SelectedItem != null)
            {
                listBoxAutoComplete_DoubleClick(sender, new EventArgs());
            }
        }

        private void listBoxTagFiller_KeyPress_1(object sender, KeyPressEventArgs e)
        {
            // if char != [Enter]
            if (e.KeyChar != (char)13)
            {
                return;
            }
            if (listBoxTagFiller.SelectedItem != null)
            {
                listBoxTagFiller_DoubleClick(sender, new EventArgs());
            }
        }

        private void listBoxTagFiller_DoubleClick_1(object sender, EventArgs e)
        {
            listBoxTagFiller_DoubleClick(sender, e);
        }

    }
}
