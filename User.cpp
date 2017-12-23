#include"User.h"
#include<iostream>
#include<vector>
using namespace std;
User::User(int i,int a,string occ){
    id=i;
    age=a;
    occupation=occ;
    ratings.push_back(0.0);
}
void User::addRating(float r){
    ratings.push_back(r);
}
vector<float> User::getRatings()const{
    return ratings;
}
void User::getAvg(){
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