#ifndef USER_H
#define USER_H
#include<iostream>
using namespace std;
#include<string>
#include<vector>
class User
{
    int id;
    vector<float> ratings;
public:
    User(int id);
    User();
    void addRating(float);
    vector<float> getRatings()const;
    void getAvg();
    void assignRatings(vector<float>);
    int getId()const;
};
#endif
