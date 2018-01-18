using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace TextAdventureManager.Models
{
    public class ViewModelBase: INotifyPropertyChanged
    {
        #region Fields

        private bool _canExecute;

        public event PropertyChangedEventHandler PropertyChanged;

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


        protected virtual void OnPropertyChanged([CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

    }
}