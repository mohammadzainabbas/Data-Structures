using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QuizTesting
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        int x = 100;
        int y = 100;
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.FillRectangle((Brushes.Blue), x, y, 100, 100);
     
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyData == Keys.Right)
            {
                x = x + 5;

                
        }
    }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Invalidate();
        }
}
