#include"Movie.h"
#include<iostream>
#include<vector>
using namespace std;
Movie::Movie(int i,string t,string r,string u)
{
    id=i;
    title=t;
    releaseDate=r;
    URL=u;
    rating.push_back(0);
}
void Movie::addRating(float r)
{
    rating.push_back(r);
}
vector<float> Movie::getRating()const
{
    return rating;
}
string Movie::getTitle()const
{
    return title;
}

