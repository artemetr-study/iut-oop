using System;
using System.Collections;
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
    public partial class StateView : UserControl
    {
        public StateView()
        {
            InitializeComponent();
        }

        public StateView(bool isFinite, int name, Dictionary<char, int> relations, int cntStates)
        {
            InitializeComponent();

            IsFinite = isFinite;
            StateName = name;
            SetRelations(relations, cntStates);
        }

        public bool IsFinite
        {
            get => finiteBox.Checked;
            set => finiteBox.ThreeState = value;
        }

        public int StateName
        {
            get => Convert.ToInt32(nameLabel.Text);
            set => nameLabel.Text = value.ToString();
        }

        public void SetRelations(Dictionary<char, int> relations, int cntStates)
        {
            stateSelectorFlowLayout.Controls.Clear();
            foreach (var entry in relations)
            {
                stateSelectorFlowLayout.Controls.Add(new StateSelectView(entry.Key, entry.Value, cntStates));
            }
        }

        public Dictionary<char, int> GetRelations()
        {
            Dictionary<char, int> result = new Dictionary<char, int>();

            foreach (var control in stateSelectorFlowLayout.Controls.OfType<StateSelectView>().ToList())
            {
                result[control.Symbol] = control.State;
            }

            return result;
        }

        public void Max(int max)
        {
            SetRelations(GetRelations(), max);
        }

        public void HandleStateRemove(int name, int cntStates)
        {
            var relations = GetRelations();
            List<char> keyList = new List<char>(relations.Keys);

            foreach (var key in keyList)
            {
                if (relations[key] == name)
                {
                    relations[key] = -1;
                }
                else if (relations[key] > name)
                {
                    relations[key]--;
                }
            }

            SetRelations(relations, cntStates);

            if (StateName > name)
            {
                StateName -= 1;
            }
        }

        public void HandleSymbolAdd(char symbol, int cntStates)
        {
            var relations = GetRelations();
            relations[symbol] = -1;
            SetRelations(relations, cntStates);
        }

        public void HandleSymbolRemove(char symbol, int cntStates)
        {
            var relations = GetRelations();
            relations.Remove(symbol);
            SetRelations(relations, cntStates);
        }

        private void RemoveStateBtn_Click(object sender, EventArgs e)
        {
            MainView.mw.RemoveState(StateName);
        }

        public State ToState()
        {
            return new State(IsFinite);
        }
    }
}
