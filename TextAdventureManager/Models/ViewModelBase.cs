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

        private bool _canExecute;

        #endregion

        #region Properties

        public bool CanExecute
        {
            get { return _canExecute; }
            set { _canExecute = value; }
        }

        #endregion

        public ViewModelBase()
        {
            _canExecute = true;
        }

    }
}