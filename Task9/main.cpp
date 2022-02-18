#include <iostream>
#include "LinkedList.h"
#include "media.h"
#include "picture.h"
#include "audio.h"
#include <string>

using namespace std;
using namespace fhdo_pk2;

void ausgabe(const char *t)
{
    std::cout << t << std::endl;
}
template <typename T>
void ausgabe(T t)
{
    cout << t << endl;
}
template <typename T>
void ausgabeZeiger(T t)
{
    cout << *t << endl;
}

void ausgabemedia(media *obj)
{
    obj->printData();
}

void deletemedia(media *obj)
{
    delete obj;
}
int main()
{

    cout << "String Liste : " << endl;
    LinkedList<string> liste{};
    liste.append("Element 1");
    liste.insert("Element 2", 2);
    LinkedList<string> liste2 = liste;
    cout << "Liste:" << endl;
    liste.visit_all(ausgabe);
    liste.remove(2);
    cout << "Liste:" << endl;
    liste.visit_all(ausgabe);
    cout << "Liste2:" << endl;
    liste2.visit_all(ausgabe);

    cout << "----------------" << endl;

    cout << "Integer Liste : " << endl;
    LinkedList<int *> liste3;
    int a = 1;
    int b = 2;
    liste3.append(&a);
    liste3.insert(&b, 2);
    LinkedList<int *> liste4 = liste3;
    cout << "Liste:" << endl;
    liste3.visit_all(ausgabeZeiger);
    liste3.remove(2);
    cout << "Liste:" << endl;
    liste3.visit_all(ausgabeZeiger);
    cout << "Liste2:" << endl;
    liste4.visit_all(ausgabeZeiger);

    cout << "-----------------" << endl;
    audio *audiobib = new audio("Celin Dion", 225, "I Will always Love u ", 1985);
    picture *bild = new picture("Dortmund", 2018, "Sunset");
    cout << "media Liste : " << endl;
    LinkedList<media *> liste5{};
    liste5.append(audiobib);
    liste5.insert(bild, 2);
    LinkedList<media *> liste6 = liste5;
    cout << "Liste1:" << endl;
    liste5.visit_all(ausgabemedia);
    liste5.remove(2);
    cout << "Liste1:" << endl;
    liste5.visit_all(ausgabemedia);
    cout << "Liste2:" << endl;
    liste6.visit_all(ausgabemedia);

    cout << endl;
    cout << "After Delete" << endl;
    liste6.visit_all(deletemedia);
    // media Objecte wurden gelöcht aber die NODES in denen die media Objekte waren
    // müssen auch gelöcht werden !
    for (int i = 0; i < liste6.anzahlElemente(); i++)
    {
        liste6.remove(i);
    }
    return 0;
}