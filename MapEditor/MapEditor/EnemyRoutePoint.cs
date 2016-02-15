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
    class EnemyRoutePoint : PictureBox
    {
        static Image crosshairImage = Image.FromFile("BlackCrosshair.png");
        static int count;
        static EnemyRoutePoint nowRoutePoint = null;

        Enemy parent;
        Image orgImage, cursoredImage;

        public EnemyRoutePoint(Enemy parent)
        {
            this.parent = parent;
            Image image = new Bitmap(Image.FromFile("Redpoint.png"), 30, 30);
            this.Image = image;
            this.Size = image.Size;
            this.Location = new Point(50, 50);
            this.Name = parent.Name + "routepoint" + parent.getRouteCount();
            orgImage = new Bitmap(Image);
            cursoredImage = new Bitmap(Image);

            count++;

            Graphics g = Graphics.FromImage(cursoredImage);
            g.DrawImage(new Bitmap(crosshairImage, this.Size.Width, this.Size.Height), new Point(0, 0));

            this.MouseDown += routePointMouseDown;
            this.MouseMove += routePointMouseMove;
            this.MouseUp += routePointMouseUp;
            this.MouseClick += routePointClick;
        }

        bool isDrag;
        int oldX, oldY;

        private void routePointClick(object sender, MouseEventArgs e)
        {
        }

        private void routePointMouseDown(object sender, MouseEventArgs e)
        {
            isDrag = true;
            oldX = e.X;
            oldY = e.Y;
            
            if(nowRoutePoint != null)
            {
                nowRoutePoint.Image = nowRoutePoint.orgImage;
            }

            nowRoutePoint = sender as EnemyRoutePoint;

            nowRoutePoint.Image = nowRoutePoint.cursoredImage;
        }

        private void routePointMouseMove(object sender, MouseEventArgs e)
        {
            try
            {
                EnemyRoutePoint enemyRoutePoint = sender as EnemyRoutePoint;
                if (isDrag && e.Button == MouseButtons.Left)
                {
                    enemyRoutePoint.Location = new Point(enemyRoutePoint.Location.X + e.X - oldX, enemyRoutePoint.Location.Y + e.Y - oldY);
                    //enemy.Top += e.Y - oldY;
                    //enemy.Left += e.X - oldX;
                }
            }
            catch (Exception ex)
            {

            }
        }

        private void routePointMouseUp(object sender, MouseEventArgs e)
        {
            isDrag = false;
        }
    }
}
