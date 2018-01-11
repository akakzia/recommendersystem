#include "MatrixMap.h"

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
MatrixMap::MatrixMap():Matrix(2114,10198)
{
    vector<float> temp;
    for (int j=0; j<dimCol;j++){
        temp.push_back(0.0);
    }
    for (int i=0; i<dimRow;i++){
        data.insert(std::pair<int,vector<float> >(i,temp));
    }
}
MatrixMap::~MatrixMap(){
    data.clear();
}
float MatrixMap::getEl(int i, int j)const{
    return data.at(i).at(j);
}
void MatrixMap::setEl(int i, int j, float e){
    data.at(i).at(j)=e;
}
vector<float> MatrixMap::getColumn(int c){
    return data[c];
}

vector<float> MatrixMap::getRow(int c){
    vector <float> column;
    for(int i=0;i<dimRow;i++){
        column.push_back(data.at(i).at(c));
    }
    return column;
}


