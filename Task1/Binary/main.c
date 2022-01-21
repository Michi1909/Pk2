#include <stdio.h>
#include "Binary.h"

void main(void)
{
    printf("Aufgabe 4: \n");
    unsigned int decimal;
    printf("Please write the number which should be convert in dual:");
    scanf("%i", &decimal);
    binary(decimal);
    printf("\n");
    printf("\n");
}