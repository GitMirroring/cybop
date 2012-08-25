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
    public partial class frmComment : Form
    {

        #region "Konstruktor"

        public frmComment()
        {
            InitializeComponent();
        }

        #endregion

        #region "Events"

        private void btnSpeichern_Click(object sender, EventArgs e)
        {
            if (richTextBoxComment.Text != Properties.Settings.Default.CommentBlock)
            {
                Properties.Settings.Default.CommentBlock = richTextBoxComment.Text;
                Properties.Settings.Default.Save();
            }

            this.Close();

        }

        private void btnAbbrechen_Click(object sender, EventArgs e)
        {
            richTextBoxComment.Text = Properties.Settings.Default.CommentBlock;
            this.Close();
        }

        private void frmComment_Load(object sender, EventArgs e)
        {
            richTextBoxComment.Text = Properties.Settings.Default.CommentBlock;
        }

        private void frmComment_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (richTextBoxComment.Text != Properties.Settings.Default.CommentBlock)
            {
                switch (MessageBox.Show("Möchten Sie die Änderung Speichern?", this.Text, MessageBoxButtons.YesNoCancel, MessageBoxIcon.Question))
	            {
                    case DialogResult.Cancel:
                        e.Cancel = true;
                        break;
                    case DialogResult.No:
                        break;
                    case DialogResult.Yes:
                        Properties.Settings.Default.CommentBlock = richTextBoxComment.Text;
                        Properties.Settings.Default.Save();
                        break;
                    default:
                        break;
	            }
            }
        }

        private void richTextBoxComment_TextChanged(object sender, EventArgs e)
        {
            IntellisenseEditor.EditorTextbox.HighLight(Properties.Settings.Default.XmlBrackets,
                                                        Properties.Settings.Default.XmlAttributeValue,
                                                        Properties.Settings.Default.XmlAttributeKey,
                                                        Properties.Settings.Default.XmlAttributeMarkup,
                                                        Properties.Settings.Default.XmlTagContent,
                                                        Properties.Settings.Default.XmlKommentar,
                                                        ref this.richTextBoxComment);
        }

        #endregion

    }
}
