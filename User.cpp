#include"User.h"
#include<iostream>
#include<vector>
#include <numeric>
#include <functional>

using namespace std;
User::User(int i){
    id=i;
    ratings.push_back(0.0);
    //for(int i=0;i<16529;i++){ profile.push_back(i);}
}
User::User(int i, int h){
    id=i;
    hId=h;
    ratings.push_back(0.0);
    //for(int i=0;i<16529;i++){ profile.push_back(i);}
}
User::User(){}
void User::addRating(float r){
    ratings.push_back(r);
}
vector<float> User::getRatings()const{
    return ratings;
}
void User::getAvg(){

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

void User::setProfile(map <int,Movie> M){
    map<int, float> m_p;
    int n=0;
    cout<<"Setting Profile..."<<endl;
    for(std::map<int,float>::iterator it=M[1].getProfile().begin(); it !=M[1].getProfile().end();it++){
        profile.insert(pair<int,float>(it->first,0));
    }

    for(std::map<int,Movie>::iterator it=M.begin(); it !=M.end();it++){
        if (ratings[it->second.gethId()]!=0){
            n++;
            m_p=it->second.getProfile();
            for(std::map<int,float>::iterator i = m_p.begin(); i != m_p.end(); ++i){
                profile[it->first]=profile[i->first]+ratings[it->second.gethId()]*m_p[i->first];
            }
        }
    }
    for (std::map<int,float>::iterator it = profile.begin(); it != profile.end(); ++it){
        it->second=it->second/n;
    }
    cout<<"Profile set!"<<endl;
}

map<int,float> User::getProfile()const{
    return profile;
}
