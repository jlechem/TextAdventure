using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using TextAdventureManager.Models;
using TextAdventureManager.Windows;

namespace TextAdventureManager
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        HomeViewModel _homeViewModel = new HomeViewModel();

        public MainWindow()
        {
            InitializeComponent();

            this.LoadGames();

            this.DataContext = _homeViewModel;

        }

        private void LoadGames()
        {
            // TODO: read the games data from the XML file
            _homeViewModel.Games.Add(new GameViewModel { Id = 1, Name = "Justins Text", Description = "Justins Adventure Game", Enabled = true });
        }

        private void menuAbout_Click(object sender, RoutedEventArgs e)
        {
            new AboutWindow().ShowDialog();
        }
    }
}