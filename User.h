#ifndef USER_H
#define USER_H
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include <map>
#include "Movie.h"
#include <algorithm>
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
