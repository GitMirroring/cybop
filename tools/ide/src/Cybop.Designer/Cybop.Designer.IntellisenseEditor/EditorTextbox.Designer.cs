namespace Cybop.Designer.IntellisenseEditor
{
    partial class EditorTextbox
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

        #region Vom Komponenten-Designer generierter Code

        /// <summary> 
        /// Erforderliche Methode für die Designerunterstützung. 
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.textBoxLineNumbers = new System.Windows.Forms.TextBox();
            this.listBoxRefPicker = new System.Windows.Forms.ListBox();
            this.listBoxTagFiller = new System.Windows.Forms.ListBox();
            this.listBoxAutoComplete = new System.Windows.Forms.ListBox();
            this.richTextBoxEditor = new System.Windows.Forms.RichTextBox();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.toolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripMenuItem5 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripMenuItem4 = new System.Windows.Forms.ToolStripMenuItem();
            this.labelStatLines = new System.Windows.Forms.Label();
            this.labelStatCurrentPos = new System.Windows.Forms.Label();
            this.labelStatLength = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitContainer1
            // 
            this.splitContainer1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.splitContainer1.FixedPanel = System.Windows.Forms.FixedPanel.Panel1;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.textBoxLineNumbers);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.listBoxRefPicker);
            this.splitContainer1.Panel2.Controls.Add(this.listBoxTagFiller);
            this.splitContainer1.Panel2.Controls.Add(this.listBoxAutoComplete);
            this.splitContainer1.Panel2.Controls.Add(this.richTextBoxEditor);
            this.splitContainer1.Size = new System.Drawing.Size(449, 391);
            this.splitContainer1.SplitterDistance = 32;
            this.splitContainer1.TabIndex = 0;
            this.splitContainer1.SizeChanged += new System.EventHandler(this.splitContainer1_SizeChanged);
            // 
            // textBoxLineNumbers
            // 
            this.textBoxLineNumbers.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBoxLineNumbers.Dock = System.Windows.Forms.DockStyle.Right;
            this.textBoxLineNumbers.Location = new System.Drawing.Point(7, 0);
            this.textBoxLineNumbers.Multiline = true;
            this.textBoxLineNumbers.Name = "textBoxLineNumbers";
            this.textBoxLineNumbers.ReadOnly = true;
            this.textBoxLineNumbers.Size = new System.Drawing.Size(25, 391);
            this.textBoxLineNumbers.TabIndex = 5;
            this.textBoxLineNumbers.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // listBoxRefPicker
            // 
            this.listBoxRefPicker.FormattingEnabled = true;
            this.listBoxRefPicker.Location = new System.Drawing.Point(62, 215);
            this.listBoxRefPicker.Name = "listBoxRefPicker";
            this.listBoxRefPicker.Size = new System.Drawing.Size(120, 95);
            this.listBoxRefPicker.TabIndex = 3;
            this.listBoxRefPicker.Visible = false;
            this.listBoxRefPicker.VisibleChanged += new System.EventHandler(this.listBoxRefPicker_VisibleChanged);
            this.listBoxRefPicker.KeyDown += new System.Windows.Forms.KeyEventHandler(this.listBoxGeneric_KeyDown);
            // 
            // listBoxTagFiller
            // 
            this.listBoxTagFiller.FormattingEnabled = true;
            this.listBoxTagFiller.Location = new System.Drawing.Point(193, 199);
            this.listBoxTagFiller.Name = "listBoxTagFiller";
            this.listBoxTagFiller.Size = new System.Drawing.Size(120, 95);
            this.listBoxTagFiller.TabIndex = 2;
            this.listBoxTagFiller.Visible = false;
            this.listBoxTagFiller.VisibleChanged += new System.EventHandler(this.listBoxTagFiller_VisibleChanged);
            this.listBoxTagFiller.DoubleClick += new System.EventHandler(this.listBoxTagFiller_DoubleClick_1);
            this.listBoxTagFiller.KeyDown += new System.Windows.Forms.KeyEventHandler(this.listBoxGeneric_KeyDown);
            this.listBoxTagFiller.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.listBoxTagFiller_KeyPress_1);
            // 
            // listBoxAutoComplete
            // 
            this.listBoxAutoComplete.FormattingEnabled = true;
            this.listBoxAutoComplete.Location = new System.Drawing.Point(159, 72);
            this.listBoxAutoComplete.Name = "listBoxAutoComplete";
            this.listBoxAutoComplete.Size = new System.Drawing.Size(120, 95);
            this.listBoxAutoComplete.TabIndex = 1;
            this.listBoxAutoComplete.Visible = false;
            this.listBoxAutoComplete.VisibleChanged += new System.EventHandler(this.listBox1_VisibleChanged);
            this.listBoxAutoComplete.DoubleClick += new System.EventHandler(this.listBoxAutoComplete_DoubleClick);
            this.listBoxAutoComplete.KeyDown += new System.Windows.Forms.KeyEventHandler(this.listBoxGeneric_KeyDown);
            this.listBoxAutoComplete.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.listBoxAutoComplete_KeyPress);
            // 
            // richTextBoxEditor
            // 
            this.richTextBoxEditor.AcceptsTab = true;
            this.richTextBoxEditor.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.richTextBoxEditor.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.richTextBoxEditor.ContextMenuStrip = this.contextMenuStrip1;
            this.richTextBoxEditor.HideSelection = false;
            this.richTextBoxEditor.Location = new System.Drawing.Point(0, 0);
            this.richTextBoxEditor.Name = "richTextBoxEditor";
            this.richTextBoxEditor.Size = new System.Drawing.Size(411, 391);
            this.richTextBoxEditor.TabIndex = 1;
            this.richTextBoxEditor.Text = "";
            this.richTextBoxEditor.SelectionChanged += new System.EventHandler(this.richTextBoxEditor_SelectionChanged);
            this.richTextBoxEditor.VScroll += new System.EventHandler(this.textBoxKeyIn_VScroll);
            this.richTextBoxEditor.Click += new System.EventHandler(this.textBoxKeyIn_Click);
            this.richTextBoxEditor.FontChanged += new System.EventHandler(this.textBoxKeyIn_FontChanged);
            this.richTextBoxEditor.SizeChanged += new System.EventHandler(this.richTextBoxEditor_SizeChanged);
            this.richTextBoxEditor.TextChanged += new System.EventHandler(this.textBoxKeyIn_TextChanged);
            this.richTextBoxEditor.KeyDown += new System.Windows.Forms.KeyEventHandler(this.textBoxKeyIn_KeyDown);
            this.richTextBoxEditor.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxKeyIn_KeyPress);
            this.richTextBoxEditor.KeyUp += new System.Windows.Forms.KeyEventHandler(this.textBoxKeyIn_KeyUp);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem3,
            this.toolStripMenuItem1,
            this.toolStripMenuItem2,
            this.toolStripSeparator1,
            this.toolStripMenuItem5,
            this.toolStripSeparator2,
            this.toolStripMenuItem4});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(184, 126);
            this.contextMenuStrip1.VisibleChanged += new System.EventHandler(this.contextMenuStrip1_VisibleChanged);
            // 
            // toolStripMenuItem3
            // 
            this.toolStripMenuItem3.Name = "toolStripMenuItem3";
            this.toolStripMenuItem3.Size = new System.Drawing.Size(183, 22);
            this.toolStripMenuItem3.Text = "Ausschneiden";
            this.toolStripMenuItem3.Click += new System.EventHandler(this.toolStripMenuItem3_Click);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(183, 22);
            this.toolStripMenuItem1.Text = "Kopieren";
            this.toolStripMenuItem1.Click += new System.EventHandler(this.toolStripMenuItem1_Click);
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.Size = new System.Drawing.Size(183, 22);
            this.toolStripMenuItem2.Text = "Einfügen";
            this.toolStripMenuItem2.Click += new System.EventHandler(this.toolStripMenuItem2_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(180, 6);
            // 
            // toolStripMenuItem5
            // 
            this.toolStripMenuItem5.Name = "toolStripMenuItem5";
            this.toolStripMenuItem5.Size = new System.Drawing.Size(183, 22);
            this.toolStripMenuItem5.Text = "Rückgängig machen";
            this.toolStripMenuItem5.Click += new System.EventHandler(this.toolStripMenuItem5_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(180, 6);
            // 
            // toolStripMenuItem4
            // 
            this.toolStripMenuItem4.Name = "toolStripMenuItem4";
            this.toolStripMenuItem4.Size = new System.Drawing.Size(183, 22);
            this.toolStripMenuItem4.Text = "Formatieren";
            this.toolStripMenuItem4.Click += new System.EventHandler(this.toolStripMenuItem4_Click);
            // 
            // labelStatLines
            // 
            this.labelStatLines.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.labelStatLines.AutoSize = true;
            this.labelStatLines.Location = new System.Drawing.Point(4, 394);
            this.labelStatLines.Name = "labelStatLines";
            this.labelStatLines.Size = new System.Drawing.Size(0, 13);
            this.labelStatLines.TabIndex = 1;
            // 
            // labelStatCurrentPos
            // 
            this.labelStatCurrentPos.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.labelStatCurrentPos.AutoSize = true;
            this.labelStatCurrentPos.Location = new System.Drawing.Point(95, 394);
            this.labelStatCurrentPos.Name = "labelStatCurrentPos";
            this.labelStatCurrentPos.Size = new System.Drawing.Size(0, 13);
            this.labelStatCurrentPos.TabIndex = 2;
            // 
            // labelStatLength
            // 
            this.labelStatLength.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.labelStatLength.AutoSize = true;
            this.labelStatLength.Location = new System.Drawing.Point(249, 394);
            this.labelStatLength.Name = "labelStatLength";
            this.labelStatLength.Size = new System.Drawing.Size(0, 13);
            this.labelStatLength.TabIndex = 3;
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // EditorTextbox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.labelStatLength);
            this.Controls.Add(this.labelStatCurrentPos);
            this.Controls.Add(this.labelStatLines);
            this.Controls.Add(this.splitContainer1);
            this.DoubleBuffered = true;
            this.Name = "EditorTextbox";
            this.Size = new System.Drawing.Size(449, 407);
            this.Load += new System.EventHandler(this.EditorTextbox_Load);
            this.VisibleChanged += new System.EventHandler(this.EditorTextbox_VisibleChanged);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.ResumeLayout(false);
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.TextBox textBoxLineNumbers;
        private System.Windows.Forms.RichTextBox richTextBoxEditor;
        private System.Windows.Forms.ListBox listBoxRefPicker;
        private System.Windows.Forms.ListBox listBoxTagFiller;
        private System.Windows.Forms.ListBox listBoxAutoComplete;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem3;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem4;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem5;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.Label labelStatLines;
        private System.Windows.Forms.Label labelStatCurrentPos;
        private System.Windows.Forms.Label labelStatLength;
        private System.Windows.Forms.Timer timer1;

    }
}
