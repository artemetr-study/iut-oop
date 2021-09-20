namespace study_iut_oop_4_semester_cw
{
    partial class StateView
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(StateView));
            this.finiteBox = new System.Windows.Forms.CheckBox();
            this.nameLabel = new System.Windows.Forms.Label();
            this.stateSelectorFlowLayout = new System.Windows.Forms.FlowLayoutPanel();
            this.removeStateBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // finiteBox
            // 
            this.finiteBox.AutoSize = true;
            this.finiteBox.Location = new System.Drawing.Point(6, 9);
            this.finiteBox.Name = "finiteBox";
            this.finiteBox.Size = new System.Drawing.Size(15, 14);
            this.finiteBox.TabIndex = 0;
            this.finiteBox.UseVisualStyleBackColor = true;
            // 
            // nameLabel
            // 
            this.nameLabel.AutoSize = true;
            this.nameLabel.Location = new System.Drawing.Point(40, 10);
            this.nameLabel.Name = "nameLabel";
            this.nameLabel.Size = new System.Drawing.Size(21, 13);
            this.nameLabel.TabIndex = 1;
            this.nameLabel.Text = "XX";
            // 
            // stateSelectorFlowLayout
            // 
            this.stateSelectorFlowLayout.Location = new System.Drawing.Point(76, 5);
            this.stateSelectorFlowLayout.Name = "stateSelectorFlowLayout";
            this.stateSelectorFlowLayout.Size = new System.Drawing.Size(625, 24);
            this.stateSelectorFlowLayout.TabIndex = 2;
            // 
            // removeStateBtn
            // 
            this.removeStateBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.removeStateBtn.Image = ((System.Drawing.Image)(resources.GetObject("removeStateBtn.Image")));
            this.removeStateBtn.Location = new System.Drawing.Point(733, 5);
            this.removeStateBtn.Margin = new System.Windows.Forms.Padding(0);
            this.removeStateBtn.Name = "removeStateBtn";
            this.removeStateBtn.Size = new System.Drawing.Size(24, 24);
            this.removeStateBtn.TabIndex = 3;
            this.removeStateBtn.UseVisualStyleBackColor = true;
            this.removeStateBtn.Click += new System.EventHandler(this.RemoveStateBtn_Click);
            // 
            // StateView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.removeStateBtn);
            this.Controls.Add(this.stateSelectorFlowLayout);
            this.Controls.Add(this.nameLabel);
            this.Controls.Add(this.finiteBox);
            this.Name = "StateView";
            this.Size = new System.Drawing.Size(769, 35);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox finiteBox;
        private System.Windows.Forms.Label nameLabel;
        private System.Windows.Forms.FlowLayoutPanel stateSelectorFlowLayout;
        private System.Windows.Forms.Button removeStateBtn;
    }
}
