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
    public partial class frmNew : Form
    {

        #region "Members"
        private Data.Project _Project;
        #endregion

        #region "Konstruktor"

        public frmNew(ref Data.Project Project)
        {
            InitializeComponent();

            if (Project == null)
            {
                _Project = new Data.Project();
            }
            else
            {
                _Project = Project;
            }
        }

        #endregion

        #region "Events"

        private void frmNew_Shown(object sender, EventArgs e)
        {
            this.txtProjektname.Focus();
        }

        private void btnAnlegen_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(txtProjektname.Text))
            {
                MessageBox.Show("Bitte geben Sie einen Projektnamen an.", this.Text, MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                _Project.Name = txtProjektname.Text;
                this.DialogResult = System.Windows.Forms.DialogResult.OK;
                this.Close();
            }
        }

        private void btnAbbrechen_Click(object sender, EventArgs e)
        {
            _Project.Name = string.Empty;
            this.DialogResult = System.Windows.Forms.DialogResult.Abort;
            this.Close();
        }

        #endregion    

    }
}
