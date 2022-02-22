#include "MyString.h"
#include <string.h>
#include <string>
String::String() : arraySize{1}, arrayString{new char[arraySize]}
{
    arrayString[0] = '\0';
}
String::String(const char *k) : arraySize{strlen(k) + 1}, arrayString{new char[arraySize]}
{
    strcpy(arrayString, k);
}
String::String(const String &k)
{
    arraySize = k.arraySize;
    arrayString = new char[arraySize];
    for (int i = 0; i < k.arraySize; i++)
    {
        arrayString[i] = k.arrayString[i];
    }
}
String::~String()
{
    delete[] arrayString;
}
char String::operator[](int i)
{
    if (i < 0 || i > arraySize)
        return ' ';
    return arrayString[i];
}
std::ostream &operator<<(std::ostream &out, const String &k)
{
    for (int i = 0; i < k.arraySize; i++)
    {
        out << k.arrayString[i];
    }
    return out;
}