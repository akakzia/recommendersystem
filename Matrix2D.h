#ifndef Matrix2D_H
#define Matrix2D_H

#include<iostream>
using namespace std;

#include "Matrix.h"

class Matrix2D:public Matrix {
private:
    int* m_ptValues;
    int m_totalSize;
public:
    Matrix2D(int rows, int columns); // base ctor.
    ~Matrix2D(); // dtor.
    float getEl(int,int) const;
    void setEl(int,int,float);
};
#endif