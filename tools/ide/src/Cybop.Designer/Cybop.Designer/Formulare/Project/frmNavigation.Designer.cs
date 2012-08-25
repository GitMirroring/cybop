namespace Cybop.Designer.Formulare
{
    partial class frmNavigation
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmNavigation));
            this.tvNavigation = new System.Windows.Forms.TreeView();
            this.SuspendLayout();
            // 
            // tvNavigation
            // 
            this.tvNavigation.AllowDrop = true;
            this.tvNavigation.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            resources.ApplyResources(this.tvNavigation, "tvNavigation");
            this.tvNavigation.LabelEdit = true;
            this.tvNavigation.Name = "tvNavigation";
            this.tvNavigation.AfterLabelEdit += new System.Windows.Forms.NodeLabelEditEventHandler(this.tvNavigation_AfterLabelEdit);
            this.tvNavigation.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.tvNavigation_ItemDrag);
            this.tvNavigation.DragDrop += new System.Windows.Forms.DragEventHandler(this.tvNavigation_DragDrop);
            this.tvNavigation.DragEnter += new System.Windows.Forms.DragEventHandler(this.tvNavigation_DragEnter);
            this.tvNavigation.DragOver += new System.Windows.Forms.DragEventHandler(this.tvNavigation_DragOver);
            this.tvNavigation.MouseClick += new System.Windows.Forms.MouseEventHandler(this.tvNavigation_MouseClick);
            this.tvNavigation.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.tvNavigation_MouseDoubleClick);
            // 
            // frmNavigation
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.tvNavigation);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmNavigation";
            this.ShowInTaskbar = false;
            this.TopMost = true;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmNavigation_FormClosing);
            this.Load += new System.EventHandler(this.frmNavigation_Load);
            this.MouseEnter += new System.EventHandler(this.frmNavigation_MouseEnter);
            this.MouseLeave += new System.EventHandler(this.frmNavigation_MouseLeave);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TreeView tvNavigation;

    }
}