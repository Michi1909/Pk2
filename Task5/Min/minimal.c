#include <stdio.h>
#include "minimal.h"

double min(double a[], int n)
{
    double temp = a[0];
    for (int i = 0; i < n; i++)
    {
        if (temp > a[i])
        {
            temp = a[i];
        }
    }
    return temp;
}