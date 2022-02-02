#ifndef Included_Htwo
#define Included_Htwo

#include <string>
#include <iostream>
#include "media.h"
using namespace std;
class audio : public media
{
private:
    string interpred;
    int time;

public:
    audio(string title, int year, string interpred, int time);
    ~audio();
    string getInterpred() const { return interpred; }
    int getTime() const { return time; }
    void printData() override
    {
        std::cout << "ID =  " << this->getID() << " from " << this->getInterpred() << " in the year " << this->getYear() << " last " << this->getTime() << " sec." << std::endl;
    }
};
audio::audio(string title, int year, string interpred, int time) : media(title, year), interpred(interpred), time(time){};
audio::~audio(){};

#endif