#include "CFAlgorithm.h"
#include "CBAlgorithm.h"
using namespace std;


int main()
{
    int a,s;
    string uAd="data/user_taggedmovies.csv";
    string mAd="data/movies.csv";
    string rAd="data/user_ratedmovies-timestamps.dat";
    cout<<"Which algorithm you want to use?"<<endl<<"1-Collaborative Filtering: Predicts the rate of movie A for user B (15s-1min)."<<endl<<"2-Content Based: Predicts top 10 recommended movies for user A (1-3min)."<<endl;
    cin>>a;
    cout<<"Which structure you want to use?"<<endl<<"1-2D"<<endl<<"2-Vector"<<endl<<"3-Map"<<endl;
    cin>>s;
    if (a==1){
        CFAlgorithm Algo(uAd,mAd,rAd);
        Algo.execute(s);
    }
    else if(a==2){
        CBAlgorithm Al(uAd,mAd,rAd);
        Al.execute(s);
    }

    return 0;
}
