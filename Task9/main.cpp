#include <iostream>
#include "LinkedList.h"
#include <string>

using namespace std;
using namespace fhdo_pk2;
void printed(const char *t)
{
    cout << t << endl;
}
int main()
{

    LinkedList liste;
    liste.append("Element 1");
    liste.insert("Element 2", 2);
    LinkedList liste2 = liste;
    cout << "Liste:" << endl;
    liste.visit_all(printed);
    liste.remove(2);
    cout << "Liste:" << endl;
    liste.visit_all(printed);
    cout << "Liste2:" << endl;
    liste2.visit_all(printed);

    liste.append("Michaela");
    liste.printList();
    cout << "count Elements : " << liste.countElements() << endl;
    cout << endl;
    liste.append("Ella");
    liste.printList();
    cout << "count Elements : " << liste.countElements() << endl;
    cout << endl;
    liste.append("Kaiser");
    liste.printList();
    cout << "count Elements : " << liste.countElements() << endl;
    cout << endl;

    liste.insert("Insert Anfang", 0);
    liste.printList();
    cout << "count Elements : " << liste.countElements() << endl;
    cout << endl;

    liste.insert("Insert Ende", 4);
    liste.printList();
    cout << "count Elements : " << liste.countElements() << endl;
    cout << endl;

    liste.insert("Insert Mitte", 2);
    liste.printList();
    cout << "count Elements : " << liste.countElements() << endl;
    cout << endl;

    cout << "Index of \"Insert Ende\" is : " << liste.index_of("Insert Ende") << endl;
    cout << endl;

    cout << "Remove Out of Index : " << liste.remove(10) << endl;
    liste.printList();
    cout << "count Elements : " << liste.countElements() << endl;
    cout << endl;

    cout << "Index of Kaiser is : " << liste.index_of("Kaiser") << endl;
    cout << endl;

    cout << "Index of kaiser is : " << liste.index_of("kaiser") << endl;
    cout << endl;

    cout << "Remove First : " << liste.remove(0) << endl;
    liste.printList();
    cout << "count Elements : " << liste.countElements() << endl;
    cout << endl;

    cout << "Index of Michaela is : " << liste.index_of("Michaela") << endl;
    cout << endl;

    cout << "Index of Ella is : " << liste.index_of("Ella") << endl;
    cout << endl;

    cout << "Remove Index of(2) : " << liste.remove(2) << endl;
    liste.printList();
    cout << "count Elemente : " << liste.countElements() << endl;
    cout << endl;

    cout << "Index of Ella is : " << liste.index_of("Ella") << endl;
    cout << endl;

    cout << "Index of Kaiser is : " << liste.index_of("Kaiser") << endl;
    cout << endl;

    liste.printList();
    cout << endl;
    cout << "Get data from index  2 : " << liste.get(2) << endl;
    cout << "Get data from index  1 : " << liste.get(1) << endl;
    cout << "Get data from index  0 : " << liste.get(0) << endl;
    cout << endl;
    liste.printList();
    cout << "Get First : " << liste.getfirst() << endl;
    cout << "Get Last  : " << liste.getlast() << endl;
    cout << endl;
    cout << "Printing using Work" << endl;
    cout << "Visit_all : " << endl;
    liste.visit_all(printed);
    return 1;
}