#include <stdio.h>
#include "binominal.h"
#include <assert.h>

int main()
{
    int n, k;
    printf("Pls give the number for calculate the Binomial Coefficient:\n");
    scanf("%d", &n);
    scanf("%d", &k);
    if (n < k)
    {
        printf("The number n must be larger than or equal to k.\n");
        return 0;
    }
    else
    {

        printf("Binomial Coefficient is :");

        int c = binominal(n, k);

        printf("\n= %d", c);
        return 0;
    }
}