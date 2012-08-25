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
    public partial class frmOption : Form
    {

        #region "Konstruktor"

        public frmOption()
        {
            InitializeComponent();
        }
        
        #endregion

        #region "Events"
        
        private void frmOption_Load(object sender, EventArgs e)
        {
            LoadAll();
        }

        private void btnColorBrackets_Click(object sender, EventArgs e)
        {
            SelectColor(btnColorBrackets.Name);
        }

        private void btnColorAttributeValue_Click(object sender, EventArgs e)
        {
            SelectColor(btnColorAttributeValue.Name);
        }

        private void btnColorAttributeKey_Click(object sender, EventArgs e)
        {
            SelectColor(btnColorAttributeKey.Name);
        }

        private void btnColorAttributeMarkup_Click(object sender, EventArgs e)
        {
            SelectColor(btnColorAttributeMarkup.Name);
        }

        private void btnColorNodeText_Click(object sender, EventArgs e)
        {
            SelectColor(btnColorNodeText.Name);
        }

        private void btnColor_Click(object sender, EventArgs e)
        {
            SelectColor(btnColor.Name);
        }

        private void btnColorHintergrund_Click(object sender, EventArgs e)
        {
            SelectColor(btnColorHintergrund.Name);
        }

        private void btnSchriftart_Click(object sender, EventArgs e)
        {
            SelectFont(btnSchriftart.Name);
        }

        private void trackBarTransparanc_Scroll(object sender, EventArgs e)
        {
            int newValue = trackBarTransparanc.Value;
            if (newValue == 0)
            {
                newValue = 10;
            }
            Properties.Settings.Default.Transparency = newValue;
            lblNavTransparentsValue.Text = newValue.ToString();
            Properties.Settings.Default.Save();
        }

        #endregion

        #region "Funktion"

        #region "Laden"

        private void LoadAll()
        {
            LoadFont();
            LoadColor();
            LoadTransparency();
        }

        private void LoadColor()
        {
            IntellisenseEditor.EditorTextbox.HighLight(Properties.Settings.Default.XmlBrackets,
                                                        Properties.Settings.Default.XmlAttributeValue,
                                                        Properties.Settings.Default.XmlAttributeKey,
                                                        Properties.Settings.Default.XmlAttributeMarkup,
                                                        Properties.Settings.Default.XmlTagContent,
                                                        Properties.Settings.Default.XmlKommentar,
                                                        ref rtfBeispiel);
            rtfBeispiel.BackColor = Properties.Settings.Default.Hintergrundfarbe;
        }

        private void LoadTransparency()
        {
            lblNavTransparentsValue.Text = Properties.Settings.Default.Transparency.ToString();
            trackBarTransparanc.Value = Properties.Settings.Default.Transparency;
        }

        private void LoadFont()
        {
            rtfBeispiel.Font = Properties.Settings.Default.Schriftart;
        }

        #endregion

        #region "Color"

        private void SelectColor(string ButtonName)
        {

            ColorDialog colorChoos = new ColorDialog();
            colorChoos.AllowFullOpen = true;
            colorChoos.AnyColor = true;
            colorChoos.Color = GetColorFromButtonName(ButtonName);
            colorChoos.SolidColorOnly = true;

            if (colorChoos.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                SetColorFromButtonName(ButtonName, colorChoos.Color);
                LoadColor();
            }

        }

        private System.Drawing.Color GetColorFromButtonName(string ButtonName)
        {

            System.Drawing.Color saveColor = Color.Black;

            switch (ButtonName)
            {
                case "btnColor":
                    saveColor = Properties.Settings.Default.Schriftfarbe;
                    break;
                case "btnColorAttributeKey":
                    saveColor = Properties.Settings.Default.XmlAttributeKey;
                    break;

                case "btnColorAttributeMarkup":
                    saveColor = Properties.Settings.Default.XmlAttributeMarkup;
                    break;

                case "btnColorAttributeValue":
                    saveColor = Properties.Settings.Default.XmlAttributeValue;
                    break;

                case "btnColorBrackets":
                    saveColor = Properties.Settings.Default.XmlBrackets;
                    break;

                case "btnColorHintergrund":
                    saveColor = Properties.Settings.Default.Hintergrundfarbe;
                    break;

                case "btnColorNodeText":
                    saveColor = Properties.Settings.Default.XmlTagContent;
                    break;
				
                case "btnColorXmlKommentar":
                    saveColor = Properties.Settings.Default.XmlKommentar;
                    break;
				
            }

            return saveColor;

        }

        private void SetColorFromButtonName(string ButtonName, System.Drawing.Color saveColor)
        {

            switch (ButtonName)
            {
                case "btnColor":
                    Properties.Settings.Default.Schriftfarbe = saveColor;
                    break;
                case "btnColorAttributeKey":
                    Properties.Settings.Default.XmlAttributeKey = saveColor;
                    break;

                case "btnColorAttributeMarkup":
                    Properties.Settings.Default.XmlAttributeMarkup = saveColor;
                    break;

                case "btnColorAttributeValue":
                    Properties.Settings.Default.XmlAttributeValue = saveColor;
                    break;

                case "btnColorBrackets":
                    Properties.Settings.Default.XmlBrackets = saveColor;
                    break;

                case "btnColorHintergrund":
                    Properties.Settings.Default.Hintergrundfarbe = saveColor;
                    break;

                case "btnColorNodeText":
                    Properties.Settings.Default.XmlTagContent = saveColor;
                    break;
                case "btnColorXmlKommentar":
                    Properties.Settings.Default.XmlKommentar = saveColor;
                    break;
            }

            try
            {
                Properties.Settings.Default.Save();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }

        }

		#endregion

        #region "Schriftart"

        private void SelectFont(string ButtonName)
        {

            FontDialog fontDialog = new FontDialog();
            fontDialog.FontMustExist = true;
            fontDialog.ShowApply = false;
            fontDialog.ShowColor = false;
            fontDialog.ShowEffects = false;
            fontDialog.Font = Properties.Settings.Default.Schriftart;

            if (fontDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
	        {
		          if (ButtonName == btnSchriftart.Name)
                  {
                        Properties.Settings.Default.Schriftart = fontDialog.Font;
                        try 
	                    {	        
		                    Properties.Settings.Default.Save();
                            LoadAll();
	                    }
	                    catch (Exception ex)
	                    {
		                    MessageBox.Show(ex.Message, this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
	                    }
                  }
	        }

           
        }

        #endregion

        private void btnColorXmlKommentar_Click(object sender, EventArgs e)
        {
            SelectColor(btnColorXmlKommentar.Name);
        }

        #endregion      

    }
}
