using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cybop.Designer.Data.DataProvider
{
    public static class DataProviderFactory
    {
        public static Interface.IDataProvider GetProviderInstance(string DataProviderName)
        {
            switch (DataProviderName)
            {
                case "XmlDataProvider":
                    return new XmlDataProvider();

                default:
                    return new XmlDataProvider();

            }


        }
    }
}
