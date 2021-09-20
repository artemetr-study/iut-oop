namespace study_iut_oop_4_semester_cw
{
    partial class StateSelectView
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
            this.stateSelectorInput = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.stateSelectorInput)).BeginInit();
            this.SuspendLayout();
            // 
            // stateSelectorInput
            // 
            this.stateSelectorInput.Location = new System.Drawing.Point(0, 0);
            this.stateSelectorInput.Maximum = new decimal(new int[] {
            0,
            0,
            0,
            0});
            this.stateSelectorInput.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            -2147483648});
            this.stateSelectorInput.Name = "stateSelectorInput";
            this.stateSelectorInput.Size = new System.Drawing.Size(36, 20);
            this.stateSelectorInput.TabIndex = 0;
            this.stateSelectorInput.Value = new decimal(new int[] {
            1,
            0,
            0,
            -2147483648});
            // 
            // StateSelectView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.stateSelectorInput);
            this.Name = "StateSelectView";
            this.Size = new System.Drawing.Size(40, 21);
            ((System.ComponentModel.ISupportInitialize)(this.stateSelectorInput)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.NumericUpDown stateSelectorInput;
    }
}
