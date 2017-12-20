#include"Similarity.h"
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
Similarity::Similarity(){}
float Similarity::cos_similarity(vector<float> U1,vector<float> U2)
{
    float avg_U1, avg_U2;
    float a=0;
    float b=0;
    float c=0;
    avg_U1=U1[0];
    avg_U2=U2[0];
    int i;
    for (i=1; i<U1.size(); i++){
        if ((U1[i]!=0)and(U2[i]!=0)){
            a=a+(U1[i]-avg_U1)*(U2[i]-avg_U2);
            b=b+(U1[i]-avg_U1)*(U1[i]-avg_U1);
            c=c+(U2[i]-avg_U2)*(U2[i]-avg_U2);
        }
        b=sqrt(b);
        c=sqrt(c);
        float r;
        if(b*c!=0)
        {
            r=a/(b*c);
            return r;
        }
        else return 0;
    }
}