#include"MatrixMap.h"
#include<iostream>
#include<map>
#include<vector>
using namespace std;
MatrixMap::MatrixMap(int rows, int columns):Matrix(rows,columns){
    int i,j;
    for (i=0; i<rows;i++){
        for (j=0; j<columns;j++){
            (data.at(i)).at(j)=0;
        }
    }
}
float MatrixMap::getEl(int i, int j)const{
    return (data.at(i)).at(j);
}
void MatrixMap::setEl(int i, int j, float e){
    (data.at(i)).at(j)=e;
}
