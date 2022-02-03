
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

     LinkedList list{};
     list.append("Michaela");
     list.printList();
     cout << "Anazhl Emelmte : " << list.anzahlElemente() << endl;
     cout << endl;
     list.append("Ella");
     list.printList();
     cout << "Anazhl Emelmte : " << list.anzahlElemente() << endl;
     cout << endl;
     list.append("Kaiser");
     list.printList();
     cout << "Anazhl Emelmte : " << list.anzahlElemente() << endl;
     cout << endl;

     list.insert("Insert Anfang", 0);
     list.printList();
     cout << "Anazhl Emelmte : " << list.anzahlElemente() << endl;
     cout << endl;

     list.insert("Insert Ende", 4);
     list.printList();
     cout << "Anazhl Emelmte : " << list.anzahlElemente() << endl;
     cout << endl;

     list.insert("Insert Mitte", 2);
     list.printList();
     cout << "Anazhl Emelmte : " << list.anzahlElemente() << endl;
     cout << endl;

     cout << "Index of \"Insert Ende\" is : " << list.index_of("Insert Ende") << endl;
     cout << endl;

     cout << "Remove Out of Index : " << list.remove(10) << endl;
     list.printList();
     cout << "Anazhl Emelmte : " << list.anzahlElemente() << endl;
     cout << endl;

     cout << "Index of Michaela is : " << list.index_of("Michaela") << endl;
     cout << endl;

     cout << "Index of michaela is : " << list.index_of("michaela") << endl;
     cout << endl;

     cout << "Remove First : " << list.remove(0) << endl;
     list.printList();
     cout << "Anazhl Emelmte : " << list.anzahlElemente() << endl;
     cout << endl;

     cout << "Index of Ella is : " << list.index_of("Ella") << endl;
     cout << endl;

     cout << "Index of Kaiser is : " << list.index_of("Kaiser") << endl;
     cout << endl;

     cout << "Remove Index of(2) : " << list.remove(2) << endl;
     list.printList();
     cout << "Anazhl Emelmte : " << list.anzahlElemente() << endl;
     cout << endl;

     cout << "Index of Ella is : " << list.index_of("Ella") << endl;
     cout << endl;

     cout << "Index of Kaiser is : " << list.index_of("Kaiser") << endl;
     cout << endl;

     list.printList();
     cout << endl;
     cout << "Get data from index  2 : " << list.get(2) << endl;
     cout << "Get data from index  1 : " << list.get(1) << endl;
     cout << "Get data from index  0 : " << list.get(0) << endl;
     cout << endl;
     list.printList();
     cout << "Get First : " << list.getfirst() << endl;
     cout << "Get Last  : " << list.getlast() << endl;
     cout << endl;
     cout << "Printing using Work" << endl;
     cout << "Visit_all : " << endl;
     list.visit_all(ausgabe);
}