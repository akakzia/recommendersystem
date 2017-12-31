#ifndef Matrix2D_H
#define Matrix2D_H

#include<iostream>
using namespace std;

#include "Matrix.h"

class Matrix2D:public Matrix {
private:
    float** data;
    int totalSize;
public:
    Matrix2D(int,int); // base ctor.
    Matrix2D();
    ~Matrix2D(); // dtor.
    float getEl(int,int) const;
    void setEl(int,int,float);
    vector<float> getColumn(int);
    vector<float> getRow(int);

};
#endif
