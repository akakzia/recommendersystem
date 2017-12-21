#include"MatrixVector.h"
#include<iostream>
#include<vector>
using namespace std;
MatrixVector::MatrixVector(int l,int c):Matrix(l,c)
{
    dimRow=l;
    dimCol=c;
    int i;
    for (i=0; i<dimRow*dimCol; i++)
    {
        data.push_back(0);
    }
}
float MatrixVector::getEl(int i,int j)const
{
    return data.at(i*dimCol+j);
}
void MatrixVector::setEl(int i,int j,float e)
{
    data.at(i*dimCol+j)=e;
}
