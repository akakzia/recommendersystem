#include"Rating.h"
#include<iostream>
using namespace std;
Rating::Rating(int r,int iU,int iM,int d){
    rate=r;
    idUser=iU;
    idMovie=iM;
    date=d;
}
int Rating::getRate()const{
    return rate;
}
int Rating::getIdUser()const{
    return idUser;
}
int Rating::getIdMovie()const{
    return idMovie;
}