#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stringcat.h"

char *stringcat(const char *str1, const char *str2)
{
    int length = strlen(str1) + strlen(str2);
    char *newlength = malloc(length + 1);
    while (*str1)
    {
        *newlength = *str1;
        str1++;
        newlength++;
    }
    while (*str2)
    {
        *newlength = *str2;
        str2++;
        newlength++;
    }
    *newlength = '\0';
    return (newlength - length);
}