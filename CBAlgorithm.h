#ifndef CBALGORITHM_H
#define CBALGORITHM_H

#include<iostream>
#include<string>
#include<map>
#include <math.h>
#include "Movie.h"
#include "Rating.h"
#include "User.h"
#include "MatrixVector.h"
#include "Matrix2D.h"
#include "MatrixMap.h"
#include "Algorithm.h"
using namespace std;


class CBAlgorithm: public Algorithm{

public:
    CBAlgorithm(string,string,string);
    CBAlgorithm();
    float cos_similarity(map <int, float>,map <int, float>);
    map <int,float> getTop(map <int,float>,int);
    void execute(int);

};

#endif // CBALGORITHM_H
