#include"Matrix2D.h"
#include<iostream>
using namespace std;

Matrix2D::Matrix2D(int rows, int columns):Matrix(rows,columns) {
    dimCol = rows;
    dimRow = columns ;
    m_totalSize = dimCol * dimRow;
    m_ptValues = new int[m_totalSize]();
}
Matrix2D::~Matrix2D() {
    if (m_ptValues) {
        delete[] m_ptValues;
    }
}
