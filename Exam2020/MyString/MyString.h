/* 4.1. String Klasse selber schreiben (strcpy und strlen durfte genutzt werden)
es soll ein char * zur dynamischen verwaltung des Strings genutzt werden
Konstruktor der leeren String erstellt (nicht nullptr)
Konstruktor der const char * entgegen nimmt und ihn in neuen string kopiert.
Funktionen:
- indexer erstellen
- at(int pos)
- length()
- c_str()
4.2. Ausgabe überladen fuer String Klasse */
#include <ostream>
#include <string.h>
class String
{
private:
    int arraySize;
    char *arrayString;

public:
    String();
    String(const char *k);
    String(const String &k);
    ~String();
    // indexer
    char operator[](int i);
    // output Operator
    friend std::ostream &operator<<(std::ostream &out, const String &s);
    inline int getLength() { return strlen(arrayString); }
    inline char at(int pos) { return arrayString[pos]; }
    inline const char *c_str() { return arrayString; }
};