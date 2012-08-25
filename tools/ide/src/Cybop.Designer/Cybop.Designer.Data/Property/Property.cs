using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cybop.Designer.Data
{
    public class Property : Base
    {

        #region "Konstruktor"

        public Property() 
            : base()
        {
            this.Type = string.Empty;
            this.Definitions = new List<Definition>();
        }

        public Property(string Name) 
            : base(Name)
        {
            this.Type = string.Empty;
            this.Definitions = new List<Definition>();
        }

        public Property(string Name, string Comment)
            : base(Name, Comment)
        {
            this.Type = string.Empty;
            this.Definitions = new List<Definition>();
        }

        public Property(string Name, string Comment, string Type)
            : base(Name, Comment)
        {
            this.Type = Type;
            this.Definitions = new List<Definition>();
        }

        public Property(string Name, string Comment, string Type, List<Definition> Definitions)
            : base(Name, Comment)
        {
            this.Type = Type;
            this.Definitions = Definitions;
        }

        #endregion
        
        #region "Properties"

        public string Type { get; set; }

        public List<Definition> Definitions { get; set; }

        #endregion

    }
}
