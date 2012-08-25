using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cybop.Designer.Data
{
    public class Attribute : Base
    {

        #region "Konstruktor"

        public Attribute() 
            : base()
        {
            
            this.Disabled = false;
            this.Properties = new List<Property>();
        }

        public Attribute(string Name)
            :base(Name)
           
        {
            this.Disabled = false;
            this.Properties = new List<Property>();
        }

        public Attribute(string Name, string Comment)
            : base(Name, Comment)
        {
            this.Disabled = false;
            this.Properties = new List<Property>();
        }

        public Attribute(string Name, string Comment, bool Disabled)
            : base(Name, Comment)
        {
            this.Disabled = Disabled;
            this.Properties = new List<Property>();
        }

        public Attribute(string Name, string Comment, bool Disabled, List<Property> Properties)
            : base(Name, Comment)
        {
            this.Disabled = Disabled;
            this.Properties = Properties;
        }

        #endregion

        #region "Properties"

        public bool Disabled { get; set; }

        public List<Property> Properties { get; set; }

        #endregion

    }
}
