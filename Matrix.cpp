#include"Matrix.h"
#include<iostream>
#include<vector>
using namespace std;
Matrix::Matrix(int l,int c)
{
    dimRow=l;
    dimCol=c;
    int i;
    for (i=0; i<dimRow*dimCol; i++)
    {
        data.push_back(0);
    }
}
float Matrix::getEl(int i,int j)const
{
    return data.at(i*dimCol+j);
}
void Matrix::setEl(int i,int j,float e)
{
    data.at(i*dimCol+j)=e;
}
