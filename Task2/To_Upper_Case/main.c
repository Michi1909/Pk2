#include <stdio.h>
#include "To_Upper_Case.h"

int main(void)
{
    char array[] = {"Michaela"};
    upper(array);

    char letter = 'm';
    printf("%c", to_upper_case(letter));
    return 0;
}