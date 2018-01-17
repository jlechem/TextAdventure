using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextAdventureManager.Models
{
    [Serializable]
    internal class GameViewModel: ViewModelBase
    {
        /// <summary>
        /// Gets or sets the Id.
        /// </summary>
        public long Id { get; set; }

        /// <summary>
        /// Gets or sets the Name.
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// Gets or sets the Description.
        /// </summary>
        public string Description { get; set; }

        /// <summary>
        /// Gets or sets Enabled.
        /// </summary>
        public bool Enabled { get; set; }
        
        /// <summary>
        /// Gets or sets the Configuration File.
        /// </summary>
        public string ConfigFile { get; set; }

        /// <summary>
        /// 
        /// </summary>
        public GameViewModel()
        {
            CanExecute = true;
        }

        // COMMANDS
        private void SaveGameCommand()
        {

        }

        private void ResetGameCommand()
        {

        }

        private void RunGameCommand()
        {

        }


    }
}