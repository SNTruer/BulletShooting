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
    public partial class Form1 : Form
    {
        ArrayList enemyKindList;
        ImageList enemyImageList, shooterImageList;
        List<Image> originalEnemyImageList;

        public Form1()
        {
            InitializeComponent();
            init();
        }

        private void init()
        {
            stagePanel.AutoScroll = true;
            enemyKindList = new ArrayList();
            enemyImageList = new ImageList();
            originalEnemyImageList = new List<Image>();
            enemyList.View = View.LargeIcon;

            Image image;

            image = new Bitmap(Image.FromFile("HelloWorld.png"), 30, 30);
            enemyImageList.Images.Add(image);
            originalEnemyImageList.Add(image);
            enemyList.LargeImageList = enemyImageList;

            shooterImageList = new ImageList();

            initEnemy();
            initShooter();
            Enemy.activeFormInit(enemyPanel);
        }

        private void initEnemy()
        {
            enemyList.MultiSelect = false;

            ListViewItem item;
            item = new ListViewItem();
            item.ImageIndex = 0;
            item.Text = "TEST_ENEMY";
            enemyList.Items.Add(item);
        }

        private void initShooter()
        {
            shooterList.MultiSelect = false;

            ListViewItem item;
            item = new ListViewItem();
            item.ImageIndex = 0;
            item.Text = "TEST_SHOOTER";
            shooterList.Items.Add(item);
        }

        private void initRoute()
        {
            ListViewItem item;
            item = new ListViewItem();
            item.ImageIndex = 0;
            item.Text = "STRAIGHT";
           // routeList.Items.Add(item);
        }

        private void enemyAddButton_Click(object sender, EventArgs e)
        {
            if (!(enemyList.SelectedItems.Count > 0 && shooterList.SelectedItems.Count > 0)) return;

            ListViewItem enemyItem = enemyList.SelectedItems[0];
            ListViewItem shooterItem = shooterList.SelectedItems[0];

            Enemy enemy = new Enemy(originalEnemyImageList[enemyItem.ImageIndex], enemyItem.Text, shooterItem.Text, new Point(100,100));

            enemyPanel.Controls.Add(enemy);   
        }

        private void enemyPanel_Paint(object sender, PaintEventArgs e)
        {
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void statusChangeButton_Click(object sender, EventArgs e)
        {
            Enemy.statusChange(statusLabelPanel, changePanel);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
