#include"Movie.h"
#include<iostream>
#include<vector>
using namespace std;
Movie::Movie(int i,string t/*,string r,string u*/)
{
    id=i;
    title=t;
    //releaseDate=r;
    //URL=u;
    ratings.push_back(0);
}
Movie::Movie(){};

/*void Movie::addRating(float r)
{
    ratings.push_back(r);
}*/
vector<float> Movie::getRating()const
{
    return ratings;
}
string Movie::getTitle()const
{
    return title;
}
int Movie::getId()const{
    return id;
}
void Movie::getAvg(){
    int i=1;
    int j=0;
    float sum;
    while (i<ratings.size()){
        if (ratings.at(i)!=0){
            j++;
            sum+=ratings[i];
        }
        i++;
    }
    ratings[0]=sum/j;
}

