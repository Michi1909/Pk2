#include <stdio.h>

void einmaleins()
{
    int from, to;
    printf("Please write the numbers from %d to %d: \n", &from, &to);

    for (int i = 1; i <= from; i++)
    { // j <= to: leave for when row has more then to Elements
        for (int j = from; j <= to; j++)
        {
            printf("%d \t", j * i); //calculate 10 11 12 13 14 etc.
        }
        printf("\n");
    }
}