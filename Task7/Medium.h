#ifndef _MEDIUM_H_INCLUDED
#define _MEDIUM_H_INCLUDED
#include <string>
#include <iostream>

#define actuallyYear 2021
using namespace std;
class Medium
{
private:
    string title;
    int year;
    int const id;

public:
    Medium(string title, int year, int count) : title(title), year(year), id(count) {}
    inline string getTitle() { return title; }
    inline int getYear() { return year; }
    inline int getID() const { return id; }
    inline int alter() { return actuallyYear - year; };
    virtual void druckeDaten() = 0;
};

#endif //_MEDIUM_H_INCLUDED