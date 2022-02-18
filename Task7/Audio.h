#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED

#include "Medium.h"
#include <string>

class Audio : public Medium
{
private:
    std::string interpret;
    int dauer;

public:
    Audio(std::string title, int year, std::string interpret, int dauer);
    virtual ~Audio();
    std::string getInterpret() { return interpret; }
    int getDauer() { return dauer; }
    void druckeDaten() override
    {
        std::cout << "ID = " << this->getID() << " von " << this->getInterpret() << " aus " << this->getYear() << " Spieldauer: " << this->getDauer() << "sek." << std::endl;
    }
};

Audio::Audio(std::string title, int year, std::string interpret, int dauer) : Medium(title, year), interpret(interpret), dauer(dauer)
{
}
Audio::~Audio() {}
#endif // AUDIO_H_INCLUDED