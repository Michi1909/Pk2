#include "MyString.h"
#include <iostream>
int main()
{
    String name1("Michaela");
    std::cout << name1 << std::endl;
    printf("%c", name1[0]);
    std::cout << name1[0] << std::endl;
    return 0;
}