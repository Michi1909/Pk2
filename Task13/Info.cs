using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Task13;

namespace Task13
{
    class Info { 
        public Info(Fuhrpark fuhrpark)
        {
            fuhrpark.FuhrparkEreignis += Information;
        }

        public void Information(object sender, FuhrparkEreignisArgs args)
        {
            Console.WriteLine("Ein neues Auto wurde hinzugefuegt! Ein {1} aus dem Jahr {0}", args.auto.baujahr, args.auto.hersteller);
        }
    }
}
