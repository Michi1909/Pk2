#ifndef BILD_H_INCLUDED
#define BILD_H_INCLUDED

#include "Medium.h"
#include <string>

using namespace std;
class Bild : public Medium
{
private:
    string ort;

public:
    Bild(string title, int year, int count, string ort) : Medium(title, year, count), ort(ort) {}
    inline string getOrt() { return ort; }
    void druckeDaten();
};
void Bild::druckeDaten()
{
    cout << "ID = " << this->getID() << " " << this->getTitle() << " aufgenommen im Jahr " << this->getYear() << " in " << this->getOrt() << endl;
}

#endif // BILD_H_INCLUDED