#ifndef MATRIXMAP_H
#define MATRIXMAP_H
#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include "Matrix.h"
class MatrixMap:public Matrix //Matrice organisée en map
{
public:
    map<int,vector<float> > data;
public:
    MatrixMap(int,int);
    float getEl(int,int)const;
    void setEl(int,int,float);
};
#endif
