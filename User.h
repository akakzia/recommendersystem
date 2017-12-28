#ifndef USER_H
#define USER_H
#include<iostream>
using namespace std;
#include<string>
#include<vector>
class User
{
    int id;
    int hId;
    vector<float> ratings;
public:
    User(int);
    User (int, int);
    User();
    void addRating(float);
    vector<float> getRatings()const;
    void getAvg();
    void assignRatings(vector<float>);
    int getId()const;
    int gethId()const;
};
#endif
