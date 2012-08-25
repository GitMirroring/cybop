using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cybop.Designer.Data
{
    [Serializable]
    public class ElementCollection : System.Collections.ObjectModel.Collection<Element>
    {

        #region "Properties"

        /// <summary>
        /// Prüft ob das Objekt geändert wurde.
        /// </summary>
        public bool IsDirty {
            get
            {

                foreach (Element item in this)
                {
                    if (item.IsDirty)
                    {
                        return true;
                    }
                }

                return false;

            }
        }

        #endregion

    }
}
