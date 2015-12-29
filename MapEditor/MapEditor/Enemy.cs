using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;

namespace MapEditor
{
    class Enemy : PictureBox
    {
        String enemyText;
        String shooterText;
        static int count = 0;
        bool isDrag;
        int oldX, oldY;

        public Enemy(Image image, String enemyText, String shooterText, Point location)
        {
            this.Image = image;
            this.enemyText = enemyText;
            this.shooterText = shooterText;
            this.Location = location;
            this.Size = image.Size;
            this.Name = "enemy" + count;

            count++;

            this.MouseDown += enemyMouseDown;
            this.MouseMove += enemyMouseMove;
            this.MouseUp += enemyMouseUp;
        }
        
        private void enemyMouseDown(object sender, MouseEventArgs e)
        {
            isDrag = true;
            oldX = e.X;
            oldY = e.Y;
        }

        private void enemyMouseMove(object sender, MouseEventArgs e)
        {
            try {
                Enemy enemy = sender as Enemy;
                if (isDrag && e.Button == MouseButtons.Left)
                {
                    enemy.Location = new Point(enemy.Location.X + e.X - oldX, enemy.Location.Y + e.Y - oldY);
                    //enemy.Top += e.Y - oldY;
                    //enemy.Left += e.X - oldX;
                }
            }
            catch(Exception ex)
            {

            }
        }

        private void enemyMouseUp(object sender, MouseEventArgs e)
        {
            isDrag = false;
        }
    }
}
