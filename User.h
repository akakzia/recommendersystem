#ifndef USER_H
#define USER_H
#include<iostream>
using namespace std;
#include<string>
#include<vector>
class User
{
    int id;
    int age;
    string occupation;
    vector<float> ratings;
public:
    User(int id,int age,string occupation);
    void addRating(float);
    vector<float> getRatings()const;
    void getAvg();
};
#endif
