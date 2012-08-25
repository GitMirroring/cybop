namespace Cybop.Designer.Formulare
{
    partial class frmSuche
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
            this.tcSuche = new System.Windows.Forms.TabControl();
            this.tpSuchen = new System.Windows.Forms.TabPage();
            this.btnSuchen = new System.Windows.Forms.Button();
            this.lblSuchenIn = new System.Windows.Forms.Label();
            this.cboSuchenIn = new System.Windows.Forms.ComboBox();
            this.txtSuchbegriff = new System.Windows.Forms.TextBox();
            this.lblSuchbegriff = new System.Windows.Forms.Label();
            this.tpSuchenErsetzen = new System.Windows.Forms.TabPage();
            this.btnErsetzen = new System.Windows.Forms.Button();
            this.lblSuchenErsetzenIn = new System.Windows.Forms.Label();
            this.cboSuchenErsetzenIn = new System.Windows.Forms.ComboBox();
            this.txtErsetzen = new System.Windows.Forms.TextBox();
            this.lblErsetzen = new System.Windows.Forms.Label();
            this.txtSuchenErstzen = new System.Windows.Forms.TextBox();
            this.lblSuchenErstzen = new System.Windows.Forms.Label();
            this.tcSuche.SuspendLayout();
            this.tpSuchen.SuspendLayout();
            this.tpSuchenErsetzen.SuspendLayout();
            this.SuspendLayout();
            // 
            // tcSuche
            // 
            this.tcSuche.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tcSuche.Controls.Add(this.tpSuchen);
            this.tcSuche.Controls.Add(this.tpSuchenErsetzen);
            this.tcSuche.Location = new System.Drawing.Point(0, 0);
            this.tcSuche.Name = "tcSuche";
            this.tcSuche.SelectedIndex = 0;
            this.tcSuche.Size = new System.Drawing.Size(285, 188);
            this.tcSuche.TabIndex = 0;
            // 
            // tpSuchen
            // 
            this.tpSuchen.Controls.Add(this.btnSuchen);
            this.tpSuchen.Controls.Add(this.lblSuchenIn);
            this.tpSuchen.Controls.Add(this.cboSuchenIn);
            this.tpSuchen.Controls.Add(this.txtSuchbegriff);
            this.tpSuchen.Controls.Add(this.lblSuchbegriff);
            this.tpSuchen.Location = new System.Drawing.Point(4, 22);
            this.tpSuchen.Name = "tpSuchen";
            this.tpSuchen.Padding = new System.Windows.Forms.Padding(3);
            this.tpSuchen.Size = new System.Drawing.Size(277, 162);
            this.tpSuchen.TabIndex = 0;
            this.tpSuchen.Text = "Suchen";
            this.tpSuchen.UseVisualStyleBackColor = true;
            // 
            // btnSuchen
            // 
            this.btnSuchen.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnSuchen.Location = new System.Drawing.Point(193, 94);
            this.btnSuchen.Name = "btnSuchen";
            this.btnSuchen.Size = new System.Drawing.Size(75, 23);
            this.btnSuchen.TabIndex = 10;
            this.btnSuchen.Text = "Suchen";
            this.btnSuchen.UseVisualStyleBackColor = true;
            this.btnSuchen.Click += new System.EventHandler(this.btnSuchen_Click);
            // 
            // lblSuchenIn
            // 
            this.lblSuchenIn.AutoSize = true;
            this.lblSuchenIn.Location = new System.Drawing.Point(4, 51);
            this.lblSuchenIn.Name = "lblSuchenIn";
            this.lblSuchenIn.Size = new System.Drawing.Size(58, 13);
            this.lblSuchenIn.TabIndex = 3;
            this.lblSuchenIn.Text = "Suchen in:";
            // 
            // cboSuchenIn
            // 
            this.cboSuchenIn.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.cboSuchenIn.FormattingEnabled = true;
            this.cboSuchenIn.Items.AddRange(new object[] {
            "Aktuelles Dokument",
            "Alle geöffneten Dokumente",
            "Alle Dokumente"});
            this.cboSuchenIn.Location = new System.Drawing.Point(9, 67);
            this.cboSuchenIn.Name = "cboSuchenIn";
            this.cboSuchenIn.Size = new System.Drawing.Size(259, 21);
            this.cboSuchenIn.TabIndex = 2;
            this.cboSuchenIn.SelectedIndexChanged += new System.EventHandler(this.cboSuchenIn_SelectedIndexChanged);
            // 
            // txtSuchbegriff
            // 
            this.txtSuchbegriff.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txtSuchbegriff.BackColor = System.Drawing.Color.White;
            this.txtSuchbegriff.Location = new System.Drawing.Point(7, 24);
            this.txtSuchbegriff.Name = "txtSuchbegriff";
            this.txtSuchbegriff.Size = new System.Drawing.Size(261, 20);
            this.txtSuchbegriff.TabIndex = 1;
            this.txtSuchbegriff.TextChanged += new System.EventHandler(this.txtSuchbegriff_TextChanged);
            // 
            // lblSuchbegriff
            // 
            this.lblSuchbegriff.AutoSize = true;
            this.lblSuchbegriff.Location = new System.Drawing.Point(4, 8);
            this.lblSuchbegriff.Name = "lblSuchbegriff";
            this.lblSuchbegriff.Size = new System.Drawing.Size(61, 13);
            this.lblSuchbegriff.TabIndex = 0;
            this.lblSuchbegriff.Text = "Suchbegriff";
            // 
            // tpSuchenErsetzen
            // 
            this.tpSuchenErsetzen.Controls.Add(this.btnErsetzen);
            this.tpSuchenErsetzen.Controls.Add(this.lblSuchenErsetzenIn);
            this.tpSuchenErsetzen.Controls.Add(this.cboSuchenErsetzenIn);
            this.tpSuchenErsetzen.Controls.Add(this.txtErsetzen);
            this.tpSuchenErsetzen.Controls.Add(this.lblErsetzen);
            this.tpSuchenErsetzen.Controls.Add(this.txtSuchenErstzen);
            this.tpSuchenErsetzen.Controls.Add(this.lblSuchenErstzen);
            this.tpSuchenErsetzen.Location = new System.Drawing.Point(4, 22);
            this.tpSuchenErsetzen.Name = "tpSuchenErsetzen";
            this.tpSuchenErsetzen.Padding = new System.Windows.Forms.Padding(3);
            this.tpSuchenErsetzen.Size = new System.Drawing.Size(277, 162);
            this.tpSuchenErsetzen.TabIndex = 1;
            this.tpSuchenErsetzen.Text = "Suchen und Ersetzen";
            this.tpSuchenErsetzen.UseVisualStyleBackColor = true;
            // 
            // btnErsetzen
            // 
            this.btnErsetzen.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnErsetzen.Location = new System.Drawing.Point(194, 131);
            this.btnErsetzen.Name = "btnErsetzen";
            this.btnErsetzen.Size = new System.Drawing.Size(75, 23);
            this.btnErsetzen.TabIndex = 9;
            this.btnErsetzen.Text = "Ersetzen";
            this.btnErsetzen.UseVisualStyleBackColor = true;
            this.btnErsetzen.Click += new System.EventHandler(this.btnErsetzen_Click);
            // 
            // lblSuchenErsetzenIn
            // 
            this.lblSuchenErsetzenIn.AutoSize = true;
            this.lblSuchenErsetzenIn.Location = new System.Drawing.Point(5, 88);
            this.lblSuchenErsetzenIn.Name = "lblSuchenErsetzenIn";
            this.lblSuchenErsetzenIn.Size = new System.Drawing.Size(58, 13);
            this.lblSuchenErsetzenIn.TabIndex = 7;
            this.lblSuchenErsetzenIn.Text = "Suchen in:";
            // 
            // cboSuchenErsetzenIn
            // 
            this.cboSuchenErsetzenIn.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.cboSuchenErsetzenIn.FormattingEnabled = true;
            this.cboSuchenErsetzenIn.Items.AddRange(new object[] {
            "Aktuelles Dokument",
            "Alle geöffneten Dokumente"});
            this.cboSuchenErsetzenIn.Location = new System.Drawing.Point(10, 104);
            this.cboSuchenErsetzenIn.Name = "cboSuchenErsetzenIn";
            this.cboSuchenErsetzenIn.Size = new System.Drawing.Size(259, 21);
            this.cboSuchenErsetzenIn.TabIndex = 6;
            // 
            // txtErsetzen
            // 
            this.txtErsetzen.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txtErsetzen.BackColor = System.Drawing.Color.White;
            this.txtErsetzen.Location = new System.Drawing.Point(8, 63);
            this.txtErsetzen.Name = "txtErsetzen";
            this.txtErsetzen.Size = new System.Drawing.Size(261, 20);
            this.txtErsetzen.TabIndex = 5;
            // 
            // lblErsetzen
            // 
            this.lblErsetzen.AutoSize = true;
            this.lblErsetzen.Location = new System.Drawing.Point(5, 47);
            this.lblErsetzen.Name = "lblErsetzen";
            this.lblErsetzen.Size = new System.Drawing.Size(48, 13);
            this.lblErsetzen.TabIndex = 4;
            this.lblErsetzen.Text = "Ersetzen";
            // 
            // txtSuchenErstzen
            // 
            this.txtSuchenErstzen.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txtSuchenErstzen.BackColor = System.Drawing.Color.White;
            this.txtSuchenErstzen.Location = new System.Drawing.Point(8, 24);
            this.txtSuchenErstzen.Name = "txtSuchenErstzen";
            this.txtSuchenErstzen.Size = new System.Drawing.Size(261, 20);
            this.txtSuchenErstzen.TabIndex = 3;
            this.txtSuchenErstzen.TextChanged += new System.EventHandler(this.txtSuchenErstzen_TextChanged);
            // 
            // lblSuchenErstzen
            // 
            this.lblSuchenErstzen.AutoSize = true;
            this.lblSuchenErstzen.Location = new System.Drawing.Point(5, 8);
            this.lblSuchenErstzen.Name = "lblSuchenErstzen";
            this.lblSuchenErstzen.Size = new System.Drawing.Size(61, 13);
            this.lblSuchenErstzen.TabIndex = 2;
            this.lblSuchenErstzen.Text = "Suchbegriff";
            // 
            // frmSuche
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 188);
            this.Controls.Add(this.tcSuche);
            this.Name = "frmSuche";
            this.Text = "Suchen und Ersetzen";
            this.Load += new System.EventHandler(this.frmSuche_Load);
            this.tcSuche.ResumeLayout(false);
            this.tpSuchen.ResumeLayout(false);
            this.tpSuchen.PerformLayout();
            this.tpSuchenErsetzen.ResumeLayout(false);
            this.tpSuchenErsetzen.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tcSuche;
        private System.Windows.Forms.TabPage tpSuchen;
        private System.Windows.Forms.TabPage tpSuchenErsetzen;
        private System.Windows.Forms.TextBox txtSuchbegriff;
        private System.Windows.Forms.Label lblSuchbegriff;
        private System.Windows.Forms.TextBox txtErsetzen;
        private System.Windows.Forms.Label lblErsetzen;
        private System.Windows.Forms.TextBox txtSuchenErstzen;
        private System.Windows.Forms.Label lblSuchenErstzen;
        private System.Windows.Forms.Button btnSuchen;
        private System.Windows.Forms.Label lblSuchenIn;
        private System.Windows.Forms.ComboBox cboSuchenIn;
        private System.Windows.Forms.Button btnErsetzen;
        private System.Windows.Forms.Label lblSuchenErsetzenIn;
        private System.Windows.Forms.ComboBox cboSuchenErsetzenIn;
    }
}