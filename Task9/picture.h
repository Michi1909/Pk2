
#ifndef Included_H
#define Included_H

#include <string>
#include <iostream>

#include "media.h"

using namespace std;

class picture : public media
{
private:
    string place;

public:
    picture(string title, int year, string place);
    ~picture();
    string getPlace() const { return place; }
    void printData() override
    {
        std::cout << "ID = " << this->getID() << " random photo: was token in the year " << this->getYear() << " in " << this->getPlace() << std::endl;
    }
};
picture::picture(string title, int year, string place) : media(title, year), place(place){};
picture::~picture(){};
#endif