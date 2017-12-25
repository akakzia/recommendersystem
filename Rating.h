#ifndef RATING_H
#define RATING_H
#include<iostream>
using namespace std;
#include<string>
#include<vector>
class Rating
{
    float rate;
    int idUser;
    int idMovie;
public:
    Rating(float rate,int idUser,int idMovie);
    float getRate()const;
    int getIdUser()const;
    int getIdMovie()const;
};
#endif
