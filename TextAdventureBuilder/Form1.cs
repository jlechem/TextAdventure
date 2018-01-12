using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TextAdventureBuilder.MdiControls;

namespace TextAdventureBuilder
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void gameToolStripMenuItem_Click(object sender, EventArgs e)
        {
            GameForm newGame = new GameForm();
            newGame.MdiParent = this;
            newGame.Show();
        }
    }
}
