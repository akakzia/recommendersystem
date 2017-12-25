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

public:
    Matrix(int,int);
    //virtual float getEl(int,int)const ;
    //virtual void setEl(int,int,float);
    int getdimCol();
    int getdimRow();
};
#endif
