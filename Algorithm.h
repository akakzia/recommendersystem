#ifndef ALGORITHM_H
#define ALGORITHM_H
#include<iostream>
using namespace std;
#include"Rating.h"
#include"User.h"
#include"Movie.h"
#include<string>
#include<map>
class Algorithm
{
protected:
    map<int,User> allUsers;
    map<int,Movie> allMovies;
    vector<Rating> allRatings;
    string userFileAddress;
    string movieFileAddress;
    string ratingFileAddress;
    Algorithm(string,string,string);
    Algorithm();
    //~Algorithm();
public:
    void loadRatings();
    void loadMovies();
    void loadUsers();
    float cos_similarity(vector<float>,vector<float>);
    map<int, float> getNeighbors(map<int, float>, int);
    float predictRate(map<int,User>, map<int,float>,int, int);
    float predictRate(map<int,Movie>, map<int,float>,int, int);
    virtual void learning(map<int,Movie>, map<int,User>);
    virtual void execute();
};
#endif
