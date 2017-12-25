#include"MatrixMap.h"
#include<iostream>
#include<map>
#include<vector>
using namespace std;
MatrixMap::MatrixMap(int l, int c):Matrix(l,c)
{
    dimRow=l;
    dimCol=c;
    int i,j;
    vector<float> temp;
    for (j=0; j<c+1;j++){//Ajout d'une case pour stocker la valeur moyenne
        temp.push_back(0.0);
    }
    for (i=0; i<l;i++){
        data.insert(std::pair<int,vector<float> >(i,temp));
    }
}
float MatrixMap::getEl(int i, int j)const{
    return data.at(i).at(j);
}
void MatrixMap::setEl(int i, int j, float e){
    data.at(i).at(j)=e;
}
