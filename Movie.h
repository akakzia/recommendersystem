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
    //string releaseDate;
    //string URL;
    vector<float> ratings;
public:
    Movie(int id,string title/*,string releaseDate,string URL*/);
    Movie();
    //void addRating(float);
    string getTitle()const;
    int getId()const;
    vector<float> getRating()const;
    void getAvg();
    void setRatings(vector<float>);
};
#endif
