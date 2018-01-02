#include"User.h"
#include<iostream>
#include<vector>
#include <numeric>
#include <functional>

using namespace std;
User::User(int i){
    id=i;
    ratings.push_back(0.0);
    for(int i=0;i<16529;i++){ profile.push_back(i);}
}
User::User(int i, int h){
    id=i;
    hId=h;
    ratings.push_back(0.0);
    for(int i=0;i<16529;i++){ profile.push_back(i);}
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
    vector <float> m_p;
    int n=0;
    cout<<M.size()<<endl;
    for(std::map<int,Movie>::iterator it=M.begin(); it !=M.end();it++){
        if (ratings[it->second.gethId()]!=0){
            n++;
            m_p=it->second.getProfile();
            for(int i=0;i<m_p.size();i++){
                profile.at(i)=profile.at(i)+ratings[it->second.gethId()]*m_p.at(i);
            }
        }
    }
    std::transform(profile.begin(), profile.end(), profile.begin(),std::bind1st(std::multiplies<float>(),1/n));
    cout<<"done"<<endl;
}

vector<float> User::getProfile(){
    return profile;
}
