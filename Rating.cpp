#include"Rating.h"
#include<iostream>
using namespace std;
Rating::Rating(float r,int iU,int iM){
    rate=r;
    idUser=iU;
    idMovie=iM;
}
Rating::Rating(){}
float Rating::getRate()const{
    return rate;
}
int Rating::getIdUser()const{
    return idUser;
}
int Rating::getIdMovie()const{
    return idMovie;
}
