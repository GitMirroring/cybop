using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cybop.Designer.Data.DataProvider
{
    public class XmlDataProvider : Interface.IDataProvider
    {

        #region "Funktion"

        /// <summary>
        /// Load the information Form XML-File.
        /// </summary>
        /// <param name="FilePath"></param>
        /// <returns></returns>
        public List<Model> Load(string FilePath)
        {

            List<Model> Models = new List<Model>();

            System.Xml.XmlDocument xmlDocument = new System.Xml.XmlDocument();
            xmlDocument.Load(FilePath);

            System.Xml.XmlNodeList ModelNodes = xmlDocument.GetElementsByTagName("model");

            if (ModelNodes.Count == 0)
            {
                //ToDo Übersetzten.
                throw new Exception("Es wurden keine entsprechenden model-Elemente in der XML-Datei gefunden.");
            }
            else
            {
                _MaxElements = ModelNodes.Count;
                MaxElementsSelected(this, new EventArgs());

                foreach (System.Xml.XmlNode item in ModelNodes)
                {

                    if (Util.ContainsAttribute(item, "name"))
                    {

                        string Name = item.Attributes["name"].Value.Trim();
                        string Comment = string.Empty;

                        if (Util.ContainsAttribute(item, "comment"))
                        {
                            Comment = item.Attributes["comment"].Value.Trim();
                        }

                        Model newModel = new Model(Name, Comment);
                        Models.Add(newModel);

                        if (item.HasChildNodes)
                        {
                            foreach (System.Xml.XmlNode itemAttribute in item.ChildNodes)
                            {
                                if (itemAttribute.Name == "attribute")
                                {
                                    if (Util.ContainsAttribute(itemAttribute, "name"))
                                    {

                                        string NameAttribute = itemAttribute.Attributes["name"].Value.Trim();
                                        string CommentAttribute = string.Empty;
                                        bool Disabled = false;

                                        if (Util.ContainsAttribute(itemAttribute, "comment"))
                                        {
                                            CommentAttribute = itemAttribute.Attributes["comment"].Value.Trim();
                                        }

                                        if (Util.ContainsAttribute(itemAttribute, "disabled"))
                                        {
                                            Disabled = System.Convert.ToBoolean(itemAttribute.Attributes["disabled"].Value.Trim());
                                        }

                                        Attribute newAttribute = new Attribute(NameAttribute, CommentAttribute, Disabled);
                                        newModel.Attributes.Add(newAttribute);

                                        if (itemAttribute.HasChildNodes)
                                        {
                                            foreach (System.Xml.XmlNode itemProperty in itemAttribute.ChildNodes)
                                            {
                                                if (itemProperty.Name == "property")
                                                {
                                                    if (Util.ContainsAttribute(itemProperty, "name"))
                                                    {
                                                        string NamProperty = itemProperty.Attributes["name"].Value.Trim();
                                                        string CommentProperty = string.Empty;
                                                        string Type = string.Empty;

                                                        if (Util.ContainsAttribute(itemProperty, "comment"))
                                                        {
                                                            CommentProperty = itemProperty.Attributes["comment"].Value.Trim();
                                                        }

                                                        if (Util.ContainsAttribute(itemProperty, "type"))
                                                        {
                                                            Type = itemProperty.Attributes["type"].Value.Trim();
                                                        }

                                                        Property newProperty = new Property(NamProperty, CommentProperty, Type);
                                                        newAttribute.Properties.Add(newProperty);

                                                        if (itemProperty.HasChildNodes)
                                                        {

                                                            foreach (System.Xml.XmlNode itemDefinition in itemProperty.ChildNodes)
                                                            {

                                                                if (itemDefinition.Name == "definition")
                                                                {

                                                                    if (Util.ContainsAttribute(itemDefinition, "format"))
                                                                    {

                                                                        string Format = itemDefinition.Attributes["format"].Value.Trim();
                                                                        string Model = string.Empty;

                                                                        if (Util.ContainsAttribute(itemDefinition, "model"))
                                                                        {
                                                                            Model = itemDefinition.Attributes["model"].Value.Trim();
                                                                        }

                                                                        Definition newDefinition = new Definition(Format, Model);
                                                                        newProperty.Definitions.Add(newDefinition);

                                                                    }

                                                                }

                                                            }

                                                        }

                                                    }
                                                }
                                            }
                                        }

                                    }
                                }
                            }
                        }

                    }

                    LoadingElement(this, new EventArgs());

                }
            }

            return Models;

        }

        #endregion

        #region "Properties"

        private int _MaxElements;
        int Interface.IDataProvider.MaxElements
        {
            get
            {
                return _MaxElements;
            }
        }

        #endregion

        #region "Events"
        public event EventHandler LoadingElement;
        public event EventHandler MaxElementsSelected;
        #endregion
               
    }
}
