#ifndef Matrix2D_H
#define Matrix2D_H


class Matrix2D:public Matrix {
private:
    int* m_ptValues;
    int m_totalSize;
public:
    Matrix2D(int rows, int columns); // base ctor.
    //Matrix2D(const Matrix2D& rhs); // copy ctor.
    //CMatrix& operator=(const CMatrix& rhs); // assign. ctor.
    ~Matrix2D(); // dtor.
    int& operator()(int row, int column);
    int& operator()(int row, int column) const;
};
#endif