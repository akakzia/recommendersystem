#include"MatrixVector.h"
#include<iostream>
#include<vector>
using namespace std;
MatrixVector::MatrixVector(int l,int c):Matrix(l,c)
{
    for (int i=0; i<l*c; i++)
    {
        data.push_back(0);
    }
}
MatrixVector::MatrixVector():Matrix(10198,2114)
{
    for (int i=0; i<dimRow*dimCol; i++)
    {
        data.push_back(0);
    }
}
MatrixVector::MatrixVector( const MatrixVector &obj){
    dimCol = obj.dimCol;
    dimRow = obj.dimRow;
    data=obj.data;
}

float MatrixVector::getEl(int i,int j)const
{
    return data.at(i*dimCol+j);
}
void MatrixVector::setEl(int i,int j,float e)
{
    data.at(i*dimCol+j)=e;
}
vector<float> MatrixVector::getColumn(int j){
    vector<float> c;
    for (int i=0; i<dimRow; i++){
        c.push_back(this->getEl(i,j));
    }
    return c;
}
vector<float> MatrixVector::getRow(int i){
    vector<float> l;
    for (int j=0; j<dimCol; j++){
        l.push_back(this->getEl(i,j));
    }
    return l;
}
