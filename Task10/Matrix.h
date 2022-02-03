#ifndef _MATRIX_H_INCLUDED
#define _MATRIX_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
namespace Matrix_Operations
{

    template <typename T>
    class Matrix
    {
    private:
        int demesional;
        T **matrix;

    public:
        Matrix(int demesional) : demesional(demesional)
        {
            this->matrix = generateMatrix(this->demesional);
        }
        Matrix(const Matrix &org);
        ~Matrix();
        T **generateMatrix(int demesional);
        void set(int i, int j, T value);
        void fillMatrix(int *src, int size);
        void printMatrix();
        void transpose();
        void addMatrix(Matrix &m);
        void subMatrix(Matrix &m);
        Matrix<T> mulMatrix(Matrix &m);
        void divMatrix(Matrix &m);
        const T getValueAt(int i, int j) const;
        const int getNumberOfRows() const;
        const int getNumberOfCols() const;
        const int getDem() const;
    };

    template <typename T>
    Matrix<T>::Matrix(const Matrix &org) : Matrix(org.demesional)
    {
        for (int j, i = 0; i < this->demesional; ++i)
        {
            for (j = 0; j < this->demesional; ++j)
            {
                this->set(i, j, org.getValueAt(i, j));
            }
        }
    }

    template <typename T>
    Matrix<T>::~Matrix()
    {
        for (int i = 0; i < this->demesional; i++)
        {
            delete[] this->matrix[i]; // we delete all the rows
        }
        // now delete the main pointer
        delete[] this->matrix;
    }
    template <typename T>
    T **Matrix<T>::generateMatrix(int demesional)
    {
        T **temp = new T *[demesional];
        for (int i = 0; i < demesional; i++)
        {
            temp[i] = new T[demesional];
        }
        return temp;
    }
    template <typename T>
    void Matrix<T>::set(int i, int j, T value)
    {
        if ((i >= 0 && i < this->demesional) && (j >= 0 && j < this->demesional))
        {
            this->matrix[i][j] = value;
        }
        else
        {

            cout << "One or Both Indexes in the Methode set() are not in bounds" << this->demesional << endl;
            exit(-1);
        }
    }

    template <typename T>
    const T Matrix<T>::getValueAt(int i, int j) const
    {
        return this->matrix[i][j];
    }

    template <typename T>
    int const Matrix<T>::getDem() const
    {
        return this->demesional;
    }

    template <typename T>
    void Matrix<T>::fillMatrix(int *src, int size)
    {
        if ((this->demesional * this->demesional) != size)
        {
            cout << "size of matrix is not equal to size of source array" << endl;
            exit(-1);
        }
        else
        {
            int pos = 0;
            for (int i = 0; i < this->demesional; i++)
            {
                for (int j = 0; j < this->demesional; j++)
                {
                    this->matrix[i][j] = src[pos++];
                }
            }
        }
    }

    template <typename T>
    void Matrix<T>::printMatrix()
    {
        for (int i = 0; i < this->demesional; i++)
        {
            for (int j = 0; j < demesional; j++)
            {
                cout << this->matrix[i][j] << "  ";
            }
            cout << endl;
        }
    }

    template <typename T>
    void Matrix<T>::transpose()
    {
        int **temp = generateMatrix(this->demesional);
        for (int i = 0; i < this->demesional; i++)
        {
            for (int j = 0; j < this->demesional; j++)
            {
                // saving the Trans Matrix in temp
                temp[i][j] = this->matrix[j][i];
            }
        }
        // deleting the Orginal Matrix
        for (int i = 0; i < this->demesional; i++)
        {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
        // setting the temp as an orginal Matrix
        this->matrix = temp;
        /*
    // we need to swap the cols and rows 
    int tmp_Swap = this->cols;
    this->cols= this->rows;
    this->rows = tmp_Swap;
    */
    }

    /*
int const Matrix::getNumberOfRows() {return this->rows;}
int const Matrix::getNumberOfCols() {return this->cols;}
*/

    template <typename T>
    void Matrix<T>::addMatrix(Matrix &m)
    {
        /*
    if(this->rows != m.getNumberOfRows() || this->cols != m.getNumberOfCols()){
        cout<<"Matrices should be same size in cols and rows"<<endl;
        exit(-1); 
    }
    */
        for (int i = 0; i < this->demesional; i++)
        {
            for (int j = 0; j < this->demesional; j++)
            {
                this->matrix[i][j] += m.getValueAt(i, j);
            }
        }
    }
    template <typename T>
    void Matrix<T>::subMatrix(Matrix &m)
    {
        /*
    if(this->rows != m.getNumberOfRows() || this->cols != m.getNumberOfCols()){
        cout<<"Matrices should be same size in cols and rows"<<endl;
        exit(-1); 
    } 
    */
        for (int i = 0; i < this->demesional; i++)
        {
            for (int j = 0; j < this->demesional; j++)
            {
                this->matrix[i][j] -= m.getValueAt(i, j);
            }
        }
    }

    template <typename T>
    Matrix<T> Matrix<T>::mulMatrix(Matrix &m)
    {
        if (this->demesional != m.getDem())
        {
            cout << "cann not Multiplicate this Matrices !! " << endl;
            exit(-1);
        }
        T **result = generateMatrix(this->demesional);

        for (int i = 0; i < this->demesional; ++i)
        {
            for (int j = 0; j < this->demesional; ++j)
            {
                for (int k = 0; k < this->demesional; ++k)
                {
                    result[i][j] += this->matrix[i][k] * m.getValueAt(k, j);
                }
            }
        }
        /*
    for(int i = 0 ; i<this->demesional; ++i){
        delete[] this->matrix[i];
    }
    */

        Matrix<T> erg(this->demesional);
        erg.matrix = result;
        return erg;
    }

}

#endif // _MATRIX_H_INCLUDED