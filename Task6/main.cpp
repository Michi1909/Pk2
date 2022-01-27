#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main()
{
    cout << "LinkedList in C++" << endl;
    LinkedList *list1 = new LinkedList(); //Create a empty LinkedList;
    list1->append(new char('a'));
    list1->printList();
    cout << "Number of Elements : " << list1->lengthElemente() << endl;
    list1->append(new char('b'));
    list1->printList();
    cout << "Number of Elements : " << list1->lengthElemente() << endl;
    list1->insert(new char('c'), 3);
    list1->printList();
    cout << "Number of Elements : " << list1->lengthElemente() << endl;
    list1->insert(new char('d'), 4);
    list1->printList();
    cout << "Number of Elements : " << list1->lengthElemente() << endl;
    list1->insert(new char('e'), 5);
    list1->printList();
    cout << "Number of Elements : " << list1->lengthElemente() << "\n"
         << endl;
    cout << "First Element of the LinkedList is: " << *list1->first() << "\n"
         << endl;
    cout << "Last Element of the LinkedList : " << *list1->last() << "\n"
         << endl;
    cout << "The Element with the char 'a' is at position : " << list1->index_of(new char('a')) << "\n"
         << endl;

    return 0;
}