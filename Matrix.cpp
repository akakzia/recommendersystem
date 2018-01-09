#include"Matrix.h"
#include<iostream>
#include<vector>
using namespace std;
Matrix::Matrix(int rows ,int columns){
    dimCol = columns;
    dimRow = rows ;
}
Matrix::Matrix(){}

float Matrix::getEl(int i,int j)const
{
    return 0;
}
void Matrix::setEl(int i,int j,float e)
{
}
vector<float> Matrix::getColumn(int i)
{
}


int Matrix::getdimCol(){
    return dimCol;
}
int Matrix::getdimRow(){
    return dimRow;
}
vector<float> Matrix::getRow(int i)
{
}
