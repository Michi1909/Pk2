
#include "TestMatrix.h"
#include "TestMatrix.cpp"
#include <iostream>
using namespace std;
int main()
{

    Matrix<int> m(2);

    m.set(0, 0, 1);
    m.set(0, 1, 2);
    m.set(1, 0, 3);
    m.set(1, 1, 4);

    //cout << m << "*" << endl << m << "=";
    cout << m << "*" << endl
         << m << "=" << endl
         << *(m * m);

    return 0;
}