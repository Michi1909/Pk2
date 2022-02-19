#include <iostream>
#include "Medium.h"
#include "Bild.h"
#include "Audio.h"
using namespace std;

int main(void)
{

    Medium *medien[2];

    Bild *b = new Bild("La Pineda", 2021, 0, "Spanien");
    Audio *a = new Audio("Irgendein Interpred", 2022, 1, "Lalala", 220);

    medien[0] = b;
    medien[1] = a;

    for (int i = 0; i < 2; i++)
    {
        medien[i]->druckeDaten();
    }
}