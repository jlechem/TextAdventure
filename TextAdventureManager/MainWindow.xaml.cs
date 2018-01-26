using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Controls;
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
            _homeViewModel.Games[0].ConfigFile = "..\\..\\..\\Debug\\config.xml";
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
        }

        private void StartGame()
        {
            SetCurrentGame();

            Process process = new Process();
            process.StartInfo.FileName = "TextAdventure.exe";
            process.StartInfo.Arguments = _homeViewModel.CurrentGame.ConfigFile;
            process.ErrorDataReceived += Process_ErrorDataReceived;
            process.Exited += Process_Exited;
            //process.Start();
        }

        private void Process_Exited(object sender, EventArgs e)
        {
        }

        private void Process_ErrorDataReceived(object sender, DataReceivedEventArgs e)
        {
        }

    }
}