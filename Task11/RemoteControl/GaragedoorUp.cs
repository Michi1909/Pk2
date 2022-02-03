using Fh.Pk2.Devices;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fh.Pk2.Commands
{
    class GaragedoorUp : Command
    {
        private Garagedoor garagedoor;

        public GaragedoorUp(Garagedoor garagedoor)
        {
            this.garagedoor = garagedoor;
        }

        public override void Execute()
        {
            garagedoor.Up();
        }
    }
}