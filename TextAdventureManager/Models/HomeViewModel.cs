using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using TextAdventureManager.Windows;

namespace TextAdventureManager.Models
{
    internal class HomeViewModel: ViewModelBase
    {
        #region Fields

        private GameViewModel _gameViewModel;

        private List<GameViewModel> _games;

        #endregion

        #region Properties

        public GameViewModel CurrentGame
        {
            get { return _gameViewModel; }
            set
            {
                if( value != _gameViewModel)
                {
                    _gameViewModel = value;
                    OnPropertyChanged();
                }
            }
        }

        public List<GameViewModel> Games { get; }

        #endregion

        internal HomeViewModel()
        {
            Games = new List<GameViewModel>();
            CurrentGame = new GameViewModel();
            CanExecute = true;
        }

        // Commands will go here
        public ICommand AboutClickCommand
        {
            get
            {
                return new CommandHandler(() => AboutClick(), CanExecute);
            }
        }

        public ICommand ExitClickCommand
        {
            get
            {
                return new CommandHandler(() => ExitClick(), CanExecute);
            }
        }

        private void AboutClick()
        {
            new AboutWindow().ShowDialog();
        }

        private void ExitClick()
        {
            if( MessageBox.Show("Are you sure you want to exit?","Exit Game Manager?",
                MessageBoxButton.YesNoCancel,MessageBoxImage.Question) == MessageBoxResult.Yes)
            {
                App.Current.Shutdown(0);
            }
        }
    }
}