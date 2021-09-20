using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace study_iut_oop_4_semester_cw
{
    class Dfa : AutomatFin
    {
        public Dfa() { }
        public Dfa(List<State> states, string symbols, State startState)
        {
            States = states;
            Symbols = symbols;
            StartState = startState;
        }
    }
}
