using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace study_iut_oop_4_semester_cw
{
    abstract class AutomatFin
    {
        protected List<State> _states = new List<State>();
        protected string _symbols = string.Empty;
        protected State _startState = null;

        public bool Full()
        {
            return !(States.Count == 0 || Symbols.Length == 0 || StartState == null);
        }

        public bool Preform(string expression)
        {
            if (!Full())
            {
                throw new ArgumentNullException();
            }

            var pattern = $"[^{Symbols.ToString()}]";

            var m = Regex.Match(expression, @pattern, RegexOptions.IgnoreCase);
            if (m.Success)
            {
                return false;
            }

            var state = StartState;
            foreach (var symbol in expression.ToCharArray())
            {
                state = state[symbol];

                if (state == null)
                {
                    return false;
                }
            }

            return state.Finite;
        }

        public List<State> States { get => _states; set => _states = value; }

        public string Symbols { get => _symbols; set => _symbols = value; }

        public State StartState { get => _startState; set => _startState = value; }
    }
}
