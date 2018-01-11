#ifndef MATRIXVECTOR_H
#define MATRIXVECTOR_H
using namespace std;
#include<vector>
#include "Matrix.h"
class MatrixVector:public Matrix //Matrice organisée en vector
{
    vector<float> data;
public:
    MatrixVector(int,int);
    MatrixVector();
    MatrixVector( const MatrixVector &obj);
    ~MatrixVector();
    float getEl(int,int)const;
    void setEl(int,int,float);
    vector<float> getColumn(int);
    vector<float> getRow(int);
};
#endif
