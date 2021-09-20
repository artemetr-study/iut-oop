using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static study_iut_oop_4_semester_cw.State;

namespace study_iut_oop_4_semester_cw
{
    class MDfa : Dfa
    {
        private bool _isMinimized = false;

        MDfa() { }

        public MDfa(List<State> states, string symbols, State startState)
        {
            States = states;
            Symbols = symbols;
            StartState = startState;
            Minimize();
        }

        MDfa(AutomatFin fa)
        {
            Copy(fa);
            Minimize();
        }

        public List<State> States
        {
            get => _states;
            set {
                _states = value;
                _isMinimized = false;
            }
        }
        public string Symbols
        {
            get => _symbols;
            set
            {
                _symbols = value;
                _isMinimized = false;
            }
        }

        public State StartState
        {
            get => _startState;
            set
            {
                _startState = value;
                _isMinimized = false;
            }
        }

        private void Copy(AutomatFin af)
        {
            States = af.States;
            Symbols = af.Symbols;
            StartState = af.StartState;
        }

        public bool IsMinimized() => _isMinimized;

        MDfa MinDfa(Dfa dfa)
        {
            return new MDfa(dfa);
        }

        public void Minimize()
        {
            if (!Full())
            {
                throw new ArgumentNullException();
            }

            var dfaStates = States;
            var mDfaStates = new List<State>();
            var statesMap = new Dictionary<State, State>();

            mDfaStates.Add(StartState);

            foreach (var dfaState in dfaStates)
            {
                var hasSameTransition = false;
                foreach (var mDfaState in mDfaStates)
                {
                    if (HasSameTransitions(mDfaState, dfaState))
                    {
                        statesMap[dfaState] = mDfaState;
                        hasSameTransition = true;
                        break;
                    }
                }

                if (!hasSameTransition)
                {
                    mDfaStates.Add(dfaState);
                }

                hasSameTransition = false;
            }

            foreach (var mDfaState in mDfaStates)
            {
                var mDfaStateRelations = mDfaState.Relations;
                var keys = mDfaStateRelations.Keys.ToList<char>();
                foreach (var key in keys)
                {
                    if (statesMap.ContainsKey(mDfaStateRelations[key]))
                    {
                        mDfaStateRelations[key] = statesMap[mDfaStateRelations[key]];
                    }
                }

                mDfaStates[mDfaStates.IndexOf(mDfaState)].Relations = mDfaStateRelations;
            }

            States = mDfaStates;
            Symbols = Symbols;
        }
    }
}
