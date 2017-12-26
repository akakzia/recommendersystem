#include"Matrix.h"
#include<iostream>
#include<vector>
using namespace std;
Matrix::Matrix(int rows ,int columns){
    dimCol = columns;
    dimRow = rows ;
}

float Matrix::getEl(int i,int j)const
{
    return 0;
}
void Matrix::setEl(int i,int j,float e)
{
}
Matrix::Matrix(){}


int Matrix::getdimCol(){
    return dimCol;
}
int Matrix::getdimRow(){
    return dimRow;
}
vector<float> Matrix::getRow(int i)
{
}
