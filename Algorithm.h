#ifndef ALGORITHM_H
#define ALGORITHM_H
#include<iostream>
using namespace std;
#include"User.h"
#include"Movie.h"
#include<string>
class Algorithm
{
protected:
    string userFileAddress;
    string movieFileAddress;
    string ratingFileAddress;
    Algorithm(string userFileAddress,string movieFileAddress,string ratingFileAddress);
    Algorithm();
public:
    virtual int predictRate(int,int);
};
#endif