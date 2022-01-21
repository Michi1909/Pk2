#include <stdio.h>
#include "binary.h"
#include "math.h"

void binary(int x)
{
    int contin = x;

    for (int i = 6; i >= 0; i--)
    {
        int rest = contin - (int)pow(2, i);
        if (rest >= 0)
        {
            contin = rest;
            printf("1");
        }
        if (rest < 0)
        {
            contin = contin;
            printf("0");
        }
    }
}
