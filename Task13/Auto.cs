using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Task13;

namespace Task13
{
    class Auto
    {
        public string hersteller;
        public int baujahr { get; set; }

        public Auto(string hersteller, int baujahr)
        {
            this.hersteller = hersteller;
            this.baujahr = baujahr;
        }
    }
}
