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
    public partial class frmNavigation : Form
    {

        #region "Members"
        private frmMain _ParentForm;
        private Data.Project _Project;
        private ImageList _ImageList;
        private TreeNode _CopyNode;
        #endregion

        #region "Konstruktor"
        
        public frmNavigation(frmMain ParentForm, ref Data.Project Project)
        {
            InitializeComponent();
            _ParentForm = ParentForm;
            _Project = Project;
            _ImageList = new ImageList();
            _ImageList.Images.Add(Properties.Resources.project_open_32);
            _ImageList.Images.Add(Properties.Resources.folder_32);
            _ImageList.Images.Add(Properties.Resources.file_32);
            this.tvNavigation.ImageList = _ImageList;
        }

        #endregion

        #region "Properties"

        public TreeView NavigationTree { get { return this.tvNavigation; } }

        #endregion

        #region "Events"

        #region "Form"

        private void frmNavigation_Load(object sender, EventArgs e)
        {
            this.Text = "Cybol-Designer - " + _Project.Name;
            LoadNavigation();
            InitializeControls();
        }

        private void frmNavigation_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (_Project != null)
            {
                e.Cancel = true;
                this.Visible = false;
            }
        }

        #endregion

        #region "Navigation-Tree"

        private void tvNavigation_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == System.Windows.Forms.MouseButtons.Right)
            {

                bool MenuItemsEnabled = false;

                if (this.tvNavigation.SelectedNode != null)
                {
                    if (this.tvNavigation.SelectedNode.ImageIndex != 2)
                    {
                        MenuItemsEnabled = true;
                    }
                }

                ContextMenuStrip contextMenu = new ContextMenuStrip();
                ToolStripMenuItem contextMenuItem = contextMenu.Items.Add("Neu", null, null) as ToolStripMenuItem;
                contextMenuItem.Enabled = MenuItemsEnabled;
                contextMenuItem.DropDownItems.Add("Datei", Properties.Resources.file_32, new EventHandler(tvNavigationContextMenuNewFile_Click));
                contextMenuItem.DropDownItems.Add("Ordner", Properties.Resources.folder_32, new EventHandler(tvNavigationContextMenuNewFolder_Click));

                contextMenuItem = contextMenu.Items.Add("Hinzufügen", null, null) as ToolStripMenuItem;
                contextMenuItem.Enabled = MenuItemsEnabled;
                contextMenuItem.DropDownItems.Add("Datei", Properties.Resources.file_32, new EventHandler(tvNavigationContextMenuAddFile_Click));
                contextMenuItem.DropDownItems.Add("Ordner", Properties.Resources.folder_32, new EventHandler(tvNavigationContextMenuAddFolder_Click));

                contextMenu.Items.Add("-");

                contextMenuItem = contextMenu.Items.Add("Kopieren", null, new EventHandler(tvNavigationContextMenuCopyObject_Click)) as ToolStripMenuItem;
                if (tvNavigation.SelectedNode.Name == "Project")
                {
                    contextMenuItem.Enabled = false;
                }

                contextMenuItem = contextMenu.Items.Add("Einfügen", null, new EventHandler(tvNavigationContextMenuPasteObject_Click)) as ToolStripMenuItem;
                if (_CopyNode != null)
                {
                    contextMenuItem.Enabled = true;
                }
                else
                {
                    contextMenuItem.Enabled = false;
                }

                contextMenu.Items.Add("-");

                contextMenuItem = contextMenu.Items.Add("Löschen", Properties.Resources.delete_32, new EventHandler(tvNavigationContextMenuDeleteObject_Click)) as ToolStripMenuItem;
                if (tvNavigation.SelectedNode.Name == "Project")
                {
                    contextMenuItem.Enabled = false;
                }

                contextMenu.Items.Add("-");

                contextMenuItem = contextMenu.Items.Add("Umbenennen", null, new EventHandler(tvNavigationContextMenuChangeText_Click)) as ToolStripMenuItem;

                contextMenu.Show(Cursor.Position);

            }

        }

        private void tvNavigation_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            if (e.Button == System.Windows.Forms.MouseButtons.Left)
            {
                if (tvNavigation.SelectedNode != null)
                {

                    TreeNode parentNode = tvNavigation.SelectedNode.Parent;

                    if (parentNode != null)
                    {
                        Data.ElementCollection listElements = parentNode.Tag as Data.ElementCollection;

                        if (listElements != null)
                        {
                            Data.Element elementOpen = listElements.ToList().Find(el => el.ID.ToString() == tvNavigation.SelectedNode.Name);

                            if (elementOpen != null)
                            {
                                if (elementOpen.Type == Data.Element.File)
                                {
                                    _ParentForm.OpenFile(elementOpen, tvNavigation.SelectedNode);
                                }
                            }
                                                      
                        }
                    }                  

                }
            }
        }

        private void tvNavigation_AfterLabelEdit(object sender, NodeLabelEditEventArgs e)
        {

            if (e.Node.Name == "Project")
            {
                _Project.Name = e.Label;
            }
            else
            {
                Data.ElementCollection Elements = e.Node.Parent.Tag as Data.ElementCollection;
                Data.Element Element = Elements.ToList().Find(el => el.ID.ToString() == e.Node.Name);
                if (Element != null)
                {
                    if (!string.IsNullOrEmpty(e.Label))
                    {
                        Element.Name = e.Label;
                    }

                }
            }

        }

        #region "ContextMenu"

        private void tvNavigationContextMenuNewFile_Click(object sender, EventArgs e)
        {
            CreateNewObject(Data.Element.File);
        }

        private void tvNavigationContextMenuNewFolder_Click(object sender, EventArgs e)
        {
            CreateNewObject(Data.Element.Folder);
        }

        private void tvNavigationContextMenuAddFile_Click(object sender, EventArgs e)
        {
            if (tvNavigation.SelectedNode != null)
            {
                AddObject(Data.Element.File);
            }
        }

        private void tvNavigationContextMenuAddFolder_Click(object sender, EventArgs e)
        {
            if (tvNavigation.SelectedNode != null)
            {
                AddObject(Data.Element.Folder);
            }
        }

        private void tvNavigationContextMenuChangeText_Click(object sender, EventArgs e)
        {
            if (this.tvNavigation.SelectedNode != null)
            {
                this.tvNavigation.SelectedNode.BeginEdit();
            }
        }

        private void tvNavigationContextMenuCopyObject_Click(object sender, EventArgs e)
        {
            if (tvNavigation.SelectedNode != null)
            {
                _CopyNode = tvNavigation.SelectedNode;
            }
        }

        private void tvNavigationContextMenuPasteObject_Click(object sender, EventArgs e)
        {
            if (tvNavigation.SelectedNode != null)
            {
                if (_CopyNode != null)
                {
                    PasteObject(_CopyNode);
                    _CopyNode = null;
                }
            }
        }

        private void tvNavigationContextMenuDeleteObject_Click(object sender, EventArgs e)
        {
            if (tvNavigation.SelectedNode != null)
            {
                DeleteObject(tvNavigation.SelectedNode);
            }
        }

        #endregion

        #region "DragDrop Funktion"

        private void tvNavigation_ItemDrag(object sender, ItemDragEventArgs e)
        {
            if (e.Item != null)
            {

                TreeNode node = e.Item as TreeNode;
                if (node.Name != "Project")
                {

                    Data.Element element = null;

                    if (node.Parent != null)
                    {
                        Data.ElementCollection elements = node.Parent.Tag as Data.ElementCollection;
                        if (elements != null)
                        {
                            element = elements.ToList().Find(el => el.ID.ToString() == node.Name);
                        }
                    }

                    if (element != null)
                    {
                        if (!element.IsOpen)
                        {
                            DoDragDrop(node, DragDropEffects.Move | DragDropEffects.None);
                        }
                    }
                                       
                }
            }
        }

        private void tvNavigation_DragEnter(object sender, DragEventArgs e)
        {

            // Nur TreeNodes werden zugelassen:
            if (e.Data.GetDataPresent(typeof(TreeNode)))
            {
                Point pt = ((TreeView)sender).PointToClient(new Point(e.X, e.Y));
                TreeNode DestinationNode = ((TreeView)sender).GetNodeAt(pt);
                if (DestinationNode != null)
                {
                    e.Effect = DragDropEffects.Move;
                }
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }

        }

        private void tvNavigation_DragOver(object sender, DragEventArgs e)
        {
            Point pt = ((TreeView)sender).PointToClient(new Point(e.X, e.Y));
            TreeNode DestinationNode = ((TreeView)sender).GetNodeAt(pt);

            if (DestinationNode != null)
            {

                tvNavigation.SelectedNode = DestinationNode;

                if (DestinationNode.ImageIndex == 2)
                {
                    e.Effect = DragDropEffects.None;
                }
                else
                {
                    e.Effect = DragDropEffects.Move;
                }
            }
        }

        private void tvNavigation_DragDrop(object sender, DragEventArgs e)
        {
            TreeNode OldNode;

            if (e.Data.GetDataPresent("System.Windows.Forms.TreeNode", false))
            {
                Point pt = ((TreeView)sender).PointToClient(new Point(e.X, e.Y));
                TreeNode DestinationNode = ((TreeView)sender).GetNodeAt(pt);
                if (DestinationNode != null)
                {

                    if (DestinationNode.ImageIndex == 2)
                    {
                        e.Effect = DragDropEffects.None;
                    }
                    else
                    {
                        OldNode = (TreeNode)e.Data.GetData("System.Windows.Forms.TreeNode");
                        if (DestinationNode.TreeView == OldNode.TreeView)
                        {

                            TreeNode oldParentNode = OldNode.Parent;
                            Data.ElementCollection Elements = oldParentNode.Tag as Data.ElementCollection;
                            Data.ElementCollection DestinationElement = DestinationNode.Tag as Data.ElementCollection;

                            Data.Element oldElement = Elements.ToList().Find(el => el.ID.ToString() == OldNode.Name);
                            Data.Element newElement = new Data.Element(oldElement.Type, DestinationElement.Count + 1);

                            newElement.Name = oldElement.Name;
                            newElement.Content = oldElement.Content;
                            newElement.Elements = oldElement.Elements;

                            newElement.ChangeLocation(oldElement);

                            Elements.Remove(oldElement);
                            DestinationElement.Add(newElement);

                            int ImageIndex = 1;

                            if (newElement.Type == Data.Element.File)
                            {
                                ImageIndex = 2;
                            }

                            TreeNode NewNode = DestinationNode.Nodes.Add(newElement.ID.ToString(), newElement.Name, ImageIndex, ImageIndex);
                            NewNode.Tag = newElement.Elements;

                            CopyNodes(OldNode, ref NewNode);

                            DestinationNode.Expand();

                            //Remove Original Node
                            OldNode.Remove();
                            tvNavigation.Refresh();
                        }
                    }

                }

            }
        }

        #endregion

        #endregion

        #region "Transparency"

        private void frmNavigation_MouseEnter(object sender, EventArgs e)
        {
            SetTransparency(100);
        }

        private void frmNavigation_MouseLeave(object sender, EventArgs e)
        {
            SetTransparency(Properties.Settings.Default.Transparency);
        }

        private void tvNavigation_MouseEnter(object sender, EventArgs e)
        {
            frmNavigation_MouseEnter(sender, e);
        }

        private void tvNavigation_MouseLeave(object sender, EventArgs e)
        {
            frmNavigation_MouseLeave(sender, e);
        }

        private void tvNavigation_MouseHover(object sender, EventArgs e)
        {
            SetTransparency(100);
        }

        #endregion

        #endregion

        #region "Funktionen"

        #region "Navigation"

        /// <summary>
        /// Lädt den Navigations-Baum.
        /// </summary>
        private void LoadNavigation()
        {

            try
            {
                this.tvNavigation.Nodes.Clear();

                TreeNode treeNode = this.tvNavigation.Nodes.Add("Project", _Project.Name, 0);
                treeNode.Tag = _Project.Elements;

                LoadElements(_Project.Elements, treeNode);
               
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }

        }

        /// <summary>
        /// Lädt ein Element
        /// </summary>
        /// <param name="Elements"></param>
        /// <param name="Node"></param>
        private void LoadElements(Data.ElementCollection Elements, TreeNode Node)
        {
            foreach (Data.Element item in Elements)
            {
                int ImageIndex = 1;

                if (item.Type == Data.Element.File)
	            {
		             ImageIndex = 2;
	            }

                TreeNode treeNode = Node.Nodes.Add(item.ID.ToString(), item.Name, ImageIndex, ImageIndex);
                treeNode.Tag = item.Elements;

                if (item.Elements.Count > 0)
                {
                    LoadElements(item.Elements, treeNode);
                }
            }
        }

        /// <summary>
        /// Erzeugt eine neue Datei oder Ordner.
        /// </summary>
        /// <param name="Type"></param>
        private void CreateNewObject(string Type)
        {
            try
            {

                Data.ElementCollection ElementCollection = null;
                Data.Element element = null;

                if (this.tvNavigation.SelectedNode != null)
                {
                    if (this.tvNavigation.SelectedNode.Tag != null)
                    {
                        ElementCollection = this.tvNavigation.SelectedNode.Tag as Data.ElementCollection;
                    }
                }

                if (ElementCollection != null)
                {
                    switch (Type)
                    {
                        case Data.Element.Folder:
                            element = new Data.Element(Data.Element.Folder, ElementCollection.Count + 1);
                            element.Name = "Neuer Ordner";
                            ElementCollection.Add(element);
                            TreeNode treeNodeFolder = this.tvNavigation.SelectedNode.Nodes.Add(element.ID.ToString(), element.Name, 1, 1);
                            treeNodeFolder.Tag = element.Elements;
                            tvNavigation.SelectedNode = treeNodeFolder;
                            treeNodeFolder.BeginEdit();
                            break;
                        case Data.Element.File:
                            element = new Data.Element(Data.Element.File, ElementCollection.Count + 1);
                            element.Name = "Neue Datei.cybol";
                            ElementCollection.Add(element);
                            TreeNode treeNodeFile = this.tvNavigation.SelectedNode.Nodes.Add(element.ID.ToString(), element.Name, 2, 2);
                            treeNodeFile.Tag = element.Elements;
                            tvNavigation.SelectedNode = treeNodeFile;
                            treeNodeFile.BeginEdit();
                            break;
                        default:
                            break;
                    }
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        /// <summary>
        /// Fügt ein vorhandenes Objekt zum Projekt hinzu.
        /// </summary>
        /// <param name="Type"></param>
        private void AddObject(string Type)
        {

            try
            {

                switch (Type)
                {

                    case Data.Element.File:
                        AddFile();
                        break;

                    case Data.Element.Folder:
                        AddFolder();
                        break;

                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }

        }

        /// <summary>
        /// Fügt einen vorhandenen Ordner rekursiv dem Projekt hinzu.
        /// </summary>
        private void AddFolder()
        {

            FolderBrowserDialog openFolder = new FolderBrowserDialog();

            if (openFolder.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                AddFolder(openFolder.SelectedPath, tvNavigation.SelectedNode);
            }

            tvNavigation.SelectedNode.Expand();

        }

        /// <summary>
        /// Fügt einen vorhandenen Ordner rekursiv dem Projekt hinzu.
        /// </summary>
        private void AddFolder(string Path, TreeNode CurrentNode)
        {
            System.IO.DirectoryInfo Directory = new System.IO.DirectoryInfo(Path);

            if (Directory.Exists)
            {
                Data.ElementCollection Elements = tvNavigation.SelectedNode.Tag as Data.ElementCollection;
                Data.Element newElemente = new Data.Element(Data.Element.Folder, Elements.Count + 1);
                newElemente.Name = Directory.Name;

                TreeNode newNode = CurrentNode.Nodes.Add(newElemente.ID.ToString(), newElemente.Name, 1, 1);
                newNode.Tag = newElemente.Elements;

                foreach (System.IO.FileInfo file in Directory.GetFiles())
                {
                    if (file.Exists)
                    {
                        AddFile(file.FullName, newNode);
                    }
                }

                foreach (System.IO.DirectoryInfo ChildeDirectory in Directory.GetDirectories())
                {
                    if (ChildeDirectory.Exists)
                    {
                        AddFolder(ChildeDirectory.FullName, newNode);
                    }
                }

            }
        }

        /// <summary>
        /// Fügt eine vorhandenen Datei dem Projekt hinzu.
        /// </summary>
        private void AddFile(string FilePath, TreeNode CurrentNode)
        {
            System.IO.FileInfo File = new System.IO.FileInfo(FilePath);

            if (tvNavigation.SelectedNode != null)
            {
                Data.ElementCollection Elementes = tvNavigation.SelectedNode.Tag as Data.ElementCollection;
                Data.Element newElement = new Data.Element(Data.Element.File, Elementes.Count + 1);
                newElement.Name = File.Name;

                System.IO.StreamReader myFile = new System.IO.StreamReader(File.FullName, System.Text.Encoding.Default);
                newElement.Content = myFile.ReadToEnd();
                myFile.Close();

                Elementes.Add(newElement);
                TreeNode newNode = CurrentNode.Nodes.Add(newElement.ID.ToString(), newElement.Name, 2, 2);
                newNode.Tag = newElement.Elements;

            }
        }

        /// <summary>
        /// Fügt eine vorhandenen Datei dem Projekt hinzu.
        /// </summary>
        private void AddFile()
        {
            OpenFileDialog openFile = new OpenFileDialog();
            openFile.CheckFileExists = true;
            openFile.Filter = "All files (*.*)|*.*";
            openFile.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
            openFile.Multiselect = false;

            if (openFile.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                AddFile(openFile.FileName, tvNavigation.SelectedNode);
            }

            tvNavigation.SelectedNode.Expand();
        }

        /// <summary>
        /// Kopiert die Angehangenen Knoten aus dem alten Objekt ins neue Objekt.
        /// </summary>
        /// <param name="OldNode"></param>
        /// <param name="NewNode"></param>
        private void CopyNodes(TreeNode OldNode, ref TreeNode NewNode)
        {
            foreach (TreeNode node in OldNode.Nodes)
            {
                NewNode.Nodes.Add(node.Clone() as TreeNode);
            }
        }

        /// <summary>
        /// Fügt das Objekt an einer neuen stelle ein.
        /// </summary>
        /// <param name="OldNode"></param>
        private void PasteObject(TreeNode OldNode)
        {
            if (OldNode != null)
            {
                TreeNode ParentNode = OldNode.Parent;
                Data.ElementCollection ParentElements = ParentNode.Tag as Data.ElementCollection;
                Data.Element Elemenent = ParentElements.ToList().Find(el => el.ID.ToString() == OldNode.Name);

                if (Elemenent != null)
                {
                    Data.ElementCollection NewParentElements = tvNavigation.SelectedNode.Tag as Data.ElementCollection;
                    Data.Element NewElement = new Data.Element(Elemenent.Type, NewParentElements.Count + 1);
                    NewElement.Elements = Elemenent.Elements;
                    NewElement.Content = Elemenent.Content;
                    NewElement.Name = Elemenent.Name;

                    int ImageIndex = 1;

                    if (NewElement.Type == Data.Element.File)
                    {
                        ImageIndex = 2;
                    }

                    NewParentElements.Add(NewElement);

                    TreeNode NewNode = tvNavigation.SelectedNode.Nodes.Add(NewElement.ID.ToString(), NewElement.Name, ImageIndex, ImageIndex);
                    NewNode.Tag = NewElement.Elements;

                    CopyNodes(OldNode, ref NewNode);

                    tvNavigation.SelectedNode.Expand();
                }
            }
        }

        /// <summary>
        /// Löscht das Objekt 
        /// </summary>
        /// <param name="Node"></param>
        private void DeleteObject(TreeNode Node)
        {
            if (Node != null)
            {
                TreeNode ParentNode = Node.Parent;
                Data.ElementCollection ParentElemenets = ParentNode.Tag as Data.ElementCollection;
                Data.Element Element = ParentElemenets.ToList().Find(el => el.ID.ToString() == Node.Name);

                if (Element != null)
                {

                    if (!Element.IsOpen)
                    {
                        Element.Delete();
                        ParentElemenets.Remove(Element);
                        Node.Remove();
                    }
                                        
                }
            }
        }

        #endregion

        #region "Transparency"

        /// <summary>
        /// Initialisiert die Steuerelemente auf dem Formular.
        /// </summary>
        private void InitializeControls()
        {
            this.Focus();
            SetTransparency(Properties.Settings.Default.Transparency);
        }

        /// <summary>
        /// Setzt die Transparenz.
        /// </summary>
        /// <param name="Value"></param>
        private void SetTransparency(int Value)
        {
            this.AllowTransparency = true;
            this.Opacity = (double)Value / (double)100;
        }

        #endregion      

        

        #endregion

    }
}
