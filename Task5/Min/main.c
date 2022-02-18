#include <stdio.h>
#include "minimal.h"

int main()
{
    int n = 5;
    double a[5] = {2, 6, 3, 1, 4};
    int result = min(a, n);
    printf("The min of this array is: %d", result);
    return 0;
}