#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
using namespace std;
#include<vector>
class Matrix //Matrice organisée en vector
{
    int dimCol;
    int dimRow;
    vector<float> data;
public:
    Matrix(int,int);
    ~Matrix();
    float getEl(int,int)const;
    void setEl(int,int,float);
};
#endif