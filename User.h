#ifndef USER_H
#define USER_H

using namespace std;
#include<string>
#include <map>
#include<iostream>
#include<vector>
#include "Movie.h"

class User
{
    int id;
    int hId;
    vector <float> ratings;
    map<int,float> profile;
public:
    User();
    User(int);
    User(int, int);
    ~User();
    void addRating(float);
    vector<float> getRatings()const;
    void getAvg();
    void assignRatings(vector<float>);
    int getId()const;
    int gethId()const;
    void setProfile(map <int,Movie>);
    map<int, float> getProfile()const;
};
#endif
