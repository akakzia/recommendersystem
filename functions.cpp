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
//Useless

float cos_similarity(vector<float> U1,vector<float> U2){
    float avg_U1, avg_U2;
    float a=0;
    float b=0;
    float c=0;
    avg_U1=U1[0];
    avg_U2=U2[0];
    int i;
    for (i=1; i<U1.size(); i++){
        a=a+((U1[i]!=0)*(U1[i]-avg_U1))*((U2[i]-avg_U2)*(U2[i]!=0));
        b=b+((U1[i]!=0)*(U1[i]-avg_U1))*(U1[i]-avg_U1);
        c=c+((U2[i]-avg_U2)*(U2[i]!=0))*(U2[i]-avg_U2);
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


MatrixVector Similarity_Vector(MatrixVector U){

    cout<<"calculating similarity..."<<endl;
    MatrixVector S(U.getdimCol()-1,U.getdimCol()-1);
    for(int i=1;i<U.dimCol;i++){
        int size_= 0;
        float sum = 0;
        vector <float> a=U.getColumn(i);
        for (std::vector<float>::iterator it=a.begin(); it!=a.end(); ++it){
            (*it!=0)?size_++:0;
            sum+=*it;
        }
        U.setEl(0,i,sum/size_);
    }
    for(int i=0;i<S.getdimCol();i++){
        cout<<"i="<<i<<endl;
        for(int j=1;j<S.getdimCol();j++){
            S.setEl(i,j,cos_similarity(U.getColumn(i+1),U.getColumn(j+1)));
        }
    }
    cout<<"silimarity calculated!"<<endl;
    return S;
}
