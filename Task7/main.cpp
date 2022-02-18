#include <iostream>
#include "Medium.h"
#include "Bild.h"
#include "Audio.h"
using namespace std;

int main(void)
{
    Medium *audioBib[3];
    audioBib[0] = new Audio("Happy Birthday", 1900, "Happy Birthday", 220);
    audioBib[1] = new Audio("Happy New Year", 1999, "Happy New Year", 150);
    audioBib[2] = new Audio("Happy Christmas", 1700, "Happy Christmas", 233);

    Medium *bildBib[3];
    bildBib[0] = new Bild("Im Urlaub", 2021, "Spanien");
    bildBib[1] = new Bild("Am arbeiten", 2021, "Deutschland");
    bildBib[2] = new Bild("Fosdem", 2019, "Bruessel");

    Medium *a1 = new Audio("Sad and always alone", 2021, "Sad and always alone", 222);
    Medium *a2 = new Audio("Totally not importand", 2022, "Totally not important", 333);
    Medium *a3 = new Audio("happpy and bla bla bla ", 2022, "Happy and bla bla bla", 202);

    std::cout << "Audio with Pointer Bib:" << std::endl;
    a1->druckeDaten();
    a2->druckeDaten();
    a3->druckeDaten();

    for (int i = 0; i < sizeof(bildBib); i++)
    {
        std::cout << "Bild Bib" << std::endl;
        bildBib[i]->druckeDaten();
        std::cout << "Audio Bib" << std::endl;
        audioBib[i]->druckeDaten();
    }
}