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
    //int date;
public:
    Rating(int rate,int idUser,int idMovie/*,int date*/);
    Rating();
    int getRate()const;
    int getIdUser()const;
    int getIdMovie()const;
    int setRate(int);
    int setIdUser(int);
    int setIdMovie(int);
};
#endif
