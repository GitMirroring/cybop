using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cybop.Designer.Data
{
    [Serializable]
    public class Element
    {

        #region "Konstanten"

        public const string Folder = "Folder";
        public const string File = "File";

        #endregion

        #region "Konstruktor"

        public Element(string Type, int ID)
        {
            _Name = string.Empty;
            this._IsDirty = false;
            this.Type = Type;
            this.ID = ID;
            _Elements = new ElementCollection();
            _Content = new object();
            this.IsOpen = false;
        }

        protected Element()
        {
            _Name = string.Empty;
            this._IsDirty = false;
            this.Type = string.Empty;
            this.ID = 0;
            _Elements = new ElementCollection();
            _Content = new object();
        }

        #endregion

        #region "Properties"

        [System.Xml.Serialization.XmlIgnore]
        public int ID { get; protected set; }

        private string _Name;
        public string Name {
            get
            {
                return _Name;
            }
            set
            {
                if (_Name != value)
                {
                    _Name = value;
                    this._IsDirty = true;
                }
            }
        }

        public string Type { get; set; }

        public string FilePath { get; set; }

        public string FolderPath { get; set; }

        private ElementCollection _Elements;
        public ElementCollection Elements
        {
            get
            {
                return _Elements;
            }
            set
            {
                if (_Elements != value)
                {
                    _Elements = value;
                    this._IsDirty = true;
                }
            }
        }

        private bool _IsDirty;
        [System.Xml.Serialization.XmlIgnore]
        public bool IsDirty {
            get
            {
                if (this._IsDirty || this.Elements.IsDirty)
                {
                    return true;
                }

                return false;
            }
            private set
            {
                this._IsDirty = value;
            }
        }

        [System.Xml.Serialization.XmlIgnore]
        public bool IsOpen { get; set; }

        private object _Content;
        [System.Xml.Serialization.XmlIgnore]
        public object Content {
            get
            {
                return _Content;
            }
            set
            {
                if (_Content != value)
                {
                    _Content = value;
                    this._IsDirty = true;
                }
            }
        }

        #endregion

        #region "Funktionen"

        /// <summary>
        /// Lädt die Inhalte des Objekts.
        /// </summary>
        public void Load(int ID)
        {
            this.ID = ID;

            if (this.Type == File)
            {
                System.IO.FileInfo file = new System.IO.FileInfo(this.FilePath);

                if (file.Exists)
                {
                    System.IO.StreamReader myFile = new System.IO.StreamReader(file.FullName, System.Text.Encoding.Default);
                    this._Content = myFile.ReadToEnd();
                    myFile.Close();
                }
                
            }

            if (this.Elements.Count > 0)
            {
                int Index = 1;

                foreach (Element item in this.Elements)
                {
                    item.Load(Index);
                    Index += 1;
                }
            }

            this._IsDirty = false;

        }

        /// <summary>
        /// Speichert das Objekt ab.
        /// </summary>
        public void Save()
        {

            if (this.Type == Element.File)
            {
                System.IO.FileInfo file = new System.IO.FileInfo(this.FilePath);

                if (file.Exists)
                {
                    file.Delete();
                    file.Refresh();
                }

                if (this.Content.GetType() == typeof(string))
                {
                    System.IO.TextWriter Writer = new System.IO.StreamWriter(file.FullName);
                    Writer.Write(this.Content);
                    Writer.Close();
                }
                else
                {
                    System.IO.FileStream fs = new System.IO.FileStream(file.FullName, System.IO.FileMode.Create);

                    // Construct a BinaryFormatter and use it to serialize the data to the stream.
                    System.Runtime.Serialization.Formatters.Binary.BinaryFormatter formatter = new System.Runtime.Serialization.Formatters.Binary.BinaryFormatter();
                    formatter.Serialize(fs, this.Content);
                }

            }

            if (this.Type == Element.Folder)
            {
                System.IO.DirectoryInfo directory = new System.IO.DirectoryInfo(this.FilePath);
                if (!directory.Exists)
                {
                    directory.Create();
                }
            }

            if (this.Elements.Count > 0)
            {
                foreach (Element item in this.Elements)
                {
                    item.Save();
                }
            }

            this._IsDirty = false;

            GC.Collect();

        }

        /// <summary>
        /// Löscht das Objekt.
        /// </summary>
        public void Delete()
        {

            foreach (Element item in this.Elements)
            {
                item.Delete();
            }

            if (!string.IsNullOrEmpty(this.FilePath))
	        {
		        if (this.Type == File)
                {
                    System.IO.FileInfo file = new System.IO.FileInfo(this.FilePath);
                    if (file.Exists)
	                {
		                file.Delete();
                        file.Refresh();
	                }
                }

                if (this.Type == Folder)
	            {  
		            System.IO.DirectoryInfo directory = new System.IO.DirectoryInfo(this.FilePath);
                    if (directory.Exists)
	                {
		                directory.Delete(true);
                        directory.Refresh();
	                }
	            }
	        }
        }

        /// <summary>
        /// Aufgerufen wenn Element verschoben wird.
        /// </summary>
        /// <param name="ParentElement"></param>
        /// <param name="OldElement"></param>
        public void ChangeLocation(Element OldElement)
        {

            if (!string.IsNullOrEmpty(OldElement.FilePath))
            {
                if (this.Type == File)
                {
                    System.IO.FileInfo file = new System.IO.FileInfo(OldElement.FilePath);
                    if (file.Exists)
                    {
                        file.Delete();
                        file.Refresh();
                    }
                }

                if (this.Type == Folder)
                {

                    if (OldElement.Elements.Count > 0)
                    {
                        foreach (Element item in OldElement.Elements)
                        {
                            item.Delete();
                        }
                    }

                    ResetElement(this.Elements);

                    System.IO.DirectoryInfo directory = new System.IO.DirectoryInfo(OldElement.FilePath);
                    if (directory.Exists)
                    {
                        directory.Delete(true);
                        directory.Refresh();
                    }
                }
            }

            this._IsDirty = true;

        }

        /// <summary>
        /// Setzt die Pfade zurück.
        /// </summary>
        /// <param name="Elements"></param>
        public void ResetElement(ElementCollection Elements)
        {
            foreach (Element item in Elements)
            {
                item.FilePath = string.Empty;
                item.FolderPath = string.Empty;

                if (item.Elements.Count > 0)
                {
                    item.ResetElement(Elements);
                }

            }
        }

        /// <summary>
        /// Kopiert das Objekt.
        /// </summary>
        /// <param name="ParentElement"></param>
        /// <param name="OldElement"></param>
        public void Copy(Element ParentElement, Element OldElement)
        {

        }

        #endregion
        
    }
}
