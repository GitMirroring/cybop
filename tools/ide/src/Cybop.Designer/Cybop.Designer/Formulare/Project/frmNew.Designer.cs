namespace Cybop.Designer.Formulare
{
    partial class frmNew
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmNew));
            this.btnAbbrechen = new System.Windows.Forms.Button();
            this.btnAnlegen = new System.Windows.Forms.Button();
            this.lblProjektname = new System.Windows.Forms.Label();
            this.txtProjektname = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // btnAbbrechen
            // 
            this.btnAbbrechen.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            resources.ApplyResources(this.btnAbbrechen, "btnAbbrechen");
            this.btnAbbrechen.Name = "btnAbbrechen";
            this.btnAbbrechen.UseVisualStyleBackColor = true;
            this.btnAbbrechen.Click += new System.EventHandler(this.btnAbbrechen_Click);
            // 
            // btnAnlegen
            // 
            resources.ApplyResources(this.btnAnlegen, "btnAnlegen");
            this.btnAnlegen.Name = "btnAnlegen";
            this.btnAnlegen.UseVisualStyleBackColor = true;
            this.btnAnlegen.Click += new System.EventHandler(this.btnAnlegen_Click);
            // 
            // lblProjektname
            // 
            resources.ApplyResources(this.lblProjektname, "lblProjektname");
            this.lblProjektname.Name = "lblProjektname";
            // 
            // txtProjektname
            // 
            resources.ApplyResources(this.txtProjektname, "txtProjektname");
            this.txtProjektname.Name = "txtProjektname";
            // 
            // frmNew
            // 
            this.AcceptButton = this.btnAnlegen;
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.btnAbbrechen;
            this.Controls.Add(this.txtProjektname);
            this.Controls.Add(this.lblProjektname);
            this.Controls.Add(this.btnAnlegen);
            this.Controls.Add(this.btnAbbrechen);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmNew";
            this.Shown += new System.EventHandler(this.frmNew_Shown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnAbbrechen;
        private System.Windows.Forms.Button btnAnlegen;
        private System.Windows.Forms.Label lblProjektname;
        private System.Windows.Forms.TextBox txtProjektname;
    }
}