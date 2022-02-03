#ifndef MATRIX_HEADER
#define MATRIX_HEADER

namespace pk2
{
    template <class T>
    class Matrix
    {
    private:
        int dimension;
        T **matrix;

    public:
        Matrix(int d) : dimension(d)
        {
            matrix = new T *[d];

            int a;
            for (a = 0; a < d; a++)
            {
                matrix[a] = new T[d];
            }
        }

        Matrix(const Matrix &matrix)
        {
            for (int a = 0; a < this->demesional; ++a)
            {
                for (int b = 0; b < this->demesional; ++b)
                {
                    this->set(a, b, matrix.get(a, b));
                }
            }
        }

        ~Matrix()
        {
            for (int a = 0; a < dimension; a++)
            {
                delete[] matrix[a];
            }

            delete[] matrix;
        }

        void set(int a, int b, T value)
        {
            matrix[a][b] = value;
        }

        T get(int a, int b) const
        {
            return matrix[a][b];
        }

        int getDimension() const
        {
            return dimension;
        }
    };
}
#endif