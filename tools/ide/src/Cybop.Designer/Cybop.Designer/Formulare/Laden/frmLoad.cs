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

    public delegate void intDelegate (int input);
    public delegate void closeDelegate ();

    public partial class frmLoad : Form
    {

        #region "Members"
        private bool _IsLoad;
        private int _CurrentValue;
        private System.Threading.Thread _LoadThread;
        #endregion

        #region "Konstruktor"

        public frmLoad()
        {
            InitializeComponent();
            _IsLoad = false;
            _CurrentValue = 0;
            
        }

        #endregion

        #region "Events"

        private void frmLoad_Shown(object sender, EventArgs e)
        {
            StartBackgroundWorker();
        }

        private void frmLoad_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (_IsLoad)
            {
                frmMain frmMain = new frmMain();
                Program.AppContext.MainForm = frmMain;
                frmMain.Show();
            }
            else
            {
                Application.Exit();
            }

            _LoadThread = null;

        }

        #endregion

        #region "Funktionen"

        private void StartBackgroundWorker()
        {
            _LoadThread = new System.Threading.Thread(new System.Threading.ThreadStart(LoadMain));
            _LoadThread.Start();
        }

        public void SetProgressBarValue(int value)
        {
            this.progressBarCybopDesigner.Value = value;
        }

        public void SetProgressBarMaxValue(int value)
        {
            this.progressBarCybopDesigner.Maximum = value;
        }

        /// <summary>
        /// Lädt die Daten für das Main-Objekt.
        /// </summary>
        private void LoadMain()
        {

            try
            {

                Data.Interface.IDataProvider dataProvider = Data.DataProvider.DataProviderFactory.GetProviderInstance("XmlDataProvider");
                dataProvider.LoadingElement += new EventHandler(dataProvider_LoadingElement);
                dataProvider.MaxElementsSelected += new EventHandler(dataProvider_MaxElementsSelected);
                Main.Models = dataProvider.Load("Data/api_xml_definition.xml");

                _IsLoad = true;

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, this.Text, MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }

            Invoke(new MethodInvoker(Close));
                        
        }

        void dataProvider_MaxElementsSelected(object sender, EventArgs e)
        {   

            Data.Interface.IDataProvider dataProvider = sender as Data.Interface.IDataProvider;
            Invoke(new intDelegate(SetProgressBarMaxValue), dataProvider.MaxElements);

        }

        void dataProvider_LoadingElement(object sender, EventArgs e)
        {
            _CurrentValue += 1;
            Invoke(new intDelegate(SetProgressBarValue), _CurrentValue);
        }

       
        #region "Allgemein"

        /// <summary>
        /// Initialisiert die Steuerelemente auf dem Formular.
        /// </summary>
        private void InitializeControls()
        {
            this.progressBarCybopDesigner.Maximum = 100;
        }

        #endregion

        #endregion

    }
}
