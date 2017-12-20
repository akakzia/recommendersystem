#ifndef SIMILARITY_H
#define SIMILARITY_H
#include<vector>
#include<iostream>
using namespace std;
class Similarity
{
public:
    Similarity();
    float cos_similarity(vector<float>,vector<float>);
};
#endif
