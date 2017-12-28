#ifndef MOVIE_H
#define MOVIE_H
#include<iostream>
using namespace std;
#include<string>
#include<vector>
class Movie
{
    int id;
    int hId;
    string title;
    vector<float> ratings;
public:
    Movie(int id,string title);
    Movie (int,int,string);
    Movie();
    void addRating(float);
    string getTitle()const;
    vector<float> getRatings()const;
    void getAvg();
    int getId()const;
    int gethId()const;
};
#endif
