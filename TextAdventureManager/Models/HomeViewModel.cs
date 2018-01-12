using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextAdventureManager.Models
{
    internal class HomeViewModel
    {
        public GameViewModel CurrentGame { get; set; }

        public List<GameViewModel> Games { get; }

        internal HomeViewModel()
        {
            Games = new List<GameViewModel>();
        }

        // Commands will go here

    }
}