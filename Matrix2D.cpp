#include"MatrixMap.h"
#include<iostream>
using namespace std;

Matrix2D::Matrix2D(int rows, int columns) : m_rows(rows), m_columns(columns) {
    m_totalSize = m_rows * m_columns;
    m_ptValues = new int[m_totalSize]();
}
CMatrix::~CMatrix() {
    if (m_ptValues) {
        delete[] m_ptValues;
    }

