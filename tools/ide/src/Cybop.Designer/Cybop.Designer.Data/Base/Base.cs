using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cybop.Designer.Data
{
    public class Base
    {
        #region "Konstruktor"

         public Base()
        {
            this.Name = string.Empty;
            this.Comment = string.Empty;
        }

        public Base(string Name)
        {
            this.Name = Name;
            this.Comment = string.Empty;
        }

        public Base(string Name, string Comment)
        {
            this.Name = Name;
            this.Comment = Comment;
        }

        #endregion

        #region "Properties"

        public string Name { get; set; }

        public string Comment { get; set; }

        #endregion

    }
}
