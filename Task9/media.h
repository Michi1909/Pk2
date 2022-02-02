#ifndef Included_Hone
#define Included_Hone

#include <string>
#include <iostream>
using namespace std;
class media
{
private:
    const int id;
    string title;
    int year;
    static int count;

public:
    media(string title, int year);
    virtual ~media();
    int age() const { return 2021 - year; }
    virtual void printData() = 0;
    string getTitle() const { return title; }
    int getYear() const { return year; }
    int getID() const { return id; }
};
int media::count = 0;
media::media(string title, int year) : title(title), year(year), id(count)
{
    count++;
};
media::~media(){};

#endif