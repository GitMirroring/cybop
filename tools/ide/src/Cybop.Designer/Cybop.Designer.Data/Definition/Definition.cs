using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cybop.Designer.Data
{
    public class Definition
    {

        #region "Konstruktor"

        public Definition()
        {
            this.Format = string.Empty;
            this.Model = string.Empty;
        }

        public Definition(string Format)
        {
            this.Format = Format;
            this.Model = string.Empty;
        }

        public Definition(string Format, string Model)
        {
            this.Format = Format;
            this.Model = Model;
        }
        
        #endregion

        #region "Properties"

        public string Format { get; set; }

        public string Model { get; set; }

        #endregion

    }
}
