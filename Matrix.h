#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
using namespace std;
#include<vector>
class Matrix //Classe abstraite
{
protected:
    int dimCol;
    int dimRow;
    Matrix(int,int);
    Matrix();
public:
    virtual float getEl(int,int)const;
    virtual void setEl(int,int,float);
};
#endif