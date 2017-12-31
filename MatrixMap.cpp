#include"MatrixMap.h"
#include<iostream>
#include<map>
#include<vector>
using namespace std;
MatrixMap::MatrixMap(int l, int c):Matrix(l,c)
{
    vector<float> temp;
    for (int j=0; j<c;j++){
        temp.push_back(0.0);
    }
    for (int i=0; i<l;i++){
        data.insert(std::pair<int,vector<float> >(i,temp));
    }
}
MatrixMap::MatrixMap():Matrix(10198,2114)
{
    vector<float> temp;
    for (int j=0; j<dimCol;j++){
        temp.push_back(0.0);
    }
    for (int i=0; i<dimRow;i++){
        data.insert(std::pair<int,vector<float> >(i,temp));
    }
}
float MatrixMap::getEl(int i, int j)const{
    return data.at(i).at(j);
}
void MatrixMap::setEl(int i, int j, float e){
    data.at(i).at(j)=e;
}
vector<float> MatrixMap::getRow(int c){
    data.at(c).insert(data.at(c).begin(), 0.0);
    return data.at(c);
}

vector<float> MatrixMap::getCol(int c){
    vector <float> column;
    for(int i=0;i<dimRow;i++){
        column.push_back(data.at(i).at(c));
    }
    return column;
}


