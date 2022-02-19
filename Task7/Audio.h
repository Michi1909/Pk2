#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED

#include "Medium.h"
#include <string>
using namespace std;
class Audio : public Medium
{
private:
    string interpret;
    int dauer;

public:
    Audio(string title, int year, int count, string interpret, int dauer) : Medium(title, year, count), interpret(interpret), dauer(dauer) {}
    inline string getInterpret() { return interpret; }
    inline int getDauer() { return dauer; }
    void druckeDaten();
};
void Audio::druckeDaten()
{
    cout << "ID = " << this->getID() << " von " << this->getInterpret() << " aus " << this->getYear() << " Spieldauer: " << this->getDauer() << "sek." << endl;
}

#endif // AUDIO_H_INCLUDED