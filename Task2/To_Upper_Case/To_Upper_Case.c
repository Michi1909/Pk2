#include <stdio.h>
#include "To_Upper_Case.h"

char to_upper_case(char c)
{
    char word = c;

    if ((word < 123) && (word > 96))
    {
        word -= 32;
    }
    else
    {
        return c;
    }
    return word;
}

void upper(char text[])
{
    int c = 0;

    while (text[c])
    {
        printf("%c", to_upper_case(text[c]));
        c++;
    }
    printf("\n");
}