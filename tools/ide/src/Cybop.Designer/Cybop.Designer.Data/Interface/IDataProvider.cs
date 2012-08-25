using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cybop.Designer.Data.Interface
{
    public interface IDataProvider
    {

        #region "Events"
        event EventHandler LoadingElement;
        event EventHandler MaxElementsSelected;
        #endregion

        #region "Properties"
        int MaxElements { get;}
        #endregion

        #region "Funktionen"

        #region "Laden"

        List<Data.Model> Load(string FilePath);

        #endregion

        #endregion

    }
}
