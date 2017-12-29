#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
using namespace std;
#include<vector>
class Matrix //Classe abstraite
{
public:
    int dimCol;
    int dimRow;
protected:
    Matrix(int,int);
    Matrix();
public:
    virtual float getEl(int,int)const;
    virtual void setEl(int,int,float);
    virtual vector<float> getColumn(int);
    int getdimCol();
    int getdimRow();
    virtual vector<float> getRow(int);
};
#endif
