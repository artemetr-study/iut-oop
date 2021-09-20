using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace study_iut_oop_4_semester_cw
{
    public partial class MainView : Form
    {
        public static MainView mw;
        public MainView()
        {
            InitializeComponent();

            mw = this;
        }

        public List<StateView> States
        {
            get => statesFlowLayout.Controls.OfType<StateView>().ToList();
            set
            {
                statesFlowLayout.Controls.Clear();
                foreach (var sw in value)
                {
                    statesFlowLayout.Controls.Add(sw);
                }
            }
        }

        public List<Char> Symbols
        {
            get
            {
                var result = new List<Char>();
                foreach (var label in symbolsFlowLayout.Controls.OfType<Label>().ToList())
                {
                    result.Add(Convert.ToChar(label.Text));
                }

                return result;
            }
            set
            {
                symbolsFlowLayout.Controls.Clear();
                foreach (var symbol in value)
                {
                    Label label = new Label();
                    label.Text = symbol.ToString();
                    label.Width = 40;
                    label.TextAlign = ContentAlignment.MiddleCenter;
                    symbolsFlowLayout.Controls.Add(label);
                }
            }
        }

        public Dictionary<char, int> ClearRelations()
        {
            Dictionary<char, int> result = new Dictionary<char, int>();

            foreach (var symbol in Symbols)
            {
                result[symbol] = -1;
            }

            return result;
        }

        public void RemoveState(int name)
        {
            var states = States;
            var cntStates = states.Count;

            states.RemoveAt(name);
            foreach (var state in states)
            {
                states[states.IndexOf(state)].HandleStateRemove(name, cntStates-1);
            }

            States = states;

            startStateInput.Maximum -= 1;
        }

        private void AddStateBtn_Click(object sender, EventArgs e)
        {
            var states = States;
            int cntStates = states.Count;
            var sw = new StateView(false, cntStates, ClearRelations(), cntStates + 1);

            states.Add(sw);

            for (int i = 0; i < cntStates + 1; i++)
            {
                states[i].Max(cntStates+1);
            }

            States = states;

            startStateInput.Maximum += 1;
        }

        private void AddSymbolBtn_Click(object sender, EventArgs e)
        {
            var states = States;
            int cntStates = states.Count;
            var symbols = Symbols;

            if (symbols.Count == 13)
            {
                MessageBox.Show("Too much character!");
                return;
            }

            if (selectedSymbolTextBox.TextLength == 0)
            {
                MessageBox.Show("Enter a character!");
                return;
            }

            string pattern = @"[^A-Za-zА-Яа-я0-9]";
            Match m = Regex.Match(selectedSymbolTextBox.Text, pattern, RegexOptions.IgnoreCase);
            if (m.Success)
            {
                MessageBox.Show("Invalid character!");
                return;
            }

            char symbol = Convert.ToChar(selectedSymbolTextBox.Text);

            if (symbols.Contains(symbol))
            {
                MessageBox.Show("This symbol already exists!");
                return;
            }

            symbols.Add(symbol);

            for (int i = 0; i < cntStates; i++)
            {
                states[i].HandleSymbolAdd(symbol, cntStates);
            }

            Symbols = symbols;
            States = states;
        }

        private void RmSymbolBtn_Click(object sender, EventArgs e)
        {
            var states = States;
            int cntStates = states.Count;
            var symbols = Symbols;
            char symbol = Convert.ToChar(selectedSymbolTextBox.Text);

            if (!symbols.Contains(symbol))
            {
                MessageBox.Show("This symbol does not exist!");
                return;
            }

            symbols.RemoveAt(Symbols.IndexOf(symbol));

            for (int i = 0; i < cntStates; i++)
            {
                states[i].HandleSymbolRemove(symbol, cntStates);
            }

            Symbols = symbols;
            States = states;
        }

        private MDfa BuildMDfa()
        {
            int startedStateIndex = (int) startStateInput.Value;
            if (startedStateIndex < 0)
            {
                MessageBox.Show("Please select the initial state!");
                return null;
            }

            var rowStates = States;

            var states = rowStates.Select(rowState => rowState.ToState()).ToList();
            for (var i = 0; i < rowStates.Count; i++)
            {
                foreach (var relation in rowStates[i].GetRelations())
                {
                    states[i].Relations[relation.Key] = relation.Value == -1 ? null : states[relation.Value];
                }
            }

            var symbols = new string(Symbols.ToArray());

            return new MDfa(states, symbols, states[startedStateIndex]);
        }

        private void PerformBtn_Click(object sender, EventArgs e)
        {
            var expression = wordTextBox.Text;

            if (expression.Length == 0)
            {
                MessageBox.Show("Enter the expression!");
                return;
            }

            MDfa mDfa = BuildMDfa();
            if (mDfa == null)
            {
                return;
            }

            var result = mDfa.Preform(expression);

            MessageBox.Show(result ? "Success!" : "An invalid expression for AF language!");
        }
    }
}
