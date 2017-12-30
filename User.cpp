#include"User.h"
#include<iostream>
#include<vector>
#include <numeric>
#include <functional>

using namespace std;
User::User(int i){
    id=i;
    ratings.push_back(0.0);
}
User::User(int i, int h){
    id=i;
    hId=h;
    ratings.push_back(0.0);
}
User::User(){}
void User::addRating(float r){
    ratings.push_back(r);
}
vector<float> User::getRatings()const{
    return ratings;
}
void User::getAvg(){

    //float avg = accumulate( ratings.begin(), ratings.end(), 0.0);
    //cout<<avg<<" "<<ratings.size()<<endl;
    //ratings[0] = avg/(ratings.size()-1);

    int i=1;
    int j=0;
    float sum=0;
    while (i<ratings.size()){
        if (ratings.at(i)!=0){
            j++;
            sum+=ratings[i];
        }
        i++;
    }
    ratings[0]=sum/j;
}
void User::assignRatings(vector<float> r){
    ratings=r;
}
int User::getId()const{
    return id;
}
int User::gethId()const{
    return hId;
}
