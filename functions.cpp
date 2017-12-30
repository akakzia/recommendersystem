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



MatrixMap learning_Map(map<int,Movie> M, map<int,User> U){
    ifstream in_stream;
    string line;
    float rate;
    int movieid,userid;
    MatrixMap M_Utility(10198,2114); //allocate memory, with extra row to store averages
    cout << "Learning in progress ..." << "\n";
    in_stream.open("data/user_ratedmovies-timestamps.dat"); //Open input file.

    if (in_stream.fail()) //check if file failed to open
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
            M_Utility.setEl(M[movieid].gethId(),U[userid].gethId(),rate); //sets element rate at i= movieid and j= userid (i and j start from 1)
		}
		in_stream.close(); //Closes the file
		cout << "Learning completed. Utility Matrix is ready for predict." << "\n";
		return M_Utility;
}

Matrix2D learning_2D(map<int,Movie> M, map<int,User> U){
    ifstream in_stream;
    string line;
    float rate;
    int movieid,userid;
    Matrix2D M_Utility(10198,2114); //allocate memory, with extra row to store averages
    cout << "Learning in progress ..." << "\n";
    in_stream.open("data/user_ratedmovies-timestamps.dat"); //Open input file.

    if (in_stream.fail()) //check if file failed to open
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
            M_Utility.setEl(M[movieid].gethId(),U[userid].gethId(),rate); //sets element rate at i= movieid and j= userid (i and j start from 1)
		}
		in_stream.close(); //Closes the file
		cout << "Learning completed. Utility Matrix is ready for predict." << "\n";
		return M_Utility;
}

MatrixVector learning_Vector(map<int,Movie> M, map<int,User> U){ //Fills the matrix directly from the ratings file
    ifstream in_stream;
    string line;
    float rate;
    int movieid,userid;
    MatrixVector M_Utility(10198,2114); //allocate memory, with extra row to store averages
    cout << "Learning in progress ..." << "\n";
    //Open input file.
    in_stream.open("data/user_ratedmovies-timestamps.dat"); //open input file

    if (in_stream.fail())   //check if file failed to open
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
            M_Utility.setEl(M[movieid].gethId(),U[userid].gethId(),rate); //sets element rate at i= movieid and j= userid (i and j start from 1)
		}
		in_stream.close(); //Closes the file
		cout << "Learning completed. Utility Matrix is ready for predict." << "\n";
		return M_Utility;
}

float cos_similarity(vector<float> U1,vector<float> U2){
    float avg_U1, avg_U2;
    float a=0;
    float b=0;
    float c=0;
    avg_U1=U1[0];
    avg_U2=U2[0];
    int i;
    for (i=1; i<U1.size(); i++){
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
        else return 0;
}

map<int, float> getNeighbors(map<int, float> mymap, int N){
    map<int,float> temp=mymap;
    map<int,float> res;
    int maximum;
    for (int i=0;i<N;i++){
        maximum=0;
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

float predictRate(map<int,User> U, map<int,float> c,int m, int v){
    map<int,float> neigh=getNeighbors(c, v);
    float num=0;
    float denom=0;
    for (std::map<int,float>::iterator it=neigh.begin(); it!=neigh.end(); ++it){
        num=num + it->second*U[it->first].getRatings()[m];
        denom=denom + it->second;
    }
        return num/denom;
}

float predictRate(map<int,Movie> M, map<int,float> c,int m, int v){
    map<int,float> neigh=getNeighbors(c, v);
    float num=0;
    float denom=0;
    std::map<int,float>::iterator it;
    for (it=neigh.begin(); it!=neigh.end(); ++it){
        num=num + it->second*M[it->first].getRatings()[m];
        denom=denom + it->second;
    }
        return num/denom;
}

void CFuser(map<int,User> allUsers,map<int,Movie> allMovies,MatrixVector U){
    int user=0; //user to predict
    int index=allUsers[user].gethId(); //user index
    while ((index > 2113) or (index < 1)){
        cout << "Enter the id of the user you want to recommend to : ";
        cin >> user;
        index=allUsers[user].gethId(); // return what when not found ?
    }
    allUsers[user].assignRatings(U.getColumn(index)); // add rating vector for the user
    allUsers[user].getAvg(); //calculate avg and store it in ratings[0]
    vector<float> ratings=allUsers[user].getRatings(); //get user ratings
    int movie; //movie to predict
    int index_m=0; //movie index
    while (((index_m > 10197) or (index_m < 1))or(ratings[index_m]!=0)){
        cout << "Enter the id of the movie to predict (Not seen before) : ";
        cin >> movie;
        index_m=allMovies[movie].gethId();
    }
    //Calculate correlation with all the users
    map<int,float> correlation;
    int loop=1;
    for (std::map<int,User>::iterator it=allUsers.begin(); it!=allUsers.end(); ++it){ //iterate over allusers
            if ((it->first)!=user){ //except chosen user
                it->second.assignRatings(U.getColumn(loop));
                if (it->second.getRatings()[index_m]!=0){//if movie watched
                    it->second.getAvg();
                    correlation.insert(std::pair<int,float>(it->first,cos_similarity(ratings,it->second.getRatings())));
                }
                loop++;
            }
    }
    cout << correlation.size() << " Users have already watched this movie ! \n";
    //Handling neighborhood
    int N;
    cout << "Select the size of your neighborhood : ";
    cin >> N;
    //Predict the rate
    float pre_rate=predictRate(allUsers, correlation,index_m, N);
    cout << "The predicted rate for " << allMovies[movie].getTitle() << " is : " << pre_rate << "\n";
    if (pre_rate>3.5)
        cout << allMovies[movie].getTitle() <<" is HIGHLY recommended for the user !";
    else if (pre_rate>2.5)
        cout << allMovies[movie].getTitle() << " is recommended for the user !";
    else
        cout << allMovies[movie].getTitle() << " is NOT recommended for the user !";
}

void CFmovie(map<int,User> allUsers,map<int,Movie> allMovies,MatrixVector U){
    int user = 0;
    int index = allUsers[user].gethId();
    int movie;
    int index_m = 0;
    while ((index_m > 10197) or (index_m < 1)){
        cout << "Enter the id of the movie to predict : ";
        cin >> movie;
        index_m = allMovies[movie].gethId();
    }
    allMovies[movie].assignRatings(U.getRow(index_m));
    allMovies[movie].getAvg();
    vector<float> ratings = allMovies[movie].getRatings();
    while (((index > 2113)or(index < 1))or(ratings[index]!=0)){
        cout << "Enter the id of the user you want to recommend to (Not have seen the movie) : ";
        cin >> user;
        index=allUsers[user].gethId();
    }
    //Calculate correlation with all the movies
    map<int,float> correlation;
    int loop=1;
    for (std::map<int,Movie>::iterator it=allMovies.begin(); it!=allMovies.end(); ++it){
            if ((it->first)!=movie){
                it->second.assignRatings(U.getRow(loop));
                if (it->second.getRatings()[index]!=0){//if movie watched
                    it->second.getAvg();
                    correlation.insert(std::pair<int,float>(it->first,cos_similarity(ratings,it->second.getRatings())));
                }
                loop++;
            }
    }
    cout << correlation.size() << " Movies have been watched by this user ! \n";
    //Handling neighborhood
    int N;
    cout << "Select the size of your neighborhood : ";
    cin >> N;
    //Predict the rate
    float pre_rate=predictRate(allMovies, correlation,index, N);
    cout << "The predicted rate for " << allMovies[movie].getTitle() << " is : " << pre_rate << "\n";
    if (pre_rate>3.5)
        cout << allMovies[movie].getTitle() <<" is HIGHLY recommended for the user !";
    else if (pre_rate>2.5)
        cout << allMovies[movie].getTitle() << " is recommended for the user !";
    else
        cout << allMovies[movie].getTitle() << " is NOT recommended for the user !";
}








/*
MatrixVector Similarity_Vector(MatrixVector U){
    MatrixVector S(U.getdimCol(),U.getdimCol());
    for(int i=0;i<S.getdimCol();i++){
            cout<<"user ="<<i<<endl;
            vector<float> user_i=U.getColumn(i);
            float avg_i = accumulate( user_i.begin(), user_i.end(), 0.0)/user_i.size();
            for(std::vector<float>::iterator it = user_i.begin(); it != user_i.end(); ++it) {
                *it=(*it!=0)?*it-avg_i:*it;
            }
        for (int j=0; j<S.getdimCol();j++){
            vector<float> user_j=U.getColumn(j);
            float avg_j = accumulate( user_j.begin(), user_j.end(), 0.0)/user_j.size();
            for(std::vector<float>::iterator it = user_j.begin(); it != user_j.end(); ++it) {
                *it= (*it!=0)?*it-avg_j:*it;
            }
            S.setEl(i,j,cos_similarity(user_i,user_j));
        }
    }
    return S;
}
*/
