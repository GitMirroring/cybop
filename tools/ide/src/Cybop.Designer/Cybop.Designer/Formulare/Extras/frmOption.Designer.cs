namespace Cybop.Designer.Formulare
{
    partial class frmOption
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmOption));
            this.btnColorBrackets = new System.Windows.Forms.Button();
            this.gbEinstellungenFarben = new System.Windows.Forms.GroupBox();
            this.btnColorXmlKommentar = new System.Windows.Forms.Button();
            this.btnColorHintergrund = new System.Windows.Forms.Button();
            this.btnColor = new System.Windows.Forms.Button();
            this.btnSchriftart = new System.Windows.Forms.Button();
            this.rtfBeispiel = new System.Windows.Forms.RichTextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btnColorNodeText = new System.Windows.Forms.Button();
            this.btnColorAttributeMarkup = new System.Windows.Forms.Button();
            this.btnColorAttributeKey = new System.Windows.Forms.Button();
            this.btnColorAttributeValue = new System.Windows.Forms.Button();
            this.gbNavigation = new System.Windows.Forms.GroupBox();
            this.trackBarTransparanc = new System.Windows.Forms.TrackBar();
            this.lblNavTransparentsValue = new System.Windows.Forms.Label();
            this.lblNavTransparentsBezeichnung = new System.Windows.Forms.Label();
            this.gbEinstellungenFarben.SuspendLayout();
            this.gbNavigation.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarTransparanc)).BeginInit();
            this.SuspendLayout();
            // 
            // btnColorBrackets
            // 
            this.btnColorBrackets.Location = new System.Drawing.Point(6, 19);
            this.btnColorBrackets.Name = "btnColorBrackets";
            this.btnColorBrackets.Size = new System.Drawing.Size(166, 27);
            this.btnColorBrackets.TabIndex = 1;
            this.btnColorBrackets.Text = "Bracket-Farben";
            this.btnColorBrackets.UseVisualStyleBackColor = true;
            this.btnColorBrackets.Click += new System.EventHandler(this.btnColorBrackets_Click);
            // 
            // gbEinstellungenFarben
            // 
            this.gbEinstellungenFarben.Controls.Add(this.btnColorXmlKommentar);
            this.gbEinstellungenFarben.Controls.Add(this.btnColorHintergrund);
            this.gbEinstellungenFarben.Controls.Add(this.btnColor);
            this.gbEinstellungenFarben.Controls.Add(this.btnSchriftart);
            this.gbEinstellungenFarben.Controls.Add(this.rtfBeispiel);
            this.gbEinstellungenFarben.Controls.Add(this.label1);
            this.gbEinstellungenFarben.Controls.Add(this.btnColorNodeText);
            this.gbEinstellungenFarben.Controls.Add(this.btnColorAttributeMarkup);
            this.gbEinstellungenFarben.Controls.Add(this.btnColorAttributeKey);
            this.gbEinstellungenFarben.Controls.Add(this.btnColorAttributeValue);
            this.gbEinstellungenFarben.Controls.Add(this.btnColorBrackets);
            this.gbEinstellungenFarben.Location = new System.Drawing.Point(13, 13);
            this.gbEinstellungenFarben.Name = "gbEinstellungenFarben";
            this.gbEinstellungenFarben.Size = new System.Drawing.Size(778, 330);
            this.gbEinstellungenFarben.TabIndex = 2;
            this.gbEinstellungenFarben.TabStop = false;
            this.gbEinstellungenFarben.Text = "Schriftart und Farben";
            // 
            // btnColorXmlKommentar
            // 
            this.btnColorXmlKommentar.Location = new System.Drawing.Point(350, 52);
            this.btnColorXmlKommentar.Name = "btnColorXmlKommentar";
            this.btnColorXmlKommentar.Size = new System.Drawing.Size(166, 27);
            this.btnColorXmlKommentar.TabIndex = 11;
            this.btnColorXmlKommentar.Text = "XML Kommentar-Schriftfarbe";
            this.btnColorXmlKommentar.UseVisualStyleBackColor = true;
            this.btnColorXmlKommentar.Click += new System.EventHandler(this.btnColorXmlKommentar_Click);
            // 
            // btnColorHintergrund
            // 
            this.btnColorHintergrund.Location = new System.Drawing.Point(673, 19);
            this.btnColorHintergrund.Name = "btnColorHintergrund";
            this.btnColorHintergrund.Size = new System.Drawing.Size(99, 27);
            this.btnColorHintergrund.TabIndex = 10;
            this.btnColorHintergrund.Text = "Hintergrundfarbe";
            this.btnColorHintergrund.UseVisualStyleBackColor = true;
            this.btnColorHintergrund.Click += new System.EventHandler(this.btnColorHintergrund_Click);
            // 
            // btnColor
            // 
            this.btnColor.Location = new System.Drawing.Point(522, 52);
            this.btnColor.Name = "btnColor";
            this.btnColor.Size = new System.Drawing.Size(145, 27);
            this.btnColor.TabIndex = 9;
            this.btnColor.Text = "Schriftfarbe";
            this.btnColor.UseVisualStyleBackColor = true;
            this.btnColor.Click += new System.EventHandler(this.btnColor_Click);
            // 
            // btnSchriftart
            // 
            this.btnSchriftart.Location = new System.Drawing.Point(522, 19);
            this.btnSchriftart.Name = "btnSchriftart";
            this.btnSchriftart.Size = new System.Drawing.Size(145, 27);
            this.btnSchriftart.TabIndex = 8;
            this.btnSchriftart.Text = "Schriftart";
            this.btnSchriftart.UseVisualStyleBackColor = true;
            this.btnSchriftart.Click += new System.EventHandler(this.btnSchriftart_Click);
            // 
            // rtfBeispiel
            // 
            this.rtfBeispiel.BackColor = System.Drawing.Color.White;
            this.rtfBeispiel.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.rtfBeispiel.Location = new System.Drawing.Point(6, 98);
            this.rtfBeispiel.Name = "rtfBeispiel";
            this.rtfBeispiel.ReadOnly = true;
            this.rtfBeispiel.Size = new System.Drawing.Size(766, 224);
            this.rtfBeispiel.TabIndex = 7;
            this.rtfBeispiel.Text = resources.GetString("rtfBeispiel.Text");
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 82);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(46, 13);
            this.label1.TabIndex = 6;
            this.label1.Text = "Beispiel:";
            // 
            // btnColorNodeText
            // 
            this.btnColorNodeText.Location = new System.Drawing.Point(350, 19);
            this.btnColorNodeText.Name = "btnColorNodeText";
            this.btnColorNodeText.Size = new System.Drawing.Size(166, 27);
            this.btnColorNodeText.TabIndex = 5;
            this.btnColorNodeText.Text = "XML Knoten Schriftfarbe";
            this.btnColorNodeText.UseVisualStyleBackColor = true;
            this.btnColorNodeText.Click += new System.EventHandler(this.btnColorNodeText_Click);
            // 
            // btnColorAttributeMarkup
            // 
            this.btnColorAttributeMarkup.Location = new System.Drawing.Point(178, 52);
            this.btnColorAttributeMarkup.Name = "btnColorAttributeMarkup";
            this.btnColorAttributeMarkup.Size = new System.Drawing.Size(166, 27);
            this.btnColorAttributeMarkup.TabIndex = 4;
            this.btnColorAttributeMarkup.Text = "XML Attribute Markup-Farbe";
            this.btnColorAttributeMarkup.UseVisualStyleBackColor = true;
            this.btnColorAttributeMarkup.Click += new System.EventHandler(this.btnColorAttributeMarkup_Click);
            // 
            // btnColorAttributeKey
            // 
            this.btnColorAttributeKey.Location = new System.Drawing.Point(178, 19);
            this.btnColorAttributeKey.Name = "btnColorAttributeKey";
            this.btnColorAttributeKey.Size = new System.Drawing.Size(166, 27);
            this.btnColorAttributeKey.TabIndex = 3;
            this.btnColorAttributeKey.Text = "XML Attributeschlüssel-Farbe";
            this.btnColorAttributeKey.UseVisualStyleBackColor = true;
            this.btnColorAttributeKey.Click += new System.EventHandler(this.btnColorAttributeKey_Click);
            // 
            // btnColorAttributeValue
            // 
            this.btnColorAttributeValue.Location = new System.Drawing.Point(6, 52);
            this.btnColorAttributeValue.Name = "btnColorAttributeValue";
            this.btnColorAttributeValue.Size = new System.Drawing.Size(166, 27);
            this.btnColorAttributeValue.TabIndex = 2;
            this.btnColorAttributeValue.Text = "XML Attributewert-Farbe";
            this.btnColorAttributeValue.UseVisualStyleBackColor = true;
            this.btnColorAttributeValue.Click += new System.EventHandler(this.btnColorAttributeValue_Click);
            // 
            // gbNavigation
            // 
            this.gbNavigation.Controls.Add(this.trackBarTransparanc);
            this.gbNavigation.Controls.Add(this.lblNavTransparentsValue);
            this.gbNavigation.Controls.Add(this.lblNavTransparentsBezeichnung);
            this.gbNavigation.Location = new System.Drawing.Point(13, 350);
            this.gbNavigation.Name = "gbNavigation";
            this.gbNavigation.Size = new System.Drawing.Size(269, 83);
            this.gbNavigation.TabIndex = 3;
            this.gbNavigation.TabStop = false;
            this.gbNavigation.Text = "Navigation";
            // 
            // trackBarTransparanc
            // 
            this.trackBarTransparanc.Location = new System.Drawing.Point(9, 36);
            this.trackBarTransparanc.Maximum = 100;
            this.trackBarTransparanc.Name = "trackBarTransparanc";
            this.trackBarTransparanc.Size = new System.Drawing.Size(254, 45);
            this.trackBarTransparanc.TabIndex = 2;
            this.trackBarTransparanc.TickFrequency = 5;
            this.trackBarTransparanc.Scroll += new System.EventHandler(this.trackBarTransparanc_Scroll);
            // 
            // lblNavTransparentsValue
            // 
            this.lblNavTransparentsValue.AutoSize = true;
            this.lblNavTransparentsValue.Location = new System.Drawing.Point(83, 20);
            this.lblNavTransparentsValue.Name = "lblNavTransparentsValue";
            this.lblNavTransparentsValue.Size = new System.Drawing.Size(34, 13);
            this.lblNavTransparentsValue.TabIndex = 1;
            this.lblNavTransparentsValue.Text = "Value";
            // 
            // lblNavTransparentsBezeichnung
            // 
            this.lblNavTransparentsBezeichnung.AutoSize = true;
            this.lblNavTransparentsBezeichnung.Location = new System.Drawing.Point(7, 20);
            this.lblNavTransparentsBezeichnung.Name = "lblNavTransparentsBezeichnung";
            this.lblNavTransparentsBezeichnung.Size = new System.Drawing.Size(66, 13);
            this.lblNavTransparentsBezeichnung.TabIndex = 0;
            this.lblNavTransparentsBezeichnung.Text = "Transparenz";
            // 
            // frmOption
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(803, 444);
            this.Controls.Add(this.gbNavigation);
            this.Controls.Add(this.gbEinstellungenFarben);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(711, 243);
            this.Name = "frmOption";
            this.Text = "CYBOP - Designer - Option";
            this.Load += new System.EventHandler(this.frmOption_Load);
            this.gbEinstellungenFarben.ResumeLayout(false);
            this.gbEinstellungenFarben.PerformLayout();
            this.gbNavigation.ResumeLayout(false);
            this.gbNavigation.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarTransparanc)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnColorBrackets;
        private System.Windows.Forms.GroupBox gbEinstellungenFarben;
        private System.Windows.Forms.RichTextBox rtfBeispiel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnColorNodeText;
        private System.Windows.Forms.Button btnColorAttributeMarkup;
        private System.Windows.Forms.Button btnColorAttributeKey;
        private System.Windows.Forms.Button btnColorAttributeValue;
        private System.Windows.Forms.Button btnSchriftart;
        private System.Windows.Forms.Button btnColorHintergrund;
        private System.Windows.Forms.Button btnColor;
        private System.Windows.Forms.GroupBox gbNavigation;
        private System.Windows.Forms.Label lblNavTransparentsBezeichnung;
        private System.Windows.Forms.Label lblNavTransparentsValue;
        private System.Windows.Forms.TrackBar trackBarTransparanc;
        private System.Windows.Forms.Button btnColorXmlKommentar;
    }
}