#include "stringcat.h"
#include <stdio.h>

int main()
{
    const char *str1 = "Hello ";
    const char *str2 = "World!";
    const char *c = stringcat(str1, str2);
    printf("%s", c);
    return 0;
}