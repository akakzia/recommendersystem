#include<iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include<string>
#include<map>
#include <math.h>
#include "Movie.h"
#include "Rating.h"
#include "User.h"
#include "MatrixVector.h"
#include "Matrix2D.h"
#include "MatrixMap.h"
#include "Algorithm.h"
using namespace std;
Algorithm::Algorithm(string uAd,string mAd,string rAd){
    userFileAddress = uAd;
    movieFileAddress = mAd;
    ratingFileAddress = rAd;
}
Algorithm::Algorithm(){

}
//Algorithm::~Algorithm(){}
//Load Movies in Map : used .csv instead of .dat faster access to data
void Algorithm::loadMovies(){
    std::ifstream file(movieFileAddress.c_str());
    std::string line,line1;
    ifstream in_stream;
    std::getline(file, line);
    int row=1;
    int id;
    int movieid,tagid;
    float tag_weight;

    cout << "Loading movies..." << "\n";
    while (file.good())
    {

        std::getline(file, line);
        if ( !file.good() )
            break;

        std::stringstream iss(line);
        std::string val;
        std::getline(iss, val, ';');
        if ( !iss.good() )
            break;

        std::stringstream convertor(val);
        convertor >> id;
        std::getline(iss, val, ';');
        if ( !iss.good() )
            break;
        Movie O(id,row,val);
        allMovies.insert(std::pair<int,Movie>(id,O));
        row++;
    }
    //Open input file.
    in_stream.open("data/movie_tags.dat");

    if (in_stream.fail())
    {
        cout << "Input file opening failed";
        exit(1);
    }
    getline(in_stream,line1);
    while (! in_stream.eof() ) //Runs while the file is NOT at the end
		{
            getline(in_stream,line1);//Gets a single line from file
			std::istringstream iss(line1); //get numbers in the line
            iss >>movieid>>tagid>>tag_weight;
            allMovies[movieid].setTag(tagid,tag_weight);
		}
		in_stream.close(); //Closes the file

    cout << "Movies loading succeeded!" << "\n";
}

//Load Users in Map : .csv gets full Title because its ; separated
void Algorithm::loadUsers(){
    std::ifstream file(userFileAddress.c_str());
    std::string line;
    std::getline(file, line);
    int row=1;
    int id;
    int temp=0;
    cout << "Loading users..." << "\n";
    while (file.good())
    {
        std::getline(file, line);
        if ( !file.good() )
            break;
        std::stringstream iss(line);
        std::string val;
        std::getline(iss, val, ';');
        if ( !iss.good() )
            break;
        std::stringstream convertor(val);
        convertor >> id;
        while (id!=temp){
            User O(id,row);
            allUsers.insert(std::pair<int,User>(id,O));
            temp=id;
            row++;
        }

    }
    cout << "Users loading succeeded !" << "\n";
}

void Algorithm::loadRatings(){ //create vector of all ratings

    ifstream in_stream;
    string line;
    float rate,movieid,userid;

    //Open input file.
    in_stream.open(ratingFileAddress.c_str());

    if (in_stream.fail())
    {
        cout << "Input file opening failed";
        exit(1);
    }
    getline(in_stream,line);
    while (! in_stream.eof() ) //Runs while the file is NOT at the end
		{
            getline(in_stream,line);//Gets a single line from file
			std::istringstream iss(line); //get numbers in the line
            iss >>userid>>movieid>>rate;
            allRatings.push_back(Rating(rate,userid,movieid));
		}
		in_stream.close(); //Closes the file
}
float Algorithm::cos_similarity(vector<float> U1,vector<float>U2){
    float a=0;
    float b=0;
    float c=0;
    int i=1;
    int j1=0,j2;
    float avg_U1=0;
    float avg_U2=0;

    while (i<U1.size()){
        if (U1.at(i)!=0){
            j1++;
            avg_U2+=U2[i];
        }
        if (U2.at(i)!=0){
            j2++;
            avg_U2+=U2[i];
        }
        i++;
    }
    for (int i=1; i<U1.size(); i++){
        a=a+((U1[i]!=0)*(U1[i]-avg_U1))*((U2[i]-avg_U2)*(U2[i]!=0));
        b=b+((U1[i]!=0)*(U1[i]-avg_U1))*(U1[i]-avg_U1);
        c=c+((U2[i]-avg_U2)*(U2[i]!=0))*(U2[i]-avg_U2);
    }
        b=sqrt(b);
        c=sqrt(c);
        float r;
        if(b*c!=0)
        {
            r=a/(b*c);
            return r;
        }
        else {
            return 0;
        }
}

map<int, float> Algorithm::getNeighbors(map<int, float> mymap, int N){
    map<int,float> temp=mymap;
    map<int,float> res;
    int maximum;
    for (int i=0;i<N;i++){
        maximum=0;
        temp[maximum]=-2;
        for (std::map<int,float>::iterator it=temp.begin(); it!=temp.end(); ++it){
            if (it->second > temp[maximum]){
                maximum=it->first;
            }
        }
        res.insert(std::pair<int,float>(maximum,temp[maximum]));
        temp.erase(maximum);
    }
    return res;
}
float Algorithm::predictRate(map<int,User> U, map<int,float> c,int m, int v){
    map<int,float> neigh=this->getNeighbors(c, v);
    float num=0;
    float denom=0;
    for (std::map<int,float>::iterator it=neigh.begin(); it!=neigh.end(); ++it){
        num=num + it->second*U[it->first].getRatings()[m];
        denom=denom + it->second;
    }
        return num/denom;
}
float Algorithm::predictRate(map<int,Movie> M, map<int,float> c,int m, int v){
    map<int,float> neigh=this->getNeighbors(c, v);
    float num=0;
    float denom=0;
    std::map<int,float>::iterator it;
    for (it=neigh.begin(); it!=neigh.end(); ++it){
        num=num + it->second*M[it->first].getRatings()[m];
        denom=denom + it->second;
    }
        return num/denom;
}
void Algorithm::learning(map<int,Movie> M, map<int,User> U){

}
void Algorithm::execute(){
}
