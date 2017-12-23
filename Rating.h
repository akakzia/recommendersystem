#ifndef RATING_H
#define RATING_H
#include<iostream>
using namespace std;
#include<string>
#include<vector>
class Rating
{
    int rate;
    int idUser;
    int idMovie;
    int date;
public:
    Rating(int rate,int idUser,int idMovie,int date);
    int getRate()const;
    int getIdUser()const;
    int getIdMovie()const;
};
#endif