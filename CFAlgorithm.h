#ifndef CFALGORITHM_H
#define CFALGORITHM_H
#include<iostream>
using namespace std;
#include"User.h"
#include"Movie.h"
#include"Algorithm.h"
#include"Matrix.h"
#include"MatrixVector.h"
#include"MatrixMap.h"
#include"Matrix2D.h"
#include<string>
/*This class is a child of Algorithm. The execution of the algorithm will be inside this class and it won't have children.
No time for handling indirect heritage. I tried it but there were problems and I did not have time to google them
I handled both Matrix2D and MatrixVector and put timer for each execution. Then it will output the time in order to compare.
The destructors are still not implemented */
class CFAlgorithm: public Algorithm
{
public:
    MatrixVector M_vector;
    Matrix2D M_2D;
    MatrixMap M_map;
    CFAlgorithm(string userFileAddress,string movieFileAddress,string ratingFileAddress);
    CFAlgorithm();
    void cfuser(map<int,User>,map<int,Movie>,int);
    void cfitem(map<int,User>,map<int,Movie>,int);
    //~CFAlgorithm();
public:
    void learning(map<int,Movie>, map<int,User>);
    void execute(int);
};
#endif
