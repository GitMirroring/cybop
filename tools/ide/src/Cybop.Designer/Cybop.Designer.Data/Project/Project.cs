using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cybop.Designer.Data
{
    public class Project
    {

        #region "Konstruktor"

        public Project()
        {
            this._Name = string.Empty;
            this._FilePath = string.Empty;
            this._FilePath = string.Empty;
            this._FolderPath = string.Empty;
            this._IsDirty = false;
            this.Elements = new ElementCollection();
        }

        #endregion

        #region "Properties"

        private string _Name;
        public string Name { 
            get { 
                return _Name; 
            } 
            set {
                if (_Name != value)
                {
                    _Name = value;
                    this._IsDirty = true;
                }
            } 
        }

        private string _FileName;
        public string FileName {
            get
            {
                return _FileName;
            }
            set
            {
                if (_FileName != value)
                {
                    _FileName = value;
                    this._IsDirty = true;
                }
            }
        }

        private string _FilePath;
        public string FilePath {
            get {
                return _FilePath;
            }
            set {
                if (_FilePath != value)
                {
                    _FilePath = value;
                    this._IsDirty = true;
                }
            }
        }

        private string _FolderPath;
        public string FolderPath {
            get
            {
                return _FolderPath;
            }
            set
            {
                if (_FolderPath != value)
                {
                    _FolderPath = value;
                    this._IsDirty = true;
                }
            }
        }

        public ElementCollection Elements { get; set; }

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

        #endregion

        #region "Funktionen"

        /// <summary>
        /// Lädt die Daten des Objekts.
        /// </summary>
        /// <param name="Path"></param>
        public void Load(string Path)
        {
            System.IO.FileInfo file = new System.IO.FileInfo(Path);

            if (file.Exists)
            {
            
                System.Xml.Serialization.XmlSerializer Serializer = new System.Xml.Serialization.XmlSerializer(typeof(Project));
                Project newProject = null;
                newProject = (Project) Serializer.Deserialize(file.Open(System.IO.FileMode.Open));

                if (newProject != null)
                {
                    this._FileName = newProject.FileName;
                    this._FilePath = newProject.FilePath;
                    this._Name = newProject.Name;
                    this.Elements = newProject.Elements;

                    if (this._FilePath != Path)
                    {
                        string OldFolderPath = this.FolderPath;
                        this._FileName = file.Name;
                        this._FilePath = file.FullName;
                        this._FolderPath = file.DirectoryName;

                        Util.SetElementsNewPath(this.Elements, OldFolderPath, this._FolderPath);

                    }

                }

                LoadElements();

            }
        }

        /// <summary>
        /// Lädt die Elemente des Objekts.
        /// </summary>
        private void LoadElements()
        {

            int Index = 1;

            foreach (Element item in Elements)
            {
                item.Load(Index);
                Index += 1;
            }
        }

        /// <summary>
        /// Speichert das Objekt.
        /// </summary>
        public void Save()
        {

            if (string.IsNullOrEmpty(_FilePath))
            {
                throw new Exception("Bitte geben Sie einen Speicherpfad an.");
            }

            System.IO.FileInfo File = new System.IO.FileInfo(_FilePath);

            if (File.Exists)
            {
                File.Delete();
                File.Refresh();
            }

            _FolderPath = File.DirectoryName;

            Util.SetElementsPath(this.Elements, _FolderPath);

            System.Xml.Serialization.XmlSerializer Serializer = new System.Xml.Serialization.XmlSerializer(typeof(Project));

            System.IO.TextWriter Writer = new System.IO.StreamWriter(File.FullName);
            Serializer.Serialize(Writer, this);

            Writer.Close();

            SaveElements();

        }

        /// <summary>
        /// Sepichert die untergeordneten Elemente.
        /// </summary>
        private void SaveElements()
        {

            foreach (Element item in this.Elements)
            {
                if (item.IsDirty)
                {
                    item.Save();
                }
            }

        }

        public static Element GetElementByID(ElementCollection elements, int ID)
        {

            Element result = null;

            foreach (Element item in elements)
            {
                if (item.ID == ID)
                {
                    result = item;
                    return result;
                }
                else
                {
                    if (item.Elements.Count > 0)
                    {
                        result = GetElementByID(item.Elements, ID);
                        if (result != null)
                        {
                            return result;
                        }
                    }
                }
            }

            return result;

        }

        #endregion

    }
}
