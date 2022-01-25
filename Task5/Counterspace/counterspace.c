#include <stdio.h>
#include "counterspace.h"

int counterspace(char s[])
{
    int count = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            count++;
        }
        i++;
    }
    return count;
}