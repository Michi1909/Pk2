#include <iostream>
#include "TestMatrix.h"

using namespace pk2;

template <class T>
std::ostream &operator<<(std::ostream &ausgabe, const Matrix<T> &matrix)
{
    int dimension = matrix.getDimension();

    for (int a = 0; a < dimension; a++)
    {
        for (int b = 0; b < dimension; b++)
        {
            ausgabe << matrix.get(a, b) << " ";
        }
        ausgabe << std::endl;
    }

    return ausgabe;
}

template <class T>
Matrix<T> *operator*(const Matrix<T> &m1, const Matrix<T> &m2)
{
    int dimension = m1.getDimension();
    Matrix<T> *m = new Matrix<T>(dimension);

    for (int a = 0; a < dimension; a++)
    {
        for (int b = 0; b < dimension; b++)
        {
            T value = 0;

            for (int c = 0; c < dimension; c++)
            {
                value += m1.get(a, c) * m2.get(c, b);
            }
            m->set(a, b, value);
        }
    }

    return m;
}