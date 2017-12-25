#ifndef USER_H
#define USER_H
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include "Rating.h"

class User
{
    int id;
    //int age;
    //string occupation;
    vector<float> ratings;
public:
    User(int id/*,int age,string occupation*/);
    User();
    //void addRating(float);
    vector<float> getRatings()const;
    void getAvg();
    int getId();
    void setRatings(vector<float>);
};
#endif
