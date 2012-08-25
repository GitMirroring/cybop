using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace Cybop.Designer
{
    static class Program
    {

        #region "Properties"

        public static ApplicationContext AppContext { get; private set; }

        #endregion

        #region "Funktionen"

        /// <summary>
        /// Der Haupteinstiegspunkt für die Anwendung.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            AppContext = new ApplicationContext(new Formulare.frmLoad());

            Application.Run(AppContext);
        }

        #endregion

    }
}
