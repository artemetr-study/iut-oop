namespace study_iut_oop_4_semester_cw
{
    partial class MainView
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.performBtn = new System.Windows.Forms.Button();
            this.wordTextBox = new System.Windows.Forms.TextBox();
            this.startStateLabel = new System.Windows.Forms.Label();
            this.startStateInput = new System.Windows.Forms.NumericUpDown();
            this.finiteLabel = new System.Windows.Forms.Label();
            this.stateLabel = new System.Windows.Forms.Label();
            this.symbolsFlowLayout = new System.Windows.Forms.FlowLayoutPanel();
            this.addStateBtn = new System.Windows.Forms.Button();
            this.addSymbolBtn = new System.Windows.Forms.Button();
            this.statesFlowLayout = new System.Windows.Forms.FlowLayoutPanel();
            this.rmSymbolBtn = new System.Windows.Forms.Button();
            this.selectedSymbolTextBox = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.startStateInput)).BeginInit();
            this.SuspendLayout();
            // 
            // performBtn
            // 
            this.performBtn.Location = new System.Drawing.Point(13, 414);
            this.performBtn.Name = "performBtn";
            this.performBtn.Size = new System.Drawing.Size(75, 23);
            this.performBtn.TabIndex = 1;
            this.performBtn.Text = "Perform";
            this.performBtn.UseVisualStyleBackColor = true;
            this.performBtn.Click += new System.EventHandler(this.PerformBtn_Click);
            // 
            // wordTextBox
            // 
            this.wordTextBox.Location = new System.Drawing.Point(94, 416);
            this.wordTextBox.Name = "wordTextBox";
            this.wordTextBox.Size = new System.Drawing.Size(694, 20);
            this.wordTextBox.TabIndex = 3;
            // 
            // startStateLabel
            // 
            this.startStateLabel.AutoSize = true;
            this.startStateLabel.Location = new System.Drawing.Point(605, 393);
            this.startStateLabel.Name = "startStateLabel";
            this.startStateLabel.Size = new System.Drawing.Size(57, 13);
            this.startStateLabel.TabIndex = 4;
            this.startStateLabel.Text = "Start State";
            // 
            // startStateInput
            // 
            this.startStateInput.Location = new System.Drawing.Point(668, 389);
            this.startStateInput.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            -2147483648});
            this.startStateInput.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            -2147483648});
            this.startStateInput.Name = "startStateInput";
            this.startStateInput.Size = new System.Drawing.Size(120, 20);
            this.startStateInput.TabIndex = 5;
            this.startStateInput.Value = new decimal(new int[] {
            1,
            0,
            0,
            -2147483648});
            // 
            // finiteLabel
            // 
            this.finiteLabel.AutoSize = true;
            this.finiteLabel.Location = new System.Drawing.Point(13, 13);
            this.finiteLabel.Name = "finiteLabel";
            this.finiteLabel.Size = new System.Drawing.Size(32, 13);
            this.finiteLabel.TabIndex = 6;
            this.finiteLabel.Text = "Finite";
            // 
            // stateLabel
            // 
            this.stateLabel.AutoSize = true;
            this.stateLabel.Location = new System.Drawing.Point(52, 13);
            this.stateLabel.Name = "stateLabel";
            this.stateLabel.Size = new System.Drawing.Size(32, 13);
            this.stateLabel.TabIndex = 7;
            this.stateLabel.Text = "State";
            // 
            // symbolsFlowLayout
            // 
            this.symbolsFlowLayout.Location = new System.Drawing.Point(94, 12);
            this.symbolsFlowLayout.Name = "symbolsFlowLayout";
            this.symbolsFlowLayout.Size = new System.Drawing.Size(625, 17);
            this.symbolsFlowLayout.TabIndex = 8;
            // 
            // addStateBtn
            // 
            this.addStateBtn.Location = new System.Drawing.Point(13, 387);
            this.addStateBtn.Name = "addStateBtn";
            this.addStateBtn.Size = new System.Drawing.Size(75, 23);
            this.addStateBtn.TabIndex = 9;
            this.addStateBtn.Text = "Add State";
            this.addStateBtn.UseVisualStyleBackColor = true;
            this.addStateBtn.Click += new System.EventHandler(this.AddStateBtn_Click);
            // 
            // addSymbolBtn
            // 
            this.addSymbolBtn.Location = new System.Drawing.Point(428, 388);
            this.addSymbolBtn.Name = "addSymbolBtn";
            this.addSymbolBtn.Size = new System.Drawing.Size(75, 23);
            this.addSymbolBtn.TabIndex = 10;
            this.addSymbolBtn.Text = "Add Symbol";
            this.addSymbolBtn.UseVisualStyleBackColor = true;
            this.addSymbolBtn.Click += new System.EventHandler(this.AddSymbolBtn_Click);
            // 
            // statesFlowLayout
            // 
            this.statesFlowLayout.AutoScroll = true;
            this.statesFlowLayout.Location = new System.Drawing.Point(13, 35);
            this.statesFlowLayout.Name = "statesFlowLayout";
            this.statesFlowLayout.Size = new System.Drawing.Size(775, 348);
            this.statesFlowLayout.TabIndex = 11;
            // 
            // rmSymbolBtn
            // 
            this.rmSymbolBtn.Location = new System.Drawing.Point(509, 388);
            this.rmSymbolBtn.Name = "rmSymbolBtn";
            this.rmSymbolBtn.Size = new System.Drawing.Size(94, 23);
            this.rmSymbolBtn.TabIndex = 12;
            this.rmSymbolBtn.Text = "Remove Symbol";
            this.rmSymbolBtn.UseVisualStyleBackColor = true;
            this.rmSymbolBtn.Click += new System.EventHandler(this.RmSymbolBtn_Click);
            // 
            // selectedSymbolTextBox
            // 
            this.selectedSymbolTextBox.Location = new System.Drawing.Point(343, 390);
            this.selectedSymbolTextBox.MaxLength = 1;
            this.selectedSymbolTextBox.Name = "selectedSymbolTextBox";
            this.selectedSymbolTextBox.Size = new System.Drawing.Size(79, 20);
            this.selectedSymbolTextBox.TabIndex = 13;
            // 
            // MainView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.selectedSymbolTextBox);
            this.Controls.Add(this.rmSymbolBtn);
            this.Controls.Add(this.statesFlowLayout);
            this.Controls.Add(this.addSymbolBtn);
            this.Controls.Add(this.addStateBtn);
            this.Controls.Add(this.symbolsFlowLayout);
            this.Controls.Add(this.stateLabel);
            this.Controls.Add(this.finiteLabel);
            this.Controls.Add(this.startStateInput);
            this.Controls.Add(this.startStateLabel);
            this.Controls.Add(this.wordTextBox);
            this.Controls.Add(this.performBtn);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(816, 489);
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(816, 489);
            this.Name = "MainView";
            this.ShowIcon = false;
            this.Text = "study-iut-oop-4-semester-sw";
            ((System.ComponentModel.ISupportInitialize)(this.startStateInput)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button performBtn;
        private System.Windows.Forms.TextBox wordTextBox;
        private System.Windows.Forms.Label startStateLabel;
        private System.Windows.Forms.NumericUpDown startStateInput;
        private System.Windows.Forms.Label finiteLabel;
        private System.Windows.Forms.Label stateLabel;
        private System.Windows.Forms.FlowLayoutPanel symbolsFlowLayout;
        private System.Windows.Forms.Button addStateBtn;
        private System.Windows.Forms.Button addSymbolBtn;
        private System.Windows.Forms.FlowLayoutPanel statesFlowLayout;
        private System.Windows.Forms.Button rmSymbolBtn;
        private System.Windows.Forms.TextBox selectedSymbolTextBox;
    }
}

