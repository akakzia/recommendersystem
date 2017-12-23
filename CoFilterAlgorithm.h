#ifndef COLFILTERALGORITHM_H
#define COLFILTERALGORITHM_H
#include<iostream>
using namespace std;
#include"Algorithm.h"
#include"Matrix.h"
#include<vector>
class ColFilterAlgorithm: public Algorithm
{
    Matrix U;
    Matrix A;
};
#endif