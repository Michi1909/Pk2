using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Task13;

namespace Task13
{

    public interface Iterator<T>
    {
        Boolean hasNext();

        T next();
    }
}
