#ifndef MATRIXMAP_H
#define MATRIXMAP_H
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
    MatrixMap();
    ~MatrixMap();
    float getEl(int,int)const;
    void setEl(int,int,float);
    vector<float> getRow(int);
    vector<float> getColumn(int);
};
#endif
