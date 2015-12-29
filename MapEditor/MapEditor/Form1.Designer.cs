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
            this.form1BindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.stagePanel.SuspendLayout();
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
            this.enemyAddButton.Location = new System.Drawing.Point(1312, 455);
            this.enemyAddButton.Name = "enemyAddButton";
            this.enemyAddButton.Size = new System.Drawing.Size(133, 36);
            this.enemyAddButton.TabIndex = 4;
            this.enemyAddButton.Text = "Enemy Add";
            this.enemyAddButton.UseVisualStyleBackColor = true;
            this.enemyAddButton.Click += new System.EventHandler(this.enemyAddButton_Click);
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
            this.Controls.Add(this.enemyAddButton);
            this.Controls.Add(this.shooterList);
            this.Controls.Add(this.enemyList);
            this.Controls.Add(this.stagePanel);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.stagePanel.ResumeLayout(false);
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
    }
}

