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
        static Dictionary<Enemy, List<EnemyRoutePoint>> enemyRoutePoints = new Dictionary<Enemy, List<EnemyRoutePoint>>();
        static Enemy nowEnemy = null;
        static PictureBox crosshair;
        static Image crosshairImage = Image.FromFile("Crosshair.png");

        String enemyText;
        String shooterText;
        static int count = 0;
        bool isDrag;
        int oldX, oldY;
        public int hp;
        Image orgImage;
        Image cursoredImage;

        public Enemy(Image image, String enemyText, String shooterText, Point location)
        {
            this.Image = image;
            this.enemyText = enemyText;
            this.shooterText = shooterText;
            this.Location = location;
            this.Size = image.Size;
            this.Name = "enemy" + count;
            orgImage = new Bitmap(Image);
            cursoredImage = new Bitmap(Image);

            count++;

            this.MouseClick += enemyMouseClick;
            this.MouseDown += enemyMouseDown;
            this.MouseMove += enemyMouseMove;
            this.MouseUp += enemyMouseUp;

            Graphics g = Graphics.FromImage(cursoredImage);
            g.DrawImage(new Bitmap(crosshairImage, this.Size.Width, this.Size.Height), new Point(0, 0));

            this.hp = 10;

            enemyRoutePoints[this] = new List<EnemyRoutePoint>();
        }

        static public void activeFormInit(Panel panel)
        {
            crosshair = new PictureBox();
            //crosshair.Image = Image.FromFile("Crosshair.png");
            crosshair.Name = "crosshair";
            crosshair.Visible = true;
            panel.Controls.Add(crosshair);
        }

        static public void statusChange(Panel statusLabelPanel, Panel changePanel)
        {
            if (nowEnemy == null) return;

            foreach(Control statusControl in changePanel.Controls)
            {
                var name = statusControl.Name;
                var label = statusLabelPanel.Controls[name + "label"] as Label;
                label.Text = (statusControl as NumericUpDown).Value.ToString();

                var typ = typeof(Enemy);
                var field = typ.GetField(name);
                field.SetValue(nowEnemy, (int)((statusControl as NumericUpDown).Value));
            }
        }

        private void enemyMouseClick(object sender, MouseEventArgs e)
        {
        }
        
        private void enemyMouseDown(object sender, MouseEventArgs e)
        {
            isDrag = true;
            oldX = e.X;
            oldY = e.Y;

            if (nowEnemy != null)
            {
                nowEnemy.Image = nowEnemy.orgImage;
                var prevRoutePoints = enemyRoutePoints[nowEnemy];
                foreach (EnemyRoutePoint item in prevRoutePoints)
                {
                }
            }

            nowEnemy = sender as Enemy;

            Panel statusLabelPanel = Form1.ActiveForm.Controls["statusLabelPanel"] as Panel;
            foreach (Control statusControl in statusLabelPanel.Controls)
            {
                var name = statusControl.Name;
                var label = statusControl as Label;

                var typ = typeof(Enemy);
                var field = typ.GetField(name.Replace("Label", null));

                label.Text = field.GetValue(nowEnemy).ToString();
            }

            var nowRoutePoints = enemyRoutePoints[nowEnemy];
            foreach (EnemyRoutePoint item in nowRoutePoints)
            {
            }

            nowEnemy.Image = nowEnemy.cursoredImage;

            //crosshair.Image = new Bitmap(crosshairImage, nowEnemy.Size.W / 2, nowEnemy.Size.Height/2);
            //crosshair.Location = nowEnemy.Location;
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
