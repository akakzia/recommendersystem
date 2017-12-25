#include "Matrix.h"

Matrix::Matrix(int rows ,int columns){
    dimCol = columns;
    dimRow = rows ;
}
int Matrix::getdimCol(){
    return dimCol;
}
int Matrix::getdimRow(){
    return dimRow;
}
