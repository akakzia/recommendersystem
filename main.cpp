#include "CFAlgorithm.h"
#include "CBAlgorithm.h"
using namespace std;


int main()
{
    map <int,float> p;
    //cout<<p[15];
    string uAd="data/user_taggedmovies.csv";
    string mAd="data/movies.csv";
    string rAd="data/user_ratedmovies-timestamps.dat";
    CFAlgorithm Algo(uAd,mAd,rAd);
    //CBAlgorithm Al(uAd,mAd,rAd);
    Algo.execute(1);//1 for Matrix2D - 2 for MatrixVector - 3 for MatrixMap
    //Al.execute(1);
    return 0;
}
