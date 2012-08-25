namespace Cybop.Designer.Formulare
{
    partial class frmLoad
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmLoad));
            this.progressBarCybopDesigner = new System.Windows.Forms.ProgressBar();
            this.lblBezeichnung = new System.Windows.Forms.Label();
            this.lblBezeichnungCybopDesigner = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // progressBarCybopDesigner
            // 
            resources.ApplyResources(this.progressBarCybopDesigner, "progressBarCybopDesigner");
            this.progressBarCybopDesigner.Name = "progressBarCybopDesigner";
            // 
            // lblBezeichnung
            // 
            resources.ApplyResources(this.lblBezeichnung, "lblBezeichnung");
            this.lblBezeichnung.Name = "lblBezeichnung";
            // 
            // lblBezeichnungCybopDesigner
            // 
            resources.ApplyResources(this.lblBezeichnungCybopDesigner, "lblBezeichnungCybopDesigner");
            this.lblBezeichnungCybopDesigner.Name = "lblBezeichnungCybopDesigner";
            // 
            // frmLoad
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.lblBezeichnungCybopDesigner);
            this.Controls.Add(this.lblBezeichnung);
            this.Controls.Add(this.progressBarCybopDesigner);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "frmLoad";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmLoad_FormClosing);
            this.Shown += new System.EventHandler(this.frmLoad_Shown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ProgressBar progressBarCybopDesigner;
        private System.Windows.Forms.Label lblBezeichnung;
        private System.Windows.Forms.Label lblBezeichnungCybopDesigner;
    }
}