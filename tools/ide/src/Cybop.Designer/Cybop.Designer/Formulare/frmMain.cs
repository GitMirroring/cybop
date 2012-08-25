using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Cybop.Designer.Formulare
{
    public partial class frmMain : Form
    {

        #region "Members"
        private Data.Project _Project;
        private frmNavigation _NavigationForm;
        #endregion

        #region "Konstruktor"

        public frmMain()
        {
            InitializeComponent();
            Clipboard.Clear();
        }

        #endregion

        #region "Properties"

        public TabControl EditorTab { get { return this.tcEditor; } }

        public frmNavigation Navigation { get { return this._NavigationForm; } }

        #endregion

        #region "Events"

        #region "Form"

        private void frmMain_Load(object sender, EventArgs e)
        {
            InitializeControls();
        }

        private void frmMain_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (_Project != null)
            {

                if (this.tcEditor.TabCount > 0)
                {
                    CommitChanges();
                }

                if (_Project.IsDirty)
                {

                    switch (MessageBox.Show("Möchten Sie das Projekt '" + _Project.Name + "' Speichern?", this.Text, MessageBoxButtons.YesNoCancel, MessageBoxIcon.Question))
                    {
                        case System.Windows.Forms.DialogResult.Yes:
                            bool SaveUs = false;
                            if (string.IsNullOrEmpty(_Project.FilePath))
                            {
                                SaveUs = true;
                            }
                             
                            if (!SaveProjekt(SaveUs)){
                                 e.Cancel = true;   
                            }

                            break;
                        case System.Windows.Forms.DialogResult.Cancel:
                            e.Cancel = true;
                            break;
                    }


                }
            }
        }

        #endregion

        #region "Main-Menu"

        #region "Datei"

        private void neuToolStripMenuItem_Click(object sender, EventArgs e)
        {
            NewProjekt();
        }

        private void oeffnenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenProject();
        }

        private void speichernToolStripMenuItem_Click(object sender, EventArgs e)
        {
            bool SaveUs = false;
            if (string.IsNullOrEmpty(_Project.FilePath))
            {
                SaveUs = true;
            }
            SaveProjekt(SaveUs);
        }

        private void speichernUnternToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveProjekt(true);
        }

        private void beendenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        #endregion

        #region "Fenster"

        private void navigationToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (_NavigationForm.Visible != true)
            {
                navigationToolStripMenuItem.CheckState = CheckState.Checked;
                _NavigationForm.Visible = true;
            }
            else
            {
                navigationToolStripMenuItem.CheckState = CheckState.Unchecked;
                _NavigationForm.Close();
            }
        }

        private void fensterToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (_NavigationForm == null)
            {
                navigationToolStripMenuItem.Enabled = false;
            }
            else
            {
                navigationToolStripMenuItem.Enabled = true;

                if (_NavigationForm.Visible == true)
                {
                    navigationToolStripMenuItem.CheckState = CheckState.Checked;
                }
                else
                {
                    navigationToolStripMenuItem.CheckState = CheckState.Unchecked;
                }
            }
        }

        #endregion

        #region "Extras"

        private void kommentarblockFestlegenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmComment frmComment = new frmComment();
            frmComment.MdiParent = this;
            frmComment.Show();
        }

        private void einstellungenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmOption frmOption = new frmOption();
            frmOption.ShowDialog();
        }

        #endregion

        #region "Bearbeiten"

        private void ausschneidenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.tcEditor.SelectedTab != null)
            {
                IntellisenseEditor.EditorTextbox editor = this.tcEditor.SelectedTab.Controls["edit" + this.tcEditor.SelectedTab.Name] as IntellisenseEditor.EditorTextbox;
                if (editor != null)
                {
                    editor.ContextMenuCut();
                }
            }
        }

        private void kopierenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.tcEditor.SelectedTab != null)
            {
                IntellisenseEditor.EditorTextbox editor = this.tcEditor.SelectedTab.Controls["edit" + this.tcEditor.SelectedTab.Name] as IntellisenseEditor.EditorTextbox;
                if (editor != null)
                {
                    editor.ContextMenuCopy();
                }
            }
        }

        private void einfuegenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.tcEditor.SelectedTab != null)
            {
                IntellisenseEditor.EditorTextbox editor = this.tcEditor.SelectedTab.Controls["edit" + this.tcEditor.SelectedTab.Name] as IntellisenseEditor.EditorTextbox;
                if (editor != null)
                {
                    editor.ContextMenuPaste();
                }
            }
        }

        private void rueckgaengigToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.tcEditor.SelectedTab != null)
            {
                IntellisenseEditor.EditorTextbox editor = this.tcEditor.SelectedTab.Controls["edit" + this.tcEditor.SelectedTab.Name] as IntellisenseEditor.EditorTextbox;
                if (editor != null)
                {
                    editor.ContextMenuUndo();
                }
            }
        }

        private void wiederholenToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        #endregion

        #endregion

        #region "Symbolleiste"

        private void toolStripButtonKommentarblock_Click(object sender, EventArgs e)
        {
            if (this.tcEditor.SelectedTab != null)
            {
                IntellisenseEditor.EditorTextbox editor = this.tcEditor.SelectedTab.Controls["edit" + this.tcEditor.SelectedTab.Name] as IntellisenseEditor.EditorTextbox;
                if (editor != null)
                {
                    editor.PasteText(Properties.Settings.Default.CommentBlock);
                }
            }
        }

        private void toolStripButtonCopy_Click(object sender, EventArgs e)
        {
            if (this.tcEditor.SelectedTab != null)
            {
                IntellisenseEditor.EditorTextbox editor = this.tcEditor.SelectedTab.Controls["edit" + this.tcEditor.SelectedTab.Name] as IntellisenseEditor.EditorTextbox;
                if (editor != null)
                {
                    editor.ContextMenuCopy();
                }
            }
        }

        private void toolStripButtonPaste_Click(object sender, EventArgs e)
        {
            if (this.tcEditor.SelectedTab != null)
            {
                IntellisenseEditor.EditorTextbox editor = this.tcEditor.SelectedTab.Controls["edit" + this.tcEditor.SelectedTab.Name] as IntellisenseEditor.EditorTextbox;
                if (editor != null)
                {
                    editor.ContextMenuPaste();
                }
            }
        }

        private void toolStripButtonReturn_Click(object sender, EventArgs e)
        {
            if (this.tcEditor.SelectedTab != null)
            {
                IntellisenseEditor.EditorTextbox editor = this.tcEditor.SelectedTab.Controls["edit" + this.tcEditor.SelectedTab.Name] as IntellisenseEditor.EditorTextbox;
                if (editor != null)
                {
                    editor.ContextMenuUndo();
                }
            }
        }

        private void toolStripButtonCut_Click(object sender, EventArgs e)
        {
            if (this.tcEditor.SelectedTab != null)
            {
                IntellisenseEditor.EditorTextbox editor = this.tcEditor.SelectedTab.Controls["edit" + this.tcEditor.SelectedTab.Name] as IntellisenseEditor.EditorTextbox;
                if (editor != null)
                {
                    editor.ContextMenuCut();
                }
            }
        }

        private void toolStripButtonForward_Click(object sender, EventArgs e)
        {

        }

        private void toolStripButtonSearch_Click(object sender, EventArgs e)
        {
            frmSuche frmSuche = new frmSuche("",_Project, 0, this);
            frmSuche.BringToFront();
            frmSuche.TopMost = true;
            frmSuche.Show();
        }

        private void toolStripButtonFindReplace_Click(object sender, EventArgs e)
        {
            frmSuche frmSuche = new frmSuche("", _Project, 1, this);
            frmSuche.BringToFront();
            frmSuche.TopMost = true;
            frmSuche.Show();
        }

        #endregion

        #region "Tab-Page"
        
        private void tcEditor_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            CloseFile();
        }

        private void tcEditor_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == System.Windows.Forms.MouseButtons.Right)
            {

                if (this.tcEditor.SelectedTab != null)
                {
                    ContextMenuStrip contextMenu = new ContextMenuStrip();
                    ToolStripMenuItem contextMenuItem = contextMenu.Items.Add("Schließen", null, new EventHandler(TabPageClose_Click)) as ToolStripMenuItem;
                   
                    contextMenuItem = contextMenu.Items.Add("Alle schließen", null, new EventHandler(TabPageCloseAll_Click)) as ToolStripMenuItem;
                    contextMenuItem = contextMenu.Items.Add("Alle außer diesem schließen", null, new EventHandler(TabPageCloseAllExceptThis_Click)) as ToolStripMenuItem;
                    
                    contextMenu.Show(Cursor.Position);
                }

            }
        }

        private void TabPageClose_Click(object sender, EventArgs e)
        {
            if (this.tcEditor.SelectedTab != null)
            {
                CloseFile();
            }
        }

        private void TabPageCloseAll_Click(object sender, EventArgs e)
        {
            foreach (TabPage item in this.tcEditor.TabPages)
            {
                CloseFile(item);
            }
        }

        private void TabPageCloseAllExceptThis_Click(object sender, EventArgs e)
        {
            foreach (TabPage item in this.tcEditor.TabPages)
            {
                if (item != this.tcEditor.SelectedTab)
                {
                    CloseFile(item);
                }
            }
        }

        private void tcEditor_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (this.tcEditor.SelectedTab != null)
            {
                IntellisenseEditor.EditorTextbox editor = this.tcEditor.SelectedTab.Controls["edit" + this.tcEditor.SelectedTab.Name] as IntellisenseEditor.EditorTextbox;
                UpdateStatsText(editor);
            }
        }

        #endregion

        #region "Text-Editor"

        private void Editor_TextStatsChenged(object sender, EventArgs e)
        {
            IntellisenseEditor.EditorTextbox editor = sender as IntellisenseEditor.EditorTextbox;
            UpdateStatsText(editor);
        }

        #endregion

        #endregion

        #region "Funktionen"

        #region "Neu"

        /// <summary>
        /// Erstellt ein neues Projekt.
        /// </summary>
        private void NewProjekt()
        {

            bool CreateNewProject = true;

            if (_Project != null)
	        {

                if (this.tcEditor.TabCount > 0)
                {
                    CommitChanges();
                }

		       if (_Project.IsDirty)
	            {

                   switch (MessageBox.Show("Möchten Sie das Projekt '" + _Project.Name + "' Speichern?", this.Text, MessageBoxButtons.YesNoCancel, MessageBoxIcon.Question))
                    {
                       case System.Windows.Forms.DialogResult.Yes:
                               bool SaveUs = false;
                               if (string.IsNullOrEmpty(_Project.FilePath))
	                           {
		                            SaveUs = true;
	                           }
                               SaveProjekt(SaveUs);
                            break;
                       case System.Windows.Forms.DialogResult.Cancel:
                            CreateNewProject = false;
                            break;
                    }

                   
	            }
            }

            if (CreateNewProject)
            {
                _Project = new Data.Project();

                frmNew frmNew = new frmNew(ref _Project);

                if (frmNew.ShowDialog() != System.Windows.Forms.DialogResult.OK)
                {
                    _Project = null;
                }

                InitializeControls();
            }
                       
        }

        /// <summary>
        /// Öffnet ein vorhandenes Projekt.
        /// </summary>
        private void OpenProject()
        {
            bool CanOpenProject = true;

            if (_Project != null)
            {

                if (this.tcEditor.TabCount > 0)
                {
                    CommitChanges();
                }

                if (_Project.IsDirty)
                {

                    switch (MessageBox.Show("Möchten Sie das Projekt '" + _Project.Name + "' Speichern?", this.Text, MessageBoxButtons.YesNoCancel, MessageBoxIcon.Question))
                    {
                        case System.Windows.Forms.DialogResult.Yes:
                            bool SaveUs = false;
                            if (string.IsNullOrEmpty(_Project.FilePath))
                            {
                                SaveUs = true;
                            }
                            SaveProjekt(SaveUs);
                            break;
                        case System.Windows.Forms.DialogResult.Cancel:
                            CanOpenProject = false;
                            break;
                    }


                }
            }

            if (CanOpenProject)
            {
                _Project = new Data.Project();

                OpenFileDialog openFile = new OpenFileDialog();
                openFile.CheckFileExists = true;
                openFile.CheckPathExists = true;
                openFile.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
                openFile.Multiselect = false;
                openFile.Filter = "CYBOL-Project (*.cybolprj)|*.cybolprj";
                openFile.AddExtension = false;

                if (openFile.ShowDialog() != System.Windows.Forms.DialogResult.OK)
                {
                    _Project = null;
                }

                try
                {
                    _Project.Load(openFile.FileName);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                    _Project = null;
                }

                InitializeControls();
            }
        }

        #endregion

        #region "Speichern"

        private bool SaveProjekt(bool SaveUs)
        {

            string FilePath = string.Empty;
            string FileName = string.Empty;
            string Directory = string.Empty;

            if (this.tcEditor.TabPages.Count > 0)
            {
                CommitChanges();
            }

            try
            {

                if (SaveUs)
                {
                    SaveFileDialog SaveFileDialog = new SaveFileDialog();
                    SaveFileDialog.AddExtension = true;
                    SaveFileDialog.CheckPathExists = true;
                    SaveFileDialog.DefaultExt = "cybolprj";
                    SaveFileDialog.Filter = "CYBOL-Project (*.cybolprj)|*.cybolprj";
                    SaveFileDialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
                    SaveFileDialog.FileName = _Project.Name;

                    if (SaveFileDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                    {
                        FilePath = SaveFileDialog.FileName;
                        System.IO.FileInfo file = new System.IO.FileInfo(FilePath);
                        FileName = file.Name;
                        Directory = file.DirectoryName;
                    }
                    else
                    {
                        return false;
                    }

                    _Project.FilePath = FilePath;
                    _Project.FileName = FileName;
                    _Project.FolderPath = Directory;

                }

                _Project.Save();
               
                return true;

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return false;
            }

        }

        #endregion

        #region "Öffnen"

        /// <summary>
        /// Öffnet das Dokument.
        /// </summary>
        public void OpenFile(Data.Element element, TreeNode node)
        {

            if (!element.IsOpen)
            {
                TabPage newTabPage = new TabPage(element.Name);
                IntellisenseEditor.EditorTextbox editor = new IntellisenseEditor.EditorTextbox();
                editor.Anchor = AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right | AnchorStyles.Top;
                newTabPage.Name = element.ID.ToString();
                newTabPage.Tag = node;
                editor.Name = "edit" + element.ID.ToString();
                editor.XmlAttributeKeyColor = Properties.Settings.Default.XmlAttributeKey;
                editor.XmlAttributeMarkUpColor = Properties.Settings.Default.XmlAttributeMarkup;
                editor.XmlAttributeValueColor = Properties.Settings.Default.XmlAttributeValue;
                editor.XmlBracketsColor = Properties.Settings.Default.XmlBrackets;
                editor.XmlCommentColor = Properties.Settings.Default.XmlKommentar;
                editor.XmlTagContentColor = Properties.Settings.Default.XmlTagContent;
                editor.Font = Properties.Settings.Default.Schriftart;
                editor.ForeColor = Properties.Settings.Default.Schriftfarbe;
                editor.BackcolorTextEditor = Properties.Settings.Default.Hintergrundfarbe;
                editor.TextStatsChanged += new EventHandler(Editor_TextStatsChenged);
                LoadList(editor);

                this.tcEditor.TabPages.Add(newTabPage);
                editor.Size = new Size(this.tcEditor.Size.Width, this.tcEditor.Size.Height);
                if (element.Content.GetType() == typeof(string))
                {
                    editor.Text = System.Convert.ToString(element.Content);
                }
                
                newTabPage.Controls.Add(editor);
                element.IsOpen = true;
                this.tcEditor.SelectTab(element.ID.ToString());
                editor.SetFocus();
            }
            else
            {
                this.tcEditor.SelectTab(element.ID.ToString());
                TabPage selectedTab = this.tcEditor.TabPages[element.ID.ToString()];
                if (selectedTab != null)
                {
                    if (selectedTab.Tag.Equals(node))
                    {
                         IntellisenseEditor.EditorTextbox editorText = selectedTab.Controls["edit" + element.ID.ToString()] as IntellisenseEditor.EditorTextbox;
                        if (editorText != null)
                        {
                            editorText.SetFocus();
                        }
                    }                   
                }

            }

            CheckSymbolleiste();

        }

        private void CheckSymbolleiste()
        {
            bool IsEnabled = false;

            if (tcEditor.TabCount > 0)
            {
                IsEnabled = true;
            }

            //Symbolleitse
            toolStripMain.Enabled = IsEnabled;

            //Menü Bearbeiten

            kopierenToolStripMenuItem.Enabled = IsEnabled;
            einfuegenToolStripMenuItem.Enabled = IsEnabled;
            rueckgaengigToolStripMenuItem.Enabled = IsEnabled;
            wiederholenToolStripMenuItem.Enabled = IsEnabled;

            if (this.tcEditor.SelectedTab != null)
            {
                this.toolStripStatusLabelStateTextPosition.Visible = true;
                this.toolStripStatusLabelStatTextLength.Visible = true;
                this.toolStripStatusLabelStatTextLines.Visible = true;
            }
            else
            {
                this.toolStripStatusLabelStateTextPosition.Visible = false;
                this.toolStripStatusLabelStatTextLength.Visible = false;
                this.toolStripStatusLabelStatTextLines.Visible = false;
            }          

        }

        private void LoadList(IntellisenseEditor.EditorTextbox editor)
        {
            Dictionary<string, Dictionary<string, IEnumerable<string>>> prodData;
            List<string> AutoCompleteWords;

            GenerateAutoCompleteRessources(Main.Models, out AutoCompleteWords, out prodData);

            editor.AutoCompleteWords = AutoCompleteWords;
            editor.TagAttributeValueMapping = prodData;
        }

        void GenerateAutoCompleteRessources(List<Cybop.Designer.Data.Model> rawData, out List<string> AutoCompleteWords, out Dictionary<string, Dictionary<string, IEnumerable<string>>> TagAttributeMapping)
        {
            AutoCompleteWords = new List<string>();
            TagAttributeMapping = new Dictionary<string, Dictionary<string, IEnumerable<string>>>();

            #region fill auto complete words
            foreach (Cybop.Designer.Data.Model tag in rawData)
            {
                StringBuilder autoCompleteEntry = new StringBuilder();
                autoCompleteEntry.Append("<");
                autoCompleteEntry.Append(tag.Name);

                foreach (Cybop.Designer.Data.Attribute z in tag.Attributes)
                {
                    autoCompleteEntry.Append(" " + z.Name + "=\"\"");
                }
                if (tag.Name.ToLower() == "property")
                {
                    autoCompleteEntry.Append("/>");
                }
                else
                {
                    autoCompleteEntry.Append(">");
                }
                AutoCompleteWords.Add(autoCompleteEntry.ToString());
            }
            #endregion

            foreach (Cybop.Designer.Data.Model tag in rawData)
            {
                string l1Key = tag.Name;
                Dictionary<string, IEnumerable<string>> TagToValues = new Dictionary<string, IEnumerable<string>>();
                foreach (Cybop.Designer.Data.Attribute x in tag.Attributes)
                {
                    string l2Key = x.Name;
                    List<string> values = new List<string>();
                    foreach (Cybop.Designer.Data.Property y in x.Properties)
                    {
                        values.Add(y.Name);
                    }
                    TagToValues.Add(l2Key, (IEnumerable<string>)values);
                }
                TagAttributeMapping.Add(l1Key, TagToValues);
            }
        }

        #endregion

        #region "Changes"

        /// <summary>
        /// Übernimmt die Änerungen in die Objekte.
        /// </summary>
        private void CommitChanges()
        {
            foreach (TabPage item in this.tcEditor.TabPages)
            {
                string tabName = item.Name;
                IntellisenseEditor.EditorTextbox editor = item.Controls["edit" + tabName] as IntellisenseEditor.EditorTextbox;
                if (editor != null)
                {

                    TreeNode node = item.Tag as TreeNode;
                    Data.ElementCollection elements = node.Parent.Tag as Data.ElementCollection;

                    Data.Element element = null;

                    if (elements != null)
                    {
                        element = elements.ToList().Find(el => el.ID.ToString() == tabName);
                    }
                    
                    if (element  != null)
                    {
                        string value = string.Empty;

                        if (element.Content.GetType()==typeof(string))
                        {
                            value = System.Convert.ToString(element.Content);
                        }

                        if (value != editor.Text)
                        {
                            element.Content = editor.Text;
                        }
                                                
                    }
                }
            }
        }

        #endregion

        #region "Schliessen"

        /// <summary>
        /// Schließt die Datei und übernimmt die Werte.
        /// </summary>
        private void CloseFile()
        {
            if (this.tcEditor.SelectedTab != null)
            {
                string tabName = this.tcEditor.SelectedTab.Name;
                IntellisenseEditor.EditorTextbox editor = this.tcEditor.SelectedTab.Controls["edit" + tabName] as IntellisenseEditor.EditorTextbox;
                if (editor != null)
                {

                    TreeNode node = this.tcEditor.SelectedTab.Tag as TreeNode;
                    Data.ElementCollection elements = node.Parent.Tag as Data.ElementCollection;

                    Data.Element element = null;

                    if (elements != null)
                    {
                        element = elements.ToList().Find(el => el.ID.ToString() == tabName);
                    }
                 
                    if (element  != null)
                    {
                        element.Content = editor.Text;
                        element.IsOpen = false;
                    }
                }

                this.tcEditor.TabPages.RemoveByKey(tabName);
            }
            
        }

        private void CloseFile(TabPage tab)
        {
            if (tab != null)
            {
                string tabName = tab.Name;
                IntellisenseEditor.EditorTextbox editor = tab.Controls["edit" + tabName] as IntellisenseEditor.EditorTextbox;
                if (editor != null)
                {
                    TreeNode node = tab.Tag as TreeNode;
                    Data.ElementCollection elements = node.Parent.Tag as Data.ElementCollection;

                    Data.Element element = null;

                    if (elements != null)
                    {
                        element = elements.ToList().Find(el => el.ID.ToString() == tabName);
                    }
                 
                    if (element  != null)
                    {
                        element.Content = editor.Text;
                        element.IsOpen = false;
                    }
                }

                    this.tcEditor.TabPages.RemoveByKey(tabName);
               }
        }

        #endregion

        #region "Allgemein"

        /// <summary>
        /// Initialisiert die Steuerelemente auf dem Formular.
        /// </summary>
        private void InitializeControls()
        {
            // Revision der Anwendung ausgeben.
            this.lblRevision.Text = Application.ProductName + " " + Application.ProductVersion;

            //InitializeMenuShortCut(ref this.neuToolStripMenuItem,  "Strg+N", Keys.ControlKey|Keys.N);
            //InitializeMenuShortCut(ref this.beendenToolStripMenuItem, "Alt+F4", Keys.Alt | Keys.F4);
            //InitializeMenuShortCut(ref this.einfuegenToolStripMenuItem, "Strg+V", Keys.ControlKey | Keys.V);
            //InitializeMenuShortCut(ref this.kopierenToolStripMenuItem, "Strg+C", Keys.ControlKey | Keys.C);
            //InitializeMenuShortCut(ref this.oeffnenToolStripMenuItem, "Strg+O", Keys.ControlKey | Keys.O);
            //InitializeMenuShortCut(ref this.rueckgaengigToolStripMenuItem, "Strg+Z", Keys.ControlKey | Keys.Z);
            //InitializeMenuShortCut(ref this.wiederholenToolStripMenuItem, "Strg+W", Keys.ControlKey | Keys.W);
            //InitializeMenuShortCut(ref this.speichernToolStripMenuItem, "Strg+S", Keys.ControlKey | Keys.S);
            //InitializeMenuShortCut(ref this.speichernUnternToolStripMenuItem, "Strg+Alt+S", Keys.ControlKey | Keys.Alt | Keys.S);

            if (_Project == null)
            {

                // Main-Menü
                this.speichernToolStripMenuItem.Enabled = false;
                this.speichernUnternToolStripMenuItem.Enabled = false;

                
                // Form Navigation
                if (_NavigationForm != null)
                {
                    _NavigationForm.Close();
                    _NavigationForm.Dispose();
                }
                _NavigationForm = null;

                this.tcEditor.TabPages.Clear();
                this.tcEditor.Visible = false;

            }
            else
            {

                // Main-Menü
                this.speichernToolStripMenuItem.Enabled = true;
                this.speichernUnternToolStripMenuItem.Enabled = true;

                //Panel Main

                //Form Navigation
                _NavigationForm = new frmNavigation(this, ref _Project);
                _NavigationForm.SetDesktopLocation(this.Width - _NavigationForm.Width - 50, 100);
                _NavigationForm.Show();

                this.tcEditor.Visible = true;

            }

            //Symbolleitse
            toolStripMain.Enabled = false;

            //Menü Bearbeiten

            kopierenToolStripMenuItem.Enabled = false;
            einfuegenToolStripMenuItem.Enabled = false;
            rueckgaengigToolStripMenuItem.Enabled = false;
            wiederholenToolStripMenuItem.Enabled = false;

            this.toolStripStatusLabelStateTextPosition.Visible = false;
            this.toolStripStatusLabelStatTextLength.Visible = false;
            this.toolStripStatusLabelStatTextLines.Visible = false;

        }

        /// <summary>
        /// Initialisiert die ShortCuts.
        /// </summary>
        /// <param name="menuItem"></param>
        /// <param name="displayString"></param>
        /// <param name="keys"></param>
        private void InitializeMenuShortCut(ref ToolStripMenuItem menuItem, string displayString, Keys keys)
        {
            menuItem.ShowShortcutKeys = true;
            menuItem.ShortcutKeyDisplayString = displayString;
            menuItem.ShortcutKeys = keys;
        }

        private void UpdateStatsText(IntellisenseEditor.EditorTextbox editor)
        {
            if (editor != null)
            {
                toolStripStatusLabelStatTextLength.Text = editor.StatTextLength;
                toolStripStatusLabelStatTextLines.Text = editor.StatTextLines;
                toolStripStatusLabelStateTextPosition.Text = editor.StatTextPosition;
            }
        }

        #endregion

        #endregion           

    }
}
