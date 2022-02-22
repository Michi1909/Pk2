/* 2.1. int max(int a[], int n) methode schreiben um den größten wert zurückzugeben. */
#include <iostream>
int max(int a[], int n)
{
    int temp = a[0];
    for (int i = 0; i < n; i++)
    {
        if (temp < a[i])
            temp = a[i];
    }
    return temp;
}

int main()
{
    int laenge = 4;
    int numberArray[] = {1, 35, 2, 6};

    int maxNumber = max(numberArray, laenge);
    std::cout << "The max number is " << maxNumber << std::endl;
    return 0;
}