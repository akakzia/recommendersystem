#ifndef MOVIE_H
#define MOVIE_H
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include <map>
class Movie
{
    int id;
    int hId;
    string title;
    vector <float> ratings;
    map <int, float> profile;
public:
    Movie(int id,string title);
    Movie (int,int,string);
    Movie();

    void addRating(float);
    string getTitle()const;
    vector<float> getRatings()const;
    void assignRatings(vector<float>);
    void getAvg();
    int getId()const;
    int gethId()const;
    Movie& operator=(Movie&);
    void setTag(int,float);
    map <int, float> getProfile()const;

};
#endif
