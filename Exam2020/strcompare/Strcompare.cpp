/* strcompare(char *s, char *t) methode schreiben mit rückgabewert -1 0 1. Ohne Indexschreibweise. */
#include <iostream>
strcompare(char *s, char *t)
{
    int i = 0;
    while ((*(s + i) != '\0') && (*(t + i) != '\0') && (*(s + i) == *(t + i)))
    {
        i++;
    }

    if (*(s + i) == *(t + i))
        return 0;
    int result = *(s + i) - *(t + i);
    return result > 0 ? 1 : -1;
}

int main()
{
    char c[] = {'H', 'e', 'l', 'l', '\0'};
    char myword[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    int result = strcompare(c, myword);
    std::cout << result << std::endl;
}