namespace Visual_Cybop
{
    partial class frm_Main
    {
        /// <summary>
        /// Erforderliche Designervariable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Verwendete Ressourcen bereinigen.
        /// </summary>
        /// <param name="disposing">True, wenn verwaltete Ressourcen gelöscht werden sollen; andernfalls False.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Vom Windows Form-Designer generierter Code

        /// <summary>
        /// Erforderliche Methode für die Designerunterstützung.
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frm_Main));
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("Model");
            this.menu = new System.Windows.Forms.MenuStrip();
            this.dateiToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.neuToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.öffnenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.projektSpeichernToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.speichernUnterToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.beendenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.bearbeitenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.partHinzufügenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.unterpartHinzufügenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.partLöschenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.projektToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.projektErzeugenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.extrasToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.optionenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.hilfeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.hilfeToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.überToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.statusbar = new System.Windows.Forms.StatusStrip();
            this.lbl_TagId = new System.Windows.Forms.ToolStripStatusLabel();
            this.lbl_NodeIndex = new System.Windows.Forms.ToolStripStatusLabel();
            this.lbl_NodePath = new System.Windows.Forms.ToolStripStatusLabel();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.toolbar_tree = new System.Windows.Forms.ToolStrip();
            this.btn_AddNode = new System.Windows.Forms.ToolStripButton();
            this.btn_AddSub = new System.Windows.Forms.ToolStripButton();
            this.btn_DelNode = new System.Windows.Forms.ToolStripButton();
            this.tree_Model = new System.Windows.Forms.TreeView();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.txt_Name = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.grid_Nodes = new System.Windows.Forms.DataGridView();
            this.Node_Id = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.parentIdDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.nameDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.channelDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.formatDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.modelDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Node_NodePath = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.source_Node = new System.Windows.Forms.BindingSource(this.components);
            this.dataset_Main = new Visual_Cybop.dataset_Main();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.grid_Properties = new System.Windows.Forms.DataGridView();
            this.Properties_Id = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Properties_Node_Id = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Properties_Name = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Properties_Channel = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Properties_Format = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Properties_Model = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.source_Properties = new System.Windows.Forms.BindingSource(this.components);
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.partHinzufügenToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.unterpartHinzufügenToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.parteEntfernenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.menu.SuspendLayout();
            this.statusbar.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.toolbar_tree.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).BeginInit();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.grid_Nodes)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.source_Node)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataset_Main)).BeginInit();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.grid_Properties)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.source_Properties)).BeginInit();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menu
            // 
            this.menu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.dateiToolStripMenuItem,
            this.bearbeitenToolStripMenuItem,
            this.projektToolStripMenuItem,
            this.extrasToolStripMenuItem,
            this.hilfeToolStripMenuItem});
            this.menu.Location = new System.Drawing.Point(0, 0);
            this.menu.Name = "menu";
            this.menu.Size = new System.Drawing.Size(846, 24);
            this.menu.TabIndex = 3;
            // 
            // dateiToolStripMenuItem
            // 
            this.dateiToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.neuToolStripMenuItem,
            this.öffnenToolStripMenuItem,
            this.toolStripSeparator2,
            this.projektSpeichernToolStripMenuItem,
            this.speichernUnterToolStripMenuItem,
            this.toolStripSeparator1,
            this.beendenToolStripMenuItem});
            this.dateiToolStripMenuItem.Name = "dateiToolStripMenuItem";
            this.dateiToolStripMenuItem.Size = new System.Drawing.Size(46, 20);
            this.dateiToolStripMenuItem.Text = "Datei";
            // 
            // neuToolStripMenuItem
            // 
            this.neuToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("neuToolStripMenuItem.Image")));
            this.neuToolStripMenuItem.Name = "neuToolStripMenuItem";
            this.neuToolStripMenuItem.Size = new System.Drawing.Size(205, 22);
            this.neuToolStripMenuItem.Text = "Neu...";
            this.neuToolStripMenuItem.Click += new System.EventHandler(this.UnderConstructionItem_Click);
            // 
            // öffnenToolStripMenuItem
            // 
            this.öffnenToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("öffnenToolStripMenuItem.Image")));
            this.öffnenToolStripMenuItem.Name = "öffnenToolStripMenuItem";
            this.öffnenToolStripMenuItem.Size = new System.Drawing.Size(205, 22);
            this.öffnenToolStripMenuItem.Text = "Öffnen";
            this.öffnenToolStripMenuItem.Click += new System.EventHandler(this.UnderConstructionItem_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(202, 6);
            // 
            // projektSpeichernToolStripMenuItem
            // 
            this.projektSpeichernToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("projektSpeichernToolStripMenuItem.Image")));
            this.projektSpeichernToolStripMenuItem.Name = "projektSpeichernToolStripMenuItem";
            this.projektSpeichernToolStripMenuItem.Size = new System.Drawing.Size(205, 22);
            this.projektSpeichernToolStripMenuItem.Text = "Projekt speichern";
            this.projektSpeichernToolStripMenuItem.Click += new System.EventHandler(this.UnderConstructionItem_Click);
            // 
            // speichernUnterToolStripMenuItem
            // 
            this.speichernUnterToolStripMenuItem.Name = "speichernUnterToolStripMenuItem";
            this.speichernUnterToolStripMenuItem.Size = new System.Drawing.Size(205, 22);
            this.speichernUnterToolStripMenuItem.Text = "Projekt speichern unter...";
            this.speichernUnterToolStripMenuItem.Click += new System.EventHandler(this.UnderConstructionItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(202, 6);
            // 
            // beendenToolStripMenuItem
            // 
            this.beendenToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("beendenToolStripMenuItem.Image")));
            this.beendenToolStripMenuItem.Name = "beendenToolStripMenuItem";
            this.beendenToolStripMenuItem.Size = new System.Drawing.Size(205, 22);
            this.beendenToolStripMenuItem.Text = "Beenden";
            this.beendenToolStripMenuItem.Click += new System.EventHandler(this.beendenToolStripMenuItem_Click);
            // 
            // bearbeitenToolStripMenuItem
            // 
            this.bearbeitenToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.partHinzufügenToolStripMenuItem,
            this.unterpartHinzufügenToolStripMenuItem,
            this.partLöschenToolStripMenuItem});
            this.bearbeitenToolStripMenuItem.Name = "bearbeitenToolStripMenuItem";
            this.bearbeitenToolStripMenuItem.Size = new System.Drawing.Size(75, 20);
            this.bearbeitenToolStripMenuItem.Text = "Bearbeiten";
            // 
            // partHinzufügenToolStripMenuItem
            // 
            this.partHinzufügenToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("partHinzufügenToolStripMenuItem.Image")));
            this.partHinzufügenToolStripMenuItem.Name = "partHinzufügenToolStripMenuItem";
            this.partHinzufügenToolStripMenuItem.Size = new System.Drawing.Size(187, 22);
            this.partHinzufügenToolStripMenuItem.Text = "Part hinzufügen";
            this.partHinzufügenToolStripMenuItem.Click += new System.EventHandler(this.toolStripButton1_Click);
            // 
            // unterpartHinzufügenToolStripMenuItem
            // 
            this.unterpartHinzufügenToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("unterpartHinzufügenToolStripMenuItem.Image")));
            this.unterpartHinzufügenToolStripMenuItem.Name = "unterpartHinzufügenToolStripMenuItem";
            this.unterpartHinzufügenToolStripMenuItem.Size = new System.Drawing.Size(187, 22);
            this.unterpartHinzufügenToolStripMenuItem.Text = "Unterpart hinzufügen";
            this.unterpartHinzufügenToolStripMenuItem.Click += new System.EventHandler(this.btn_AddSub_Click);
            // 
            // partLöschenToolStripMenuItem
            // 
            this.partLöschenToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("partLöschenToolStripMenuItem.Image")));
            this.partLöschenToolStripMenuItem.Name = "partLöschenToolStripMenuItem";
            this.partLöschenToolStripMenuItem.Size = new System.Drawing.Size(187, 22);
            this.partLöschenToolStripMenuItem.Text = "Part löschen";
            this.partLöschenToolStripMenuItem.Click += new System.EventHandler(this.btn_DelNode_Click);
            // 
            // projektToolStripMenuItem
            // 
            this.projektToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.projektErzeugenToolStripMenuItem});
            this.projektToolStripMenuItem.Name = "projektToolStripMenuItem";
            this.projektToolStripMenuItem.Size = new System.Drawing.Size(56, 20);
            this.projektToolStripMenuItem.Text = "Projekt";
            // 
            // projektErzeugenToolStripMenuItem
            // 
            this.projektErzeugenToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("projektErzeugenToolStripMenuItem.Image")));
            this.projektErzeugenToolStripMenuItem.Name = "projektErzeugenToolStripMenuItem";
            this.projektErzeugenToolStripMenuItem.Size = new System.Drawing.Size(162, 22);
            this.projektErzeugenToolStripMenuItem.Text = "Projekt erzeugen";
            this.projektErzeugenToolStripMenuItem.Click += new System.EventHandler(this.UnderConstructionItem_Click);
            // 
            // extrasToolStripMenuItem
            // 
            this.extrasToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.optionenToolStripMenuItem});
            this.extrasToolStripMenuItem.Name = "extrasToolStripMenuItem";
            this.extrasToolStripMenuItem.Size = new System.Drawing.Size(49, 20);
            this.extrasToolStripMenuItem.Text = "Extras";
            // 
            // optionenToolStripMenuItem
            // 
            this.optionenToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("optionenToolStripMenuItem.Image")));
            this.optionenToolStripMenuItem.Name = "optionenToolStripMenuItem";
            this.optionenToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.optionenToolStripMenuItem.Text = "Optionen";
            this.optionenToolStripMenuItem.Click += new System.EventHandler(this.UnderConstructionItem_Click);
            // 
            // hilfeToolStripMenuItem
            // 
            this.hilfeToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.hilfeToolStripMenuItem1,
            this.toolStripSeparator3,
            this.überToolStripMenuItem});
            this.hilfeToolStripMenuItem.Name = "hilfeToolStripMenuItem";
            this.hilfeToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.hilfeToolStripMenuItem.Text = "Hilfe";
            // 
            // hilfeToolStripMenuItem1
            // 
            this.hilfeToolStripMenuItem1.Image = ((System.Drawing.Image)(resources.GetObject("hilfeToolStripMenuItem1.Image")));
            this.hilfeToolStripMenuItem1.Name = "hilfeToolStripMenuItem1";
            this.hilfeToolStripMenuItem1.Size = new System.Drawing.Size(152, 22);
            this.hilfeToolStripMenuItem1.Text = "Hilfe";
            this.hilfeToolStripMenuItem1.Click += new System.EventHandler(this.UnderConstructionItem_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(149, 6);
            // 
            // überToolStripMenuItem
            // 
            this.überToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("überToolStripMenuItem.Image")));
            this.überToolStripMenuItem.Name = "überToolStripMenuItem";
            this.überToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.überToolStripMenuItem.Text = "Info";
            this.überToolStripMenuItem.Click += new System.EventHandler(this.UnderConstructionItem_Click);
            // 
            // statusbar
            // 
            this.statusbar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.lbl_TagId,
            this.lbl_NodeIndex,
            this.lbl_NodePath});
            this.statusbar.Location = new System.Drawing.Point(0, 498);
            this.statusbar.Name = "statusbar";
            this.statusbar.Size = new System.Drawing.Size(846, 22);
            this.statusbar.TabIndex = 4;
            this.statusbar.Text = "statusStrip1";
            // 
            // lbl_TagId
            // 
            this.lbl_TagId.Name = "lbl_TagId";
            this.lbl_TagId.Size = new System.Drawing.Size(18, 17);
            this.lbl_TagId.Text = "-1";
            // 
            // lbl_NodeIndex
            // 
            this.lbl_NodeIndex.Name = "lbl_NodeIndex";
            this.lbl_NodeIndex.Size = new System.Drawing.Size(18, 17);
            this.lbl_NodeIndex.Text = "-1";
            // 
            // lbl_NodePath
            // 
            this.lbl_NodePath.Name = "lbl_NodePath";
            this.lbl_NodePath.Size = new System.Drawing.Size(0, 17);
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 24);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.toolbar_tree);
            this.splitContainer1.Panel1.Controls.Add(this.tree_Model);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.splitContainer2);
            this.splitContainer1.Size = new System.Drawing.Size(846, 474);
            this.splitContainer1.SplitterDistance = 240;
            this.splitContainer1.TabIndex = 5;
            // 
            // toolbar_tree
            // 
            this.toolbar_tree.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.toolbar_tree.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.toolbar_tree.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.btn_AddNode,
            this.toolStripSeparator5,
            this.btn_AddSub,
            this.toolStripSeparator4,
            this.btn_DelNode});
            this.toolbar_tree.Location = new System.Drawing.Point(0, 449);
            this.toolbar_tree.Name = "toolbar_tree";
            this.toolbar_tree.Size = new System.Drawing.Size(240, 25);
            this.toolbar_tree.TabIndex = 1;
            this.toolbar_tree.Text = "toolStrip1";
            // 
            // btn_AddNode
            // 
            this.btn_AddNode.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btn_AddNode.Image = ((System.Drawing.Image)(resources.GetObject("btn_AddNode.Image")));
            this.btn_AddNode.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btn_AddNode.Name = "btn_AddNode";
            this.btn_AddNode.Size = new System.Drawing.Size(23, 22);
            this.btn_AddNode.Text = "+";
            this.btn_AddNode.ToolTipText = "Part hinzufügen";
            this.btn_AddNode.Click += new System.EventHandler(this.toolStripButton1_Click);
            // 
            // btn_AddSub
            // 
            this.btn_AddSub.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btn_AddSub.Image = ((System.Drawing.Image)(resources.GetObject("btn_AddSub.Image")));
            this.btn_AddSub.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btn_AddSub.Name = "btn_AddSub";
            this.btn_AddSub.Size = new System.Drawing.Size(23, 22);
            this.btn_AddSub.Text = "++";
            this.btn_AddSub.ToolTipText = "Unterpart hinzufügen";
            this.btn_AddSub.Click += new System.EventHandler(this.btn_AddSub_Click);
            // 
            // btn_DelNode
            // 
            this.btn_DelNode.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btn_DelNode.Image = ((System.Drawing.Image)(resources.GetObject("btn_DelNode.Image")));
            this.btn_DelNode.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btn_DelNode.Name = "btn_DelNode";
            this.btn_DelNode.Size = new System.Drawing.Size(23, 22);
            this.btn_DelNode.Text = "-";
            this.btn_DelNode.ToolTipText = "Part entfernen";
            this.btn_DelNode.Click += new System.EventHandler(this.btn_DelNode_Click);
            // 
            // tree_Model
            // 
            this.tree_Model.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tree_Model.ContextMenuStrip = this.contextMenuStrip1;
            this.tree_Model.DrawMode = System.Windows.Forms.TreeViewDrawMode.OwnerDrawText;
            this.tree_Model.HideSelection = false;
            this.tree_Model.LabelEdit = true;
            this.tree_Model.Location = new System.Drawing.Point(0, 0);
            this.tree_Model.Name = "tree_Model";
            treeNode1.Name = "node_Model";
            treeNode1.Tag = "0";
            treeNode1.Text = "Model";
            this.tree_Model.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode1});
            this.tree_Model.Size = new System.Drawing.Size(240, 446);
            this.tree_Model.TabIndex = 0;
            this.tree_Model.AfterLabelEdit += new System.Windows.Forms.NodeLabelEditEventHandler(this.tree_Model_AfterLabelEdit);
            this.tree_Model.DrawNode += new System.Windows.Forms.DrawTreeNodeEventHandler(this.tree_Model_DrawNode);
            this.tree_Model.BeforeSelect += new System.Windows.Forms.TreeViewCancelEventHandler(this.tree_Model_BeforeSelect);
            this.tree_Model.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.tree_Model_AfterSelect);
            this.tree_Model.NodeMouseClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.tree_Model_NodeMouseClick);
            this.tree_Model.Enter += new System.EventHandler(this.tree_Model_Enter);
            this.tree_Model.Leave += new System.EventHandler(this.tree_Model_Leave);
            // 
            // splitContainer2
            // 
            this.splitContainer2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer2.Location = new System.Drawing.Point(0, 0);
            this.splitContainer2.Name = "splitContainer2";
            this.splitContainer2.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer2.Panel1
            // 
            this.splitContainer2.Panel1.Controls.Add(this.groupBox1);
            // 
            // splitContainer2.Panel2
            // 
            this.splitContainer2.Panel2.Controls.Add(this.groupBox2);
            this.splitContainer2.Size = new System.Drawing.Size(602, 474);
            this.splitContainer2.SplitterDistance = 259;
            this.splitContainer2.TabIndex = 1;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.txt_Name);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.grid_Nodes);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(5);
            this.groupBox1.Size = new System.Drawing.Size(602, 259);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Parts";
            // 
            // txt_Name
            // 
            this.txt_Name.Location = new System.Drawing.Point(52, 15);
            this.txt_Name.Name = "txt_Name";
            this.txt_Name.Size = new System.Drawing.Size(100, 20);
            this.txt_Name.TabIndex = 8;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(8, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Name:";
            // 
            // grid_Nodes
            // 
            this.grid_Nodes.AllowUserToAddRows = false;
            this.grid_Nodes.AllowUserToDeleteRows = false;
            this.grid_Nodes.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.grid_Nodes.AutoGenerateColumns = false;
            this.grid_Nodes.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.grid_Nodes.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.grid_Nodes.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.grid_Nodes.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Node_Id,
            this.parentIdDataGridViewTextBoxColumn,
            this.nameDataGridViewTextBoxColumn,
            this.channelDataGridViewTextBoxColumn,
            this.formatDataGridViewTextBoxColumn,
            this.modelDataGridViewTextBoxColumn,
            this.Node_NodePath});
            this.grid_Nodes.ContextMenuStrip = this.contextMenuStrip1;
            this.grid_Nodes.DataSource = this.source_Node;
            this.grid_Nodes.Location = new System.Drawing.Point(5, 41);
            this.grid_Nodes.MultiSelect = false;
            this.grid_Nodes.Name = "grid_Nodes";
            this.grid_Nodes.RowHeadersVisible = false;
            this.grid_Nodes.Size = new System.Drawing.Size(592, 213);
            this.grid_Nodes.TabIndex = 6;
            this.grid_Nodes.SelectionChanged += new System.EventHandler(this.grid_Nodes_SelectionChanged);
            // 
            // Node_Id
            // 
            this.Node_Id.DataPropertyName = "Id";
            this.Node_Id.HeaderText = "Id";
            this.Node_Id.Name = "Node_Id";
            // 
            // parentIdDataGridViewTextBoxColumn
            // 
            this.parentIdDataGridViewTextBoxColumn.DataPropertyName = "Parent_Id";
            this.parentIdDataGridViewTextBoxColumn.HeaderText = "Parent_Id";
            this.parentIdDataGridViewTextBoxColumn.Name = "parentIdDataGridViewTextBoxColumn";
            // 
            // nameDataGridViewTextBoxColumn
            // 
            this.nameDataGridViewTextBoxColumn.DataPropertyName = "Name";
            this.nameDataGridViewTextBoxColumn.HeaderText = "Name";
            this.nameDataGridViewTextBoxColumn.Name = "nameDataGridViewTextBoxColumn";
            // 
            // channelDataGridViewTextBoxColumn
            // 
            this.channelDataGridViewTextBoxColumn.DataPropertyName = "Channel";
            this.channelDataGridViewTextBoxColumn.HeaderText = "Channel";
            this.channelDataGridViewTextBoxColumn.Name = "channelDataGridViewTextBoxColumn";
            // 
            // formatDataGridViewTextBoxColumn
            // 
            this.formatDataGridViewTextBoxColumn.DataPropertyName = "Format";
            this.formatDataGridViewTextBoxColumn.HeaderText = "Format";
            this.formatDataGridViewTextBoxColumn.Name = "formatDataGridViewTextBoxColumn";
            // 
            // modelDataGridViewTextBoxColumn
            // 
            this.modelDataGridViewTextBoxColumn.DataPropertyName = "Model";
            this.modelDataGridViewTextBoxColumn.HeaderText = "Model";
            this.modelDataGridViewTextBoxColumn.Name = "modelDataGridViewTextBoxColumn";
            // 
            // Node_NodePath
            // 
            this.Node_NodePath.DataPropertyName = "NodePath";
            this.Node_NodePath.HeaderText = "NodePath";
            this.Node_NodePath.Name = "Node_NodePath";
            // 
            // source_Node
            // 
            this.source_Node.DataMember = "Node";
            this.source_Node.DataSource = this.dataset_Main;
            // 
            // dataset_Main
            // 
            this.dataset_Main.DataSetName = "dataset_Main";
            this.dataset_Main.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.grid_Properties);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox2.Location = new System.Drawing.Point(0, 0);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(5);
            this.groupBox2.Size = new System.Drawing.Size(602, 211);
            this.groupBox2.TabIndex = 0;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Properties";
            // 
            // grid_Properties
            // 
            this.grid_Properties.AutoGenerateColumns = false;
            this.grid_Properties.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.grid_Properties.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.grid_Properties.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.grid_Properties.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Properties_Id,
            this.Properties_Node_Id,
            this.Properties_Name,
            this.Properties_Channel,
            this.Properties_Format,
            this.Properties_Model});
            this.grid_Properties.DataSource = this.source_Properties;
            this.grid_Properties.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grid_Properties.Location = new System.Drawing.Point(5, 18);
            this.grid_Properties.MultiSelect = false;
            this.grid_Properties.Name = "grid_Properties";
            this.grid_Properties.RowHeadersVisible = false;
            this.grid_Properties.Size = new System.Drawing.Size(592, 188);
            this.grid_Properties.TabIndex = 1;
            // 
            // Properties_Id
            // 
            this.Properties_Id.DataPropertyName = "Id";
            this.Properties_Id.HeaderText = "Id";
            this.Properties_Id.Name = "Properties_Id";
            // 
            // Properties_Node_Id
            // 
            this.Properties_Node_Id.DataPropertyName = "Node_Id";
            this.Properties_Node_Id.HeaderText = "Node_Id";
            this.Properties_Node_Id.Name = "Properties_Node_Id";
            // 
            // Properties_Name
            // 
            this.Properties_Name.DataPropertyName = "Name";
            this.Properties_Name.HeaderText = "Name";
            this.Properties_Name.Name = "Properties_Name";
            // 
            // Properties_Channel
            // 
            this.Properties_Channel.DataPropertyName = "Channel";
            this.Properties_Channel.HeaderText = "Channel";
            this.Properties_Channel.Name = "Properties_Channel";
            // 
            // Properties_Format
            // 
            this.Properties_Format.DataPropertyName = "Format";
            this.Properties_Format.HeaderText = "Format";
            this.Properties_Format.Name = "Properties_Format";
            // 
            // Properties_Model
            // 
            this.Properties_Model.DataPropertyName = "Model";
            this.Properties_Model.HeaderText = "Model";
            this.Properties_Model.Name = "Properties_Model";
            // 
            // source_Properties
            // 
            this.source_Properties.DataMember = "Properties";
            this.source_Properties.DataSource = this.dataset_Main;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.partHinzufügenToolStripMenuItem1,
            this.unterpartHinzufügenToolStripMenuItem1,
            this.parteEntfernenToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(188, 70);
            // 
            // partHinzufügenToolStripMenuItem1
            // 
            this.partHinzufügenToolStripMenuItem1.Name = "partHinzufügenToolStripMenuItem1";
            this.partHinzufügenToolStripMenuItem1.Size = new System.Drawing.Size(187, 22);
            this.partHinzufügenToolStripMenuItem1.Text = "Part hinzufügen";
            this.partHinzufügenToolStripMenuItem1.Click += new System.EventHandler(this.toolStripButton1_Click);
            // 
            // unterpartHinzufügenToolStripMenuItem1
            // 
            this.unterpartHinzufügenToolStripMenuItem1.Name = "unterpartHinzufügenToolStripMenuItem1";
            this.unterpartHinzufügenToolStripMenuItem1.Size = new System.Drawing.Size(187, 22);
            this.unterpartHinzufügenToolStripMenuItem1.Text = "Unterpart hinzufügen";
            this.unterpartHinzufügenToolStripMenuItem1.Click += new System.EventHandler(this.btn_AddSub_Click);
            // 
            // parteEntfernenToolStripMenuItem
            // 
            this.parteEntfernenToolStripMenuItem.Name = "parteEntfernenToolStripMenuItem";
            this.parteEntfernenToolStripMenuItem.Size = new System.Drawing.Size(187, 22);
            this.parteEntfernenToolStripMenuItem.Text = "Parte entfernen";
            this.parteEntfernenToolStripMenuItem.Click += new System.EventHandler(this.btn_DelNode_Click);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(6, 25);
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(6, 25);
            // 
            // frm_Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(846, 520);
            this.Controls.Add(this.splitContainer1);
            this.Controls.Add(this.statusbar);
            this.Controls.Add(this.menu);
            this.MainMenuStrip = this.menu;
            this.Name = "frm_Main";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Visual_Cybop";
            this.Shown += new System.EventHandler(this.frm_Main_Shown);
            this.menu.ResumeLayout(false);
            this.menu.PerformLayout();
            this.statusbar.ResumeLayout(false);
            this.statusbar.PerformLayout();
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.toolbar_tree.ResumeLayout(false);
            this.toolbar_tree.PerformLayout();
            this.splitContainer2.Panel1.ResumeLayout(false);
            this.splitContainer2.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).EndInit();
            this.splitContainer2.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.grid_Nodes)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.source_Node)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataset_Main)).EndInit();
            this.groupBox2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.grid_Properties)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.source_Properties)).EndInit();
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menu;
        private System.Windows.Forms.ToolStripMenuItem dateiToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem beendenToolStripMenuItem;
        private System.Windows.Forms.StatusStrip statusbar;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private System.Windows.Forms.BindingSource source_Node;
        private System.Windows.Forms.BindingSource source_Properties;
        private dataset_Main dataset_Main;
        private System.Windows.Forms.ToolStripStatusLabel lbl_TagId;
        private System.Windows.Forms.ToolStripStatusLabel lbl_NodeIndex;
        private System.Windows.Forms.ToolStripStatusLabel lbl_NodePath;
        private System.Windows.Forms.ToolStripMenuItem neuToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem öffnenToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem projektSpeichernToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem speichernUnterToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem bearbeitenToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem partHinzufügenToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem unterpartHinzufügenToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem partLöschenToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem projektToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem projektErzeugenToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem extrasToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem optionenToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem hilfeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem hilfeToolStripMenuItem1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem überToolStripMenuItem;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox txt_Name;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView grid_Nodes;
        private System.Windows.Forms.DataGridViewTextBoxColumn Node_Id;
        private System.Windows.Forms.DataGridViewTextBoxColumn parentIdDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn nameDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn channelDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn formatDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn modelDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn Node_NodePath;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.DataGridView grid_Properties;
        private System.Windows.Forms.DataGridViewTextBoxColumn Properties_Id;
        private System.Windows.Forms.DataGridViewTextBoxColumn Properties_Node_Id;
        private System.Windows.Forms.DataGridViewTextBoxColumn Properties_Name;
        private System.Windows.Forms.DataGridViewTextBoxColumn Properties_Channel;
        private System.Windows.Forms.DataGridViewTextBoxColumn Properties_Format;
        private System.Windows.Forms.DataGridViewTextBoxColumn Properties_Model;
        private System.Windows.Forms.ToolStrip toolbar_tree;
        private System.Windows.Forms.ToolStripButton btn_AddNode;
        private System.Windows.Forms.ToolStripButton btn_AddSub;
        private System.Windows.Forms.ToolStripButton btn_DelNode;
        private System.Windows.Forms.TreeView tree_Model;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem partHinzufügenToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem unterpartHinzufügenToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem parteEntfernenToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
    }
}

