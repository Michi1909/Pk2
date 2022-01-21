#include <stdio.h>
#include "Ascii.h"

void ascii(int s)
{
    for (int i = 32; i <= 126; i++)
    {
        printf("%4d %c", i, i);
        s++;

        if (s % 10 == 0)
        {
            printf("\n\r");
        }
    }
}