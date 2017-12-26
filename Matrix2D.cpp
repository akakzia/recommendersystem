#include"Matrix2D.h"
#include<iostream>
using namespace std;

Matrix2D::Matrix2D(int rows, int columns):Matrix(rows,columns) {
    totalSize = dimCol * dimRow;
    data = new float*[dimRow]();
    for(int i = 0; i < dimRow; ++i)
    data[i] = new float[dimCol];
}
Matrix2D::~Matrix2D() {
    if (data) {
        delete[] data;
    }
}

void Matrix2D::setEl(int i,int j,float value){
    data[i][j] = value;
}
float Matrix2D::getEl(int i, int j)const{
    return data[i][j];
}
