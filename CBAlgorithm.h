#ifndef CBALGORITHM_H
#define CBALGORITHM_H

#include<iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
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
#include<locale>
using namespace std;


class CBAlgorithm: public Algorithm{

public:
    CBAlgorithm(string,string,string);
    CBAlgorithm();
    void execute();
    float cos_similarity(vector <float>,vector <float> );
};

#endif // CBALGORITHM_H
