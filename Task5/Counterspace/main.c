#include "counterspace.h"
#include <stdio.h>

int main()
{
    char s[6] = {'E', 'l', 'a', ' ', 'K', '.'};
    int c = counterspace(s);
    printf("The amoung of space-tab in the char array is: %d ", c);

    return 0;
}