#include <iostream>

using namespace std;

class Matrix;

class MatrixOperations {
public:
    static Matrix add(const Matrix& m1, const Matrix& m2);
    static Matrix multiply(const Matrix& m1, const Matrix& m2);
};

class Matrix {
private:
    int rows, columns;
    int elements[10][10];

public:
    Matrix(int rows, int columns) : rows(rows), columns(columns) {}

    void inputMatrix() {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                cin >> elements[i][j];
    }

    void displayMatrix() const {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }

    friend Matrix MatrixOperations::add(const Matrix& m1, const Matrix& m2);
    friend Matrix MatrixOperations::multiply(const Matrix& m1, const Matrix& m2);
};

Matrix MatrixOperations::add(const Matrix& m1, const Matrix& m2) {
    Matrix result(m1.rows, m1.columns);

    for (int i = 0; i < m1.rows; ++i)
        for (int j = 0; j < m1.columns; ++j)
            result.elements[i][j] = m1.elements[i][j] + m2.elements[i][j];

    return result;
}

Matrix MatrixOperations::multiply(const Matrix& m1, const Matrix& m2) {
    Matrix result(m1.rows, m2.columns);

    for (int i = 0; i < m1.rows; ++i)
        for (int j = 0; j < m2.columns; ++j)
            for (int k = 0; k < m1.columns; ++k)
                result.elements[i][j] += m1.elements[i][k] * m2.elements[k][j];

    return result;
}

int main() {
    int rows, columns;

    cout << "Enter the dimensions of matrices:" << endl;
    cout << "Rows: ";
    cin >> rows;
    cout << "Columns: ";
    cin >> columns;

    Matrix matrix1(rows, columns), matrix2(rows, columns);

    cout << "Matrix 1:" << endl;
    matrix1.inputMatrix();

    cout << "Matrix 2:" << endl;
    matrix2.inputMatrix();

    Matrix sum = MatrixOperations::add(matrix1, matrix2);
    Matrix product = MatrixOperations::multiply(matrix1, matrix2);

    cout << "Matrix Addition Result:" << endl;
    sum.displayMatrix();

    cout << "Matrix Multiplication Result:" << endl;
    product.displayMatrix();

    return 0;
}
