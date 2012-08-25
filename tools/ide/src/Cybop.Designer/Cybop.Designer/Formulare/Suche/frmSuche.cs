using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace Cybop.Designer.Formulare
{
    public partial class frmSuche : Form
    {

        #region "Members"
        private Data.Project _Project;
        private int _Type;
        private string _Suchbegriff;
        private frmMain _Parentfrm;
        private Dictionary<string, MatchCollection> _SearchMatchCollection;

        private List<string> _CurrentTabNames;
        private int _CurrentTabPageIndex;
        private int _CurrentSearchMatchIndex;
        private bool _NewSearchMatch;
        private int _MaxSearchMatchIndex;

        #endregion

        #region "Konstruktor"

        public frmSuche(string Suchbegriff, Data.Project Project, int Type, frmMain Parentfrm)
        {
            InitializeComponent();
            _Project = Project;
            _Type = Type;
            _Suchbegriff = Suchbegriff;
            _Parentfrm = Parentfrm;
            _SearchMatchCollection = null;
            _CurrentSearchMatchIndex = 0;
            _CurrentTabPageIndex = 0;
            _CurrentTabNames = new List<string>();
            _NewSearchMatch = true;
        }

        #endregion

        #region "Events"
        
        private void frmSuche_Load(object sender, EventArgs e)
        {
            InitializeControls();
        }

        private void txtSuchbegriff_TextChanged(object sender, EventArgs e)
        {
            _Suchbegriff = txtSuchbegriff.Text;
            this.txtSuchenErstzen.TextChanged -= txtSuchenErstzen_TextChanged;
            this.txtSuchenErstzen.Text = _Suchbegriff;
            this.txtSuchenErstzen.TextChanged += txtSuchenErstzen_TextChanged;
            _NewSearchMatch = true;

        }

        private void txtSuchenErstzen_TextChanged(object sender, EventArgs e)
        {
            _Suchbegriff = txtSuchenErstzen.Text;

            this.txtSuchbegriff.TextChanged -= txtSuchenErstzen_TextChanged;
            this.txtSuchbegriff.Text = _Suchbegriff;
            this.txtSuchbegriff.TextChanged += txtSuchenErstzen_TextChanged;
            _NewSearchMatch = true;
        }

        private void cboSuchenIn_SelectedIndexChanged(object sender, EventArgs e)
        {
            _NewSearchMatch = true;
        }

        private void btnSuchen_Click(object sender, EventArgs e)
        {
            _Type = 0;

            if (_NewSearchMatch)
            {
                _CurrentSearchMatchIndex = 0;
                _CurrentTabPageIndex = 0;
                _CurrentTabNames = new List<string>();
               Suche();  
            }

            SucheOnlyOpenFile();
           
        }

        private void btnErsetzen_Click(object sender, EventArgs e)
        {
           
            if (cboSuchenIn.SelectedIndex == 3)
            {

            }
            else
            {
                Replace();
            }
        }

        #endregion

        #region "Funktionen"

        private void InitializeControls()
        {

            this.tcSuche.SelectTab(_Type);

            this.txtSuchenErstzen.TextChanged -= txtSuchenErstzen_TextChanged;
            this.txtSuchenErstzen.Text = _Suchbegriff;
            this.txtSuchenErstzen.TextChanged += txtSuchenErstzen_TextChanged;

            this.txtSuchbegriff.TextChanged -= txtSuchenErstzen_TextChanged;
            this.txtSuchbegriff.Text = _Suchbegriff;
            this.txtSuchbegriff.TextChanged += txtSuchenErstzen_TextChanged;

            this.cboSuchenErsetzenIn.SelectedIndex = 0;
            this.cboSuchenIn.SelectedIndex = 0;

        }

        private void Suche()
        {

            switch (cboSuchenIn.SelectedIndex)
            {
                case 0:
                    SucheOpenFiles(true);
                    break;

                case 1:
                    SucheOpenFiles(false);
                    break;

                case 2:
                    SucheAllFile();
                    break;
            }

        }

        private void SucheOpenFiles(bool Selected)
        {

            string InputString = string.Empty;

            if (Selected)
            {
                if (_Parentfrm.EditorTab.SelectedTab != null)
                {
                    IntellisenseEditor.EditorTextbox editor = _Parentfrm.EditorTab.SelectedTab.Controls["edit" + _Parentfrm.EditorTab.SelectedTab.Name] as IntellisenseEditor.EditorTextbox;
                    if (editor != null)
                    {
                        string Suchbegriff = CheckSuchbegriff(_Suchbegriff);
                        InputString = editor.Text;
                        Regex searchRegex = new Regex(Suchbegriff);
                        _SearchMatchCollection = new Dictionary<string, MatchCollection>();
                        _SearchMatchCollection.Add(_Parentfrm.EditorTab.SelectedTab.Name, searchRegex.Matches(InputString));
                        _CurrentTabNames = new List<string>();
                        _CurrentTabNames.Add(_Parentfrm.EditorTab.SelectedTab.Name);
                        _NewSearchMatch = false;
                    }
                }
            }
            else
            {

                _SearchMatchCollection = new Dictionary<string, MatchCollection>();
                _CurrentTabNames = new List<string>();

                foreach (TabPage item in _Parentfrm.EditorTab.TabPages)
                {
                    IntellisenseEditor.EditorTextbox editor = item.Controls["edit" +item.Name] as IntellisenseEditor.EditorTextbox;
                    if (editor != null)
                    {
                        string Suchbegriff = CheckSuchbegriff(_Suchbegriff);
                        InputString = editor.Text;
                        Regex searchRegex = new Regex(Suchbegriff);
                        MatchCollection results = searchRegex.Matches(InputString);
                        if (results.Count > 0)
                        {
                            _SearchMatchCollection.Add(item.Name, results);
                            _CurrentTabNames.Add(item.Name);
                            _NewSearchMatch = false;
                        }                        
                    }
                }

            }
            

        }

        private string CheckSuchbegriff(string Suchbegriff)
        {
            string result = Suchbegriff;

            if (Suchbegriff.Contains("."))
            {
                result = Suchbegriff.Replace(".", "\\.");
            }

            if (Suchbegriff.Contains("*"))
            {
                result = Suchbegriff.Replace("*", "\\*");
            }

            return result;

        }

        private void SucheOnlyOpenFile()
        {
            if (_SearchMatchCollection != null)
            {

                string tabName = string.Empty;

                if (_CurrentTabNames.Count > 0)
                {
                    tabName = _CurrentTabNames[_CurrentTabPageIndex];
                }

                if (tabName != string.Empty)
                {
                    MatchCollection Matches = _SearchMatchCollection[tabName];

                    if (Matches != null && Matches.Count > 0)
                    {
                        Match itemMatch = Matches[_CurrentSearchMatchIndex];

                        if (itemMatch.Success)
                        {
                            TabPage tabPage = _Parentfrm.EditorTab.TabPages[tabName];

                            if (tabPage != null)
                            {
                                IntellisenseEditor.EditorTextbox editor = tabPage.Controls["edit" + tabName] as IntellisenseEditor.EditorTextbox;

                                if (editor != null)
                                {
                                    editor.SelectText(itemMatch.Index, itemMatch.Length);
                                    if (_Parentfrm.EditorTab.SelectedTab != tabPage)
                                    {
                                        _Parentfrm.EditorTab.SelectTab(tabPage.Name);
                                    }
                                }

                            }

                        }

                        if (_CurrentSearchMatchIndex + 1 <= Matches.Count - 1)
                        {
                            _CurrentSearchMatchIndex += 1;
                        }
                        else
                        {
                            _CurrentSearchMatchIndex = 0;
                            if (_CurrentTabPageIndex + 1 <= _CurrentTabNames.Count - 1)
                            {
                                _CurrentTabPageIndex += 1;
                            }
                            else
                            {
                                MessageBox.Show("Die Suche hat Ihren Anfangspunkt wieder erreicht.", this.Text, MessageBoxButtons.OK, MessageBoxIcon.Information);
                                _NewSearchMatch = true;
                            }
                        }

                    }
                    else
                    {
                        MessageBox.Show("Es konnte kein Suchergebniss ermittelt werden.", this.Text, MessageBoxButtons.OK, MessageBoxIcon.Information);
                        _NewSearchMatch = true;
                    }
                }
            }
        }

        private void SucheAllFile()
        {
            OpenFilesWithMatches(_Parentfrm.Navigation.NavigationTree.Nodes);
            SucheOpenFiles(false);   
        }

        private void OpenFilesWithMatches(TreeNodeCollection TreeNodes)
        {
            foreach (TreeNode item in TreeNodes)
            {

                Data.ElementCollection elements = item.Tag as Data.ElementCollection;
                if (elements != null)
                {
                    foreach (Data.Element itemElement in elements)
                    {
                        if (!itemElement.IsOpen)
                        {
                            if (itemElement.Content.GetType() == typeof(string))
                            {
                                string content = System.Convert.ToString(itemElement.Content);
                                if (!string.IsNullOrEmpty(content))
                                {
                                    string Suchbegriff = CheckSuchbegriff(_Suchbegriff);
                                    Regex searchRegex = new Regex(Suchbegriff);
                                    MatchCollection matches = searchRegex.Matches(content);
                                    if (matches.Count > 0)
                                    {
                                        TreeNode node = null;
                                        foreach (TreeNode itemNode in item.Nodes)
                                        {
                                            if (itemNode.Name == itemElement.ID.ToString())
                                            {
                                                node = itemNode;
                                                break;
                                            }
                                        }

                                        if (node != null)
                                        {
                                            _Parentfrm.OpenFile(itemElement, node);
                                        }

                                    }
                                }
                            }
                        }
                    }
                }

                if (item.Nodes.Count > 0)
                {
                    OpenFilesWithMatches(item.Nodes);
                }

            }
        }

        private void Replace()
        {
            switch (cboSuchenErsetzenIn.SelectedIndex)
            {
                case 0:
                    ReplaceOpenFiles(true);
                    break;

                case 1:
                    ReplaceOpenFiles(false);
                    break;
            }
        }

        private void ReplaceOpenFiles(bool Selected)
        {

            if (Selected)
            {
                ReplceOnTabPage(_Parentfrm.EditorTab.SelectedTab);
            }
            else
            {

                if (_CurrentTabPageIndex <= _Parentfrm.EditorTab.TabPages.Count - 1)
                {

                    TabPage tb = _Parentfrm.EditorTab.TabPages[_CurrentTabPageIndex];
                    if (_CurrentSearchMatchIndex == 0)
                    {
                        _MaxSearchMatchIndex = GetMaxSearchCount(tb);
                    }

                    if (_CurrentSearchMatchIndex <= _MaxSearchMatchIndex - 1)
                    {
                        ReplceOnTabPage(tb);
                        _CurrentSearchMatchIndex += 1;
                    }
                    else
                    {
                        _CurrentSearchMatchIndex = 0;
                        _CurrentTabPageIndex += 1;
                    }

                }
                else
                {
                    MessageBox.Show("Es wurden keine Ergebnisse ermittelt.", this.Text, MessageBoxButtons.OK, MessageBoxIcon.Information);
                    _CurrentTabPageIndex = 0;
                }

            }

        }

        private int GetMaxSearchCount(TabPage tb)
        {
            if (tb != null)
            {
                IntellisenseEditor.EditorTextbox editor = tb.Controls["edit" + tb.Name] as IntellisenseEditor.EditorTextbox;
                    if (editor != null)
                    {
                        string Suchbegriff = CheckSuchbegriff(_Suchbegriff);
                        string InputString = editor.Text;
                        Regex searchRegex = new Regex(Suchbegriff);
                        MatchCollection result = searchRegex.Matches(InputString);
                        return result.Count;
                    }
            }

            return 0;

        }

        private void ReplceOnTabPage(TabPage tabPage)
        {
            if (tabPage != null)
            {
                IntellisenseEditor.EditorTextbox editor = tabPage.Controls["edit" + tabPage.Name] as IntellisenseEditor.EditorTextbox;
                if (editor != null)
                {
                    string Suchbegriff = CheckSuchbegriff(_Suchbegriff);
                    string InputString = editor.Text;
                    Regex searchRegex = new Regex(Suchbegriff);
                    Match match = searchRegex.Match(InputString);
                    editor.SelectText(match.Index, match.Length);
                    editor.SelectedText = txtErsetzen.Text;
                    if (_Parentfrm.EditorTab.SelectedTab != tabPage)
                    {
                        _Parentfrm.EditorTab.SelectTab(tabPage.Name);
                    }
                }
            }
        }

        #endregion          

    }
}
