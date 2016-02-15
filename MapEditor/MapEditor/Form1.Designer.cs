namespace MapEditor
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.stagePanel = new System.Windows.Forms.Panel();
            this.enemyPanel = new System.Windows.Forms.Panel();
            this.enemyList = new System.Windows.Forms.ListView();
            this.shooterList = new System.Windows.Forms.ListView();
            this.enemyAddButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.statusLabelPanel = new System.Windows.Forms.Panel();
            this.hpLabel = new System.Windows.Forms.Label();
            this.changePanel = new System.Windows.Forms.Panel();
            this.hp = new System.Windows.Forms.NumericUpDown();
            this.statusChangeButton = new System.Windows.Forms.Button();
            this.addRouteButton = new System.Windows.Forms.Button();
            this.form1BindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.stagePanel.SuspendLayout();
            this.panel1.SuspendLayout();
            this.statusLabelPanel.SuspendLayout();
            this.changePanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.hp)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.form1BindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // stagePanel
            // 
            this.stagePanel.BackgroundImage = global::MapEditor.Properties.Resources.space;
            this.stagePanel.Controls.Add(this.enemyPanel);
            this.stagePanel.Location = new System.Drawing.Point(12, 12);
            this.stagePanel.Name = "stagePanel";
            this.stagePanel.Size = new System.Drawing.Size(620, 800);
            this.stagePanel.TabIndex = 1;
            // 
            // enemyPanel
            // 
            this.enemyPanel.BackColor = System.Drawing.Color.Transparent;
            this.enemyPanel.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.enemyPanel.Location = new System.Drawing.Point(0, 0);
            this.enemyPanel.Name = "enemyPanel";
            this.enemyPanel.Size = new System.Drawing.Size(600, 1000);
            this.enemyPanel.TabIndex = 0;
            this.enemyPanel.Paint += new System.Windows.Forms.PaintEventHandler(this.enemyPanel_Paint);
            // 
            // enemyList
            // 
            this.enemyList.HideSelection = false;
            this.enemyList.Location = new System.Drawing.Point(679, 35);
            this.enemyList.Name = "enemyList";
            this.enemyList.Size = new System.Drawing.Size(348, 377);
            this.enemyList.TabIndex = 2;
            this.enemyList.UseCompatibleStateImageBehavior = false;
            // 
            // shooterList
            // 
            this.shooterList.HideSelection = false;
            this.shooterList.Location = new System.Drawing.Point(1097, 35);
            this.shooterList.Name = "shooterList";
            this.shooterList.Size = new System.Drawing.Size(348, 377);
            this.shooterList.TabIndex = 3;
            this.shooterList.UseCompatibleStateImageBehavior = false;
            // 
            // enemyAddButton
            // 
            this.enemyAddButton.Location = new System.Drawing.Point(1322, 818);
            this.enemyAddButton.Name = "enemyAddButton";
            this.enemyAddButton.Size = new System.Drawing.Size(123, 31);
            this.enemyAddButton.TabIndex = 4;
            this.enemyAddButton.Text = "Enemy Add";
            this.enemyAddButton.UseVisualStyleBackColor = true;
            this.enemyAddButton.Click += new System.EventHandler(this.enemyAddButton_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(3, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(29, 12);
            this.label1.TabIndex = 5;
            this.label1.Text = "HP :";
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.label1);
            this.panel1.Location = new System.Drawing.Point(679, 458);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(39, 143);
            this.panel1.TabIndex = 6;
            // 
            // statusLabelPanel
            // 
            this.statusLabelPanel.Controls.Add(this.hpLabel);
            this.statusLabelPanel.Location = new System.Drawing.Point(739, 458);
            this.statusLabelPanel.Name = "statusLabelPanel";
            this.statusLabelPanel.Size = new System.Drawing.Size(52, 143);
            this.statusLabelPanel.TabIndex = 7;
            // 
            // hpLabel
            // 
            this.hpLabel.AutoSize = true;
            this.hpLabel.Location = new System.Drawing.Point(3, 35);
            this.hpLabel.Name = "hpLabel";
            this.hpLabel.Size = new System.Drawing.Size(11, 12);
            this.hpLabel.TabIndex = 6;
            this.hpLabel.Text = "0";
            // 
            // changePanel
            // 
            this.changePanel.Controls.Add(this.hp);
            this.changePanel.Location = new System.Drawing.Point(806, 458);
            this.changePanel.Name = "changePanel";
            this.changePanel.Size = new System.Drawing.Size(137, 143);
            this.changePanel.TabIndex = 8;
            // 
            // hp
            // 
            this.hp.Location = new System.Drawing.Point(3, 33);
            this.hp.Name = "hp";
            this.hp.Size = new System.Drawing.Size(120, 21);
            this.hp.TabIndex = 1;
            // 
            // statusChangeButton
            // 
            this.statusChangeButton.Location = new System.Drawing.Point(840, 627);
            this.statusChangeButton.Name = "statusChangeButton";
            this.statusChangeButton.Size = new System.Drawing.Size(103, 23);
            this.statusChangeButton.TabIndex = 9;
            this.statusChangeButton.Text = "statusChange";
            this.statusChangeButton.UseVisualStyleBackColor = true;
            this.statusChangeButton.Click += new System.EventHandler(this.statusChangeButton_Click);
            // 
            // addRouteButton
            // 
            this.addRouteButton.Location = new System.Drawing.Point(694, 627);
            this.addRouteButton.Name = "addRouteButton";
            this.addRouteButton.Size = new System.Drawing.Size(131, 23);
            this.addRouteButton.TabIndex = 10;
            this.addRouteButton.Text = "Add Route Button";
            this.addRouteButton.UseVisualStyleBackColor = true;
            this.addRouteButton.Click += new System.EventHandler(this.addRouteButton_Click);
            // 
            // form1BindingSource
            // 
            this.form1BindingSource.DataSource = typeof(MapEditor.Form1);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1486, 861);
            this.Controls.Add(this.addRouteButton);
            this.Controls.Add(this.statusChangeButton);
            this.Controls.Add(this.changePanel);
            this.Controls.Add(this.statusLabelPanel);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.enemyAddButton);
            this.Controls.Add(this.shooterList);
            this.Controls.Add(this.enemyList);
            this.Controls.Add(this.stagePanel);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.stagePanel.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.statusLabelPanel.ResumeLayout(false);
            this.statusLabelPanel.PerformLayout();
            this.changePanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.hp)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.form1BindingSource)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Panel stagePanel;
        private System.Windows.Forms.BindingSource form1BindingSource;
        private System.Windows.Forms.ListView enemyList;
        private System.Windows.Forms.ListView shooterList;
        private System.Windows.Forms.Button enemyAddButton;
        private System.Windows.Forms.Panel enemyPanel;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label hpLabel;
        private System.Windows.Forms.Panel changePanel;
        private System.Windows.Forms.NumericUpDown hp;
        private System.Windows.Forms.Panel statusLabelPanel;
        private System.Windows.Forms.Button statusChangeButton;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button addRouteButton;
    }
}

