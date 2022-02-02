#ifndef _MEDIUM_H_INCLUDED
#define _MEDIUM_H_INCLUDED
#include <string>
#include <iostream>

#define actuallyYear 2021

class Medium
{
private:
    const int id;
    std::string title;
    int year;
    int count = 0;

public:
    Medium(std::string title, int year);
    virtual ~Medium();
    int alter() { return actuallyYear - year; };
    void virtual druckeDaten() = 0;
    int getID() const { return id; }
    std::string getTitle() { return title; }
    int getYear() { return year; }
};
Medium::Medium(std::string title, int year) : title(title), year(year), id(count)
{
    count++;
}
Medium::~Medium() {}
#endif //_MEDIUM_H_INCLUDED