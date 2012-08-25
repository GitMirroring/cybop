using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cybop.Designer.Data
{
    class Util
    {
                
        /// <summary>
        /// Prüft ob das Attribute im Knoten enthalten ist.
        /// </summary>
        /// <param name="Node"></param>
        /// <param name="AttributeName"></param>
        /// <returns></returns>
        public static bool ContainsAttribute(System.Xml.XmlNode Node, string AttributeName)
        {

            if (Node.Attributes.Count > 0)
            {

                for (int index = 0; index <= Node.Attributes.Count - 1; index++)
                {
                    System.Xml.XmlAttribute XmlAttribute = null;

                    XmlAttribute = Node.Attributes[index];

                    if (XmlAttribute != null)
                    {
                        if (XmlAttribute.Name == AttributeName)
                        {
                            return true;
                        }
                    }

                }

            }

            return false;

        }

        /// <summary>
        /// Setzt den Relativen Pfad zur Projekt Datei.
        /// </summary>
        public static void SetElementsPath(ElementCollection Elements, string RootFolderPath)
        {
            foreach (Element item in Elements)
            {
                switch (item.Type)
                {
                    case Element.File:
                        item.FolderPath = RootFolderPath;
                        item.FilePath = System.IO.Path.Combine(RootFolderPath, item.Name);
                        break;

                    case Element.Folder:
                        item.FolderPath = System.IO.Path.Combine(RootFolderPath, item.Name);
                        item.FilePath = System.IO.Path.Combine(RootFolderPath, item.Name);
                        break;
                }

                if (item.Elements.Count > 0)
                {
                    SetElementsPath(item.Elements, item.FolderPath);
                }

            }
        }

        /// <summary>
        /// Erstezt die alten Pfade durch neue.
        /// </summary>
        /// <param name="Elements"></param>
        /// <param name="OldFolderPath"></param>
        /// <param name="NewFolderPath"></param>
        public static void SetElementsNewPath(ElementCollection Elements, string OldFolderPath, string NewFolderPath)
        {

            foreach (Element item in Elements)
            {
                
                item.FolderPath = item.FolderPath.Replace(OldFolderPath, NewFolderPath);
                item.FilePath = item.FilePath.Replace(OldFolderPath, NewFolderPath);
                      
                if (item.Elements.Count > 0)
                {
                    SetElementsNewPath(item.Elements, OldFolderPath, NewFolderPath);
                }

            }

        }

    }
}
