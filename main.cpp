#include "CFAlgorithm.h"

using namespace std;


int main()
{
    string uAd="data/user_taggedmovies.csv";
    string mAd="data/movies.csv";
    string rAd="data/user_ratedmovies-timestamps.dat";
    CFAlgorithm Algo(uAd,mAd,rAd);
    Algo.execute();
    return 0;
}
