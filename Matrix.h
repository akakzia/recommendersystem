#ifndef MATRIX_H
#define MATRIX_H

#include<vector>

using namespace std;

class Matrix //Classe abstraite
{
public:
    int dimCol;
    int dimRow;
protected:
    Matrix(int,int);
    Matrix();
public:
    int getdimCol();
    int getdimRow();
    virtual float getEl(int,int)const;
    virtual void setEl(int,int,float);
    virtual vector<float> getRow(int);
    virtual vector<float> getColumn(int);
};
#endif
