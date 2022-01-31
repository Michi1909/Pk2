
#include <iostream>
#include "LinkedList.h"
#include <string>
using namespace std;
using namespace fhdo_pk2;

void ausgabe(const char *t)
{
     cout << t << "\t";
}
int main()
{

     fhdo_pk2::LinkedList liste;
     liste.append("Element 1");
     liste.insert("Element 2", 2);
     fhdo_pk2::LinkedList liste2 = liste;
     cout << "Liste:" << endl;
     liste.visit_all(ausgabe);
     liste.remove(2);
     cout << "Liste:" << endl;
     liste.visit_all(ausgabe);
     cout << "Liste2:" << endl;
     liste2.visit_all(ausgabe);
}