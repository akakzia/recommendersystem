#include"MatrixMap.h"
#include<iostream>
#include<map>
#include<vector>
using namespace std;
MatrixMap::MatrixMap(int l, int c):Matrix(l,c){
    dimRow=l;
    dimCol=c;
    int i,j;
    for (i=0; i<l;i++){
        for (j=0; j<c;j++){
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