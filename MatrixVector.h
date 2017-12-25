#ifndef MATRIXVECTOR_H
#define MATRIXVECTOR_H
#include<iostream>
using namespace std;
#include<vector>
#include "Matrix.h"
class MatrixVector:public Matrix //Matrice organisée en vector
{
    vector<float> data;
public:
    MatrixVector(int,int);
    ~MatrixVector();
    float getEl(int,int)const;
    void setEl(int,int,float);
};
#endif
