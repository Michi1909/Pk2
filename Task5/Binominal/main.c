#include <stdio.h>
#include "binominal.h"
#include <assert.h>

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    printf("Binomial Coefficient is :");

    int c = binominal(n, k);

    printf("\n= %d", c);
    return 0;
}