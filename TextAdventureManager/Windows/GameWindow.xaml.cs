using System.Windows;
using System.Windows.Input;

namespace TextAdventureManager.Windows
{
    /// <summary>
    /// Interaction logic for GameWindow.xaml
    /// </summary>
    public partial class GameWindow : Window
    {
        private GameDetails _model;

        public GameWindow()
        {
            InitializeComponent();

            Mouse.OverrideCursor = null;

            _model = new GameDetails();
            this.DataContext = _model;

        }
    }
}