#ifndef BILD_H_INCLUDED
#define BILD_H_INCLUDED

#include "Medium.h"
#include <string>

class Bild : public Medium
{
private:
    std::string ort;

public:
    Bild(std::string title, int year, std::string ort);
    virtual ~Bild();
    std::string getOrt() { return ort; }
    void druckeDaten() override
    {
        std::cout << "ID = " << this->getID() << " " << this->getTitle() << " aufgenommen im Jahr " << this->getYear() << " in " << this->getOrt() << std::endl;
    }
};
Bild::Bild(std::string title, int year, std::string ort) : Medium(title, year), ort(ort) {}
Bild::~Bild() {}
#endif //BILD_H_INCLUDED