using System;
using System.Collections.Generic;
using System.Diagnostics;
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
            _homeViewModel.Games[0].ConfigFile = "config.xml";
        }

        private void menuAbout_Click(object sender, RoutedEventArgs e)
        {
            new AboutWindow().ShowDialog();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            // get the object behind the DataContext and set it to our current game
            GameViewModel x = (sender as Button).DataContext as GameViewModel;

            if( x != null)
            {
                _homeViewModel.CurrentGame = x;

                StartGame();

            }
        }

        private void SetCurrentGame()
        {
            // TODO: DataBinding should be handled in the XAML
            ucCurrentGame.DataContext = _homeViewModel.CurrentGame;
        }

        private void StartGame()
        {
            SetCurrentGame();

            Process process = new Process();
            process.StartInfo.FileName = "..\\..\\..\\Debug\\TextAdventure.exe";
            process.StartInfo.Arguments = _homeViewModel.CurrentGame.ConfigFile;
            process.ErrorDataReceived += Process_ErrorDataReceived;
            process.Exited += Process_Exited;
            process.Start();
        }

        private void Process_Exited(object sender, EventArgs e)
        {
        }

        private void Process_ErrorDataReceived(object sender, DataReceivedEventArgs e)
        {
        }

        private void DataGrid_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var row = (sender as DataGridRow);

            if( row != null)
            {
                var context = row.DataContext as GameViewModel;

                if( context != null)
                {
                    _homeViewModel.CurrentGame = context;

                    SetCurrentGame();
                }
            }
        }
    }
}