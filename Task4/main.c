#include <stdio.h>
#include "Dictionary.h"
#define SIZE 2
int main()
{
    int i;
    for (i = 1; i <= 2 * SIZE; i++)
    {
        printf("%d", insert(i));
    }
    for (i = 1; i <= SIZE; i++)
    {
        printf("%d", member(i));
    }
    for (i = SIZE + 1; i <= 2 * SIZE; i++)
    {
        printf("%d", delete (i));
    }
    for (i = 1; i <= 2 * SIZE; i++)
    {
        printf("%d", member(i));
    }
    printf("\n");
    return 0;
}