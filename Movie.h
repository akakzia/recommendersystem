#ifndef MOVIE_H
#define MOVIE_H
#include<iostream>
using namespace std;
#include<string>
#include<vector>
class Movie
{
    int id;
    string title;
    vector<float> ratings;
public:
    Movie(int id,string title);
    Movie();
    void addRating(float);
    string getTitle()const;
    vector<float> getRatings()const;
    void getAvg();
    int getId()const;
};
#endif
