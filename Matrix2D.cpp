#include"Matrix2D.h"

Matrix2D::Matrix2D(int rows, int columns):Matrix(rows,columns) {
    data = new float*[dimRow]();
    for(int i = 0; i < dimRow; ++i)
    data[i] = new float[dimCol];
    for (int i=0; i<dimRow;i++){
        for (int j=0;j<dimCol;j++)
            data[i][j]=0;
    }
}
Matrix2D::Matrix2D():Matrix(10198,2114) {
    data = new float*[dimRow]();
    for(int i = 0; i < dimRow; ++i)
    data[i] = new float[dimCol];
    for (int i=0; i<dimRow;i++){
        for (int j=0;j<dimCol;j++)
            data[i][j]=0;
    }
}
Matrix2D::~Matrix2D() {
    if (data) {
        delete[] data;
    }
}

void Matrix2D::setEl(int i,int j,float value){
    data[i][j] = value;
}
float Matrix2D::getEl(int i, int j)const{
    return data[i][j];
}

vector<float> Matrix2D::getColumn(int c){
    vector<float> column;
    for(int i=0;i<dimRow;i++){
        column.push_back(this->getEl(i,c));
    }
    return column;
}
vector<float> Matrix2D::getRow(int r){
    vector<float> row;
    for(int i=0;i<dimCol;i++){
        row.push_back(data[r][i]);
    }
    return row;
}
