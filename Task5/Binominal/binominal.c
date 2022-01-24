#include <stdio.h>
#include "binominal.h"

int binominal(int n, int k)
{
    return fakultaet(n) / (fakultaet(k) * (fakultaet(n - k)));
}

int fakultaet(int n)
{

    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        count *= i;
    }
    return count;
}
