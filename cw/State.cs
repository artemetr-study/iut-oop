using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace study_iut_oop_4_semester_cw
{
    public class State
    {
        private Dictionary<char, State> _relations = new Dictionary<char, State>();
        private bool _finite = false;
        protected int _name = -1;

        public State() { }

        public State(bool finite)
        {
            Finite = finite;
        }

        public Dictionary<char, State> Relations { get => _relations; set => _relations = value; }

        public bool Finite { get => _finite; set => _finite = value; }

        public int Name { get => _name; set => _name = value; }

        public State this[char symbol]
        {
            get => Relations.ContainsKey(symbol) ? Relations[symbol] : null;
            set => _relations[symbol] = value ?? throw new ArgumentNullException(nameof(value));
        }

        public static bool HasSameTransitions(State firstState, State secondState)
        {
            if (firstState.Finite != secondState.Finite)
            {
                return false;
            }

            var firstRelations = firstState.Relations;
            var secondRelations = secondState.Relations;

            if (firstRelations.Keys.ToList<char>().Except(secondRelations.Keys.ToList<char>()).ToList().Count > 0 || (firstRelations.Values.Where(value => value != null)).Count() !=
                (secondRelations.Values.Where(value => value != null)).Count())
            {
                return false;
            }

            bool all = true;
            foreach (var relation in firstRelations)
            {
                if (!secondRelations.ContainsKey(relation.Key) || secondRelations[relation.Key] != firstRelations[relation.Key])
                {
                    all = false;
                    break;
                }
            }

            return all;
        }
    }
}
