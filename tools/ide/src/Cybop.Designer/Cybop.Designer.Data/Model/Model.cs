using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cybop.Designer.Data
{
    public class Model : Base
    {

        #region "Konstruktor"

        public Model() 
            : base()
        {
            this.Attributes = new List<Attribute>();
        }

        public Model(string Name) 
            : base(Name)
        {
            this.Attributes = new List<Attribute>();
        }

        public Model(string Name, string Comment)
            :base(Name, Comment)
        {
            this.Attributes = new List<Attribute>();
        }

        public Model(string Name, string Comment, List<Attribute> Attributes)
            :base(Name, Comment)
        {
            this.Attributes = Attributes;
        }

        #endregion

        #region "Properties"

        public List<Attribute> Attributes { get; set; }

        #endregion

    }
}
