using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;

namespace TextAdventureManager.Models
{
    [Serializable]
    internal class GameViewModel: ViewModelBase
    {
        #region Fields

        private long _id;

        private string _name;

        private string _description;

        private string _configFile;

        private bool _isEnabled;

        #endregion

        #region Properties

        /// <summary>
        /// Gets or sets the Id.
        /// </summary>
        public long Id
        {
            get { return _id; }
            set
            {
                if (value != _id)
                {
                    _id = value;
                    OnPropertyChanged();
                }
            }
        }

        /// <summary>
        /// Gets or sets the Name.
        /// </summary>
        public string Name
        {
            get { return _name; }
            set
            {
                if (value != _name)
                {
                    _name = value;
                    OnPropertyChanged();
                }
            }
        }

        /// <summary>
        /// Gets or sets the Description.
        /// </summary>
        public string Description
        {
            get { return _description; }
            set
            {
                if (value != _description)
                {
                    _description = value;
                    OnPropertyChanged();
                }
            }
        }

        /// <summary>
        /// Gets or sets Enabled.
        /// </summary>
        public bool Enabled
        {
            get { return _isEnabled; }
            set
            {
                if (value != _isEnabled)
                {
                    _isEnabled = value;
                    OnPropertyChanged();
                }
            }
        }
        
        /// <summary>
        /// Gets or sets the Configuration File.
        /// </summary>
        public string ConfigFile
        {
            get { return _configFile; }
            set
            {
                if (value != _configFile)
                {
                    _configFile = value;
                    OnPropertyChanged();
                }
            }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool IsValidGame
        {
            get
            {
                return  Name.Trim().Length > 0 &&
                        Description.Trim().Length > 0 &&
                        ConfigFile.Trim().Length > 0;
            }
        }

        #endregion

        /// <summary>
        /// 
        /// </summary>
        public GameViewModel()
        {
            CanExecute = true;
        }

        // COMMANDS
        public ICommand LoadConfigClickCommand
        {
            get { return new CommandHandler(() => LoadConfigClick(), CanExecute); }
        }

        private void SaveGameCommand()
        {

        }

        private void ResetGameCommand()
        {

        }

        private void RunGameCommand()
        {

        }

        private void LoadConfigClick()
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.CheckFileExists = true;
            openFileDialog.CheckPathExists = true;
            openFileDialog.DefaultExt = "xml";
            openFileDialog.Filter = "XML files (*.xml)|*.xml|All files (*.*)|*.*";
            openFileDialog.Multiselect = false;
            openFileDialog.Title = "Select XML configuration file";

            var result = openFileDialog.ShowDialog();

            if (result.HasValue && result.Value)
            {
                // validate we got an XML file
                if (openFileDialog.FileName.EndsWith(".xml"))
                {
                    // set it to our property
                    this.ConfigFile = openFileDialog.FileName;
                }
                else
                {
                    MessageBox.Show("Please select an XML file", "Invalid Configuration File", MessageBoxButton.OK, MessageBoxImage.Error);
                }
            }
        }


    }
}