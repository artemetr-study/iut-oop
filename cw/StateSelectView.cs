using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace study_iut_oop_4_semester_cw
{
    public partial class StateSelectView : UserControl
    {
        public StateSelectView()
        {
            InitializeComponent();
        }

        public StateSelectView(char symbol, int state, int max)
        {
            InitializeComponent();

            Max = max;
            Symbol = symbol;
            State = state;
        }

        public char Symbol { get; set; }

        public int State
        {
            get => (int) stateSelectorInput.Value;
            set => stateSelectorInput.Value = value;
        }

        public int Max
        {
            get => (int) stateSelectorInput.Maximum;
            set
            {
                stateSelectorInput.Maximum = value - 1;
                if (State > Max)
                {
                    State = -1;
                }
            }
        }
    }
}
