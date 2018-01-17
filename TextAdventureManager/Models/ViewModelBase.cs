using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace TextAdventureManager.Models
{
    public class ViewModelBase
    {
        #region Fields

        private ICommand _command;

        private bool _canExecute;

        #endregion

        #region Properties

        public bool CanExecute
        {
            get { return _canExecute; }
            set { _canExecute = value; }
        }

        public ICommand Command
        {
            get { return _command; }
            set { _command = value; }
        }

        #endregion

        public ViewModelBase()
        {
            _canExecute = true;
        }

    }
}