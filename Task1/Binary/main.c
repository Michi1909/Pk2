#include <stdio.h>
#include "Binary.h"

int main(void)
{
    printf("Aufgabe 4: \n");
    unsigned int decimal;
    printf("Please write the number which should be convert in dual:");
    scanf("%i", &decimal);
    binary(decimal);
    printf("\n");
    printf("\n");
    return 0;
}