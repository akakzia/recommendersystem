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
#include "CFAlgorithm.h"
#include<locale>
using namespace std;
CFAlgorithm::CFAlgorithm(string uAd,string mAd,string rAd):Algorithm(uAd, mAd, rAd){

}
CFAlgorithm::CFAlgorithm():Algorithm(){

}
void CFAlgorithm::learning(map<int,Movie> M, map<int,User> U){
    //Filling the matrix vector
    ifstream in_stream;
    string line;
    float rate;
    int movieid,userid;
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
            M_vector.setEl(M[movieid].gethId(),U[userid].gethId(),rate); //sets element rate at i= movieid and j= userid (i and j start from 1)
            M_2D.setEl(M[movieid].gethId(),U[userid].gethId(),rate); //sets element rate at i= movieid and j= userid (i and j start from 1)
            M_map.setEl(U[userid].gethId(),M[movieid].gethId(),rate); //sets element rate at i= movieid and j= userid (i and j start from 1)
		}
		in_stream.close(); //Closes the file
		cout << "Learning complete !" << "\n";
}

void CFAlgorithm::cfuser(map<int,User> allUsers,map<int,Movie> allMovies,int how){
    int user=0; //user to predict
    int index=0; //user index
    int movie; //movie to predict
    int index_m=0; //movie index
    float timeVector=0;
    float time2D=0;
    float timeMap=0;
    map<int,float> correlation;
    while ((index > 2113) or (index < 1)){
            cout << "Enter the id of the user you want to recommend to : ";
            cin >> user;
            index=allUsers[user].gethId(); // return what when not found ?
        }
        if (how==1){
            //Starts counting time for Matrix2D
            const clock_t begin_time1=clock();
            allUsers[user].assignRatings(M_2D.getColumn(index)); // add rating vector for the user
            time2D= time2D+float(clock()-begin_time1);//Gets the time and stops counting for input
            allUsers[user].getAvg(); //calculate avg and store it in ratings[0]
            vector<float> ratings=allUsers[user].getRatings(); //get user ratings
            while (((index_m > 10197) or (index_m < 1))or(ratings[index_m]!=0)){
                cout << "Enter the id of the movie to predict (Not seen before) : ";
                cin >> movie;
                index_m=allMovies[movie].gethId();
            }
            cout << "The chosen movie is " << allMovies[movie].getTitle() << "\n";
            //Calculate correlation with all the users and counting for Matrix2D
            const clock_t begin_time2=clock();//Continues getting time
            int loop=1;
            float temp;
            for (std::map<int,User>::iterator it=allUsers.begin(); it!=allUsers.end(); ++it){ //iterate over allusers
                    if ((it->first)!=user){ //except chosen user
                        it->second.assignRatings(M_2D.getColumn(loop));
                        if (it->second.getRatings()[index_m]!=0){//if movie watched
                            it->second.getAvg();
                            temp = cos_similarity(ratings,it->second.getRatings());
                            correlation.insert(std::pair<int,float>(it->first,temp));
                        }
                        loop++;
                    }
            }
            time2D= time2D+float(clock()-begin_time2);//Stops counting time, the rest is independent of matrix type
        }
        else if (how==2){
            //Starts counting time for Matrix2D
            const clock_t begin_time1=clock();
            allUsers[user].assignRatings(M_vector.getColumn(index)); // add rating vector for the user
            timeVector= timeVector+float(clock()-begin_time1);//Gets the time and stops counting for input
            allUsers[user].getAvg(); //calculate avg and store it in ratings[0]
            vector<float> ratings=allUsers[user].getRatings(); //get user ratings
            while (((index_m > 10197) or (index_m < 1))or(ratings[index_m]!=0)){
                cout << "Enter the id of the movie to predict (Not seen before) : ";
                cin >> movie;
                index_m=allMovies[movie].gethId();
            }
            cout << "The chosen movie is " << allMovies[movie].getTitle() << "\n";
            //Calculate correlation with all the users and counting for Matrix2D
            const clock_t begin_time2=clock();//Continues getting time
            int loop=1;
            float temp;
            for (std::map<int,User>::iterator it=allUsers.begin(); it!=allUsers.end(); ++it){ //iterate over allusers
                    if ((it->first)!=user){ //except chosen user
                        it->second.assignRatings(M_vector.getColumn(loop));
                        if (it->second.getRatings()[index_m]!=0){//if movie watched
                            it->second.getAvg();
                            temp = cos_similarity(ratings,it->second.getRatings());
                            correlation.insert(std::pair<int,float>(it->first,temp));
                        }
                        loop++;
                    }
            }
            timeVector= timeVector+float(clock()-begin_time2);//Stops counting time, the rest is independent of matrix type
        }
        else if (how==3){
            //Starts counting time for Matrix2D
            const clock_t begin_time1=clock();
            allUsers[user].assignRatings(M_map.getCol(user)); // add rating vector for the user
            timeMap= timeMap+float(clock()-begin_time1);//Gets the time and stops counting for input
            allUsers[user].getAvg(); //calculate avg and store it in ratings[0]
            vector<float> ratings=allUsers[user].getRatings(); //get user ratings
            while (((index_m > 10197) or (index_m < 1))or(ratings[index_m]!=0)){
                cout << "Enter the id of the movie to predict (Not seen before) : ";
                cin >> movie;
                index_m=allMovies[movie].gethId();
            }
            cout << "The chosen movie is " << allMovies[movie].getTitle() << "\n";
            //Calculate correlation with all the users and counting for Matrix2D
            const clock_t begin_time2=clock();//Continues getting time
            int loop=1;
            float temp;
            for (std::map<int,User>::iterator it=allUsers.begin(); it!=allUsers.end(); ++it){ //iterate over allusers
                    if ((it->first)!=user){ //except chosen user
                        it->second.assignRatings(M_map.getCol(loop));
                        if (it->second.getRatings()[index_m]!=0){//if movie watched
                            it->second.getAvg();
                            temp = cos_similarity(ratings,it->second.getRatings());
                            correlation.insert(std::pair<int,float>(it->first,temp));
                        }
                        loop++;
                    }
            }
            timeMap= timeMap+float(clock()-begin_time2);//Stops counting time, the rest is independent of matrix type
        }
        cout << correlation.size() << " Users have already watched this movie ! \n";
        //Handling neighborhood
        int N=-1;
        while ((N<1)or(N>correlation.size())){
            cout << "Select the size of your neighborhood (It must be lower than the range of watchers) : ";
            cin >> N;
        }
        //Predict the rate
        float pre_rate=predictRate(allUsers, correlation,index_m, N);
        cout << "The predicted rate for " << allMovies[movie].getTitle() << " is : " << pre_rate << "\n";
        if (pre_rate>3.5)
            cout << allMovies[movie].getTitle() <<" is HIGHLY recommended for the user !\n";
        else if (pre_rate>2.5)
            cout << allMovies[movie].getTitle() << " is recommended for the user !\n";
        else
            cout << allMovies[movie].getTitle() << " is NOT recommended for the user !\n";
        if (how==1)
            cout<<"Matrix2D tasks accomplished in "<<time2D/CLOCKS_PER_SEC<<" seconds"<<endl;
        if (how==2)
            cout<<"MatrixVector tasks accomplished in "<<timeVector/CLOCKS_PER_SEC<<" seconds"<<endl;
        if (how==3)
            cout<<"MatrixMap tasks accomplished in "<<timeMap/CLOCKS_PER_SEC<<" seconds"<<endl;
}

void CFAlgorithm::cfitem(map<int,User> allUsers,map<int,Movie> allMovies,int how){
    int user=0; //user to predict
    int index=0; //user index
    int movie; //movie to predict
    int index_m=0; //movie index
    map<int,float> correlation;
    float time2D=0;
    float timeVector=0;
    float timeMap=0;
    while ((index_m > 10197) or (index_m < 1)){
            LOOP://To handle unwatched movies
            cout << "Enter the id of the movie to predict (It must be rated) : ";
            cin >> movie;
            index_m = allMovies[movie].gethId();
        }
        if (how==1){
        //Starts counting time for Matrix2D
            const clock_t begin_time1=clock();
            allMovies[movie].assignRatings(M_2D.getRow(index_m));
            time2D=time2D+float(clock()-begin_time1);//Stops counting time
            allMovies[movie].getAvg();
            vector<float> ratings = allMovies[movie].getRatings();
            if (ratings[0]==0) {goto LOOP;}//If the movie is not watched, then we go back to loop
            while (((index > 2113)or(index < 1))or(ratings[index]!=0)){
                cout << "Enter the id of the user you want to recommend to (Not have seen the movie) : ";
                cin >> user;
                index=allUsers[user].gethId();
            }
            //Calculate correlation with all the movies
            //Resumes counting time for Matrix2D
            const clock_t begin_time2=clock();
            int loop=1;
            for (std::map<int,Movie>::iterator it=allMovies.begin(); it!=allMovies.end(); ++it){
                    if ((it->first)!=movie){
                        it->second.assignRatings(M_2D.getRow(loop));
                        if (it->second.getRatings()[index]!=0){//if movie watched
                            it->second.getAvg();
                            correlation.insert(std::pair<int,float>(it->first,cos_similarity(ratings,it->second.getRatings())));
                        }
                        loop++;
                    }
            }
            time2D=time2D+float(clock()-begin_time2);
        }
        else if (how==2){
        //Starts counting time for MatrixVector
            const clock_t begin_time1=clock();
            allMovies[movie].assignRatings(M_vector.getRow(index_m));
            timeVector=timeVector+float(clock()-begin_time1);//Stops counting time
            allMovies[movie].getAvg();
            vector<float> ratings = allMovies[movie].getRatings();
            if (ratings[0]==0) {goto LOOP;}//If the movie is not watched, then we go back to loop
            while (((index > 2113)or(index < 1))or(ratings[index]!=0)){
                cout << "Enter the id of the user you want to recommend to (Not have seen the movie) : ";
                cin >> user;
                index=allUsers[user].gethId();
            }
            //Calculate correlation with all the movies
            //Resumes counting time for Matrix2D
            const clock_t begin_time2=clock();
            int loop=1;
            for (std::map<int,Movie>::iterator it=allMovies.begin(); it!=allMovies.end(); ++it){
                    if ((it->first)!=movie){
                        it->second.assignRatings(M_vector.getRow(loop));
                        if (it->second.getRatings()[index]!=0){//if movie watched
                            it->second.getAvg();
                            correlation.insert(std::pair<int,float>(it->first,cos_similarity(ratings,it->second.getRatings())));
                        }
                        loop++;
                    }
            }
            timeVector=timeVector+float(clock()-begin_time2);
        }
        else if (how==3){
        //Starts counting time for MatrixVector
            const clock_t begin_time1=clock();
            allMovies[movie].assignRatings(M_map.getRow(index_m));
            timeMap=timeMap+float(clock()-begin_time1);//Stops counting time
            allMovies[movie].getAvg();
            vector<float> ratings = allMovies[movie].getRatings();
            if (ratings[0]==0) {goto LOOP;}//If the movie is not watched, then we go back to loop
            while (((index > 2113)or(index < 1))or(ratings[index]!=0)){
                cout << "Enter the id of the user you want to recommend to (Not have seen the movie) : ";
                cin >> user;
                index=allUsers[user].gethId();
            }
            //Calculate correlation with all the movies
            //Resumes counting time for Matrix2D
            const clock_t begin_time2=clock();
            int loop=1;
            for (std::map<int,Movie>::iterator it=allMovies.begin(); it!=allMovies.end(); ++it){
                    if ((it->first)!=movie){
                        it->second.assignRatings(M_map.getRow(loop));
                        if (it->second.getRatings()[index]!=0){//if movie watched
                            it->second.getAvg();
                            correlation.insert(std::pair<int,float>(it->first,cos_similarity(ratings,it->second.getRatings())));
                        }
                        loop++;
                    }
            }
            timeMap=timeMap+float(clock()-begin_time2);
        }
        cout << correlation.size() << " Movies have been watched by this user ! \n";
        //Handling neighborhood
        int N=-1;
        while ((N<1)or(N>correlation.size())){
            cout << "Select the size of your neighborhood (It must be lower than the range of inventory) : ";
            cin >> N;
        }
        //Predict the rate
        float pre_rate=predictRate(allMovies, correlation,index, N);
        cout << "The predicted rate for " << allMovies[movie].getTitle() << " is : " << pre_rate << "\n";
        if (pre_rate>3.5)
            cout << allMovies[movie].getTitle() <<" is HIGHLY recommended for the user !\n";
        else if (pre_rate>2.5)
            cout << allMovies[movie].getTitle() << " is recommended for the user !\n";
        else
            cout << allMovies[movie].getTitle() << " is NOT recommended for the user !\n";
        if (how==1)
            cout<<"Matrix2D tasks accomplished in "<<time2D/CLOCKS_PER_SEC<<" seconds"<<endl;
        if (how==2)
            cout<<"MatrixVector tasks accomplished in "<<timeVector/CLOCKS_PER_SEC<<" seconds"<<endl;
        if (how==3)
            cout<<"MatrixMap tasks accomplished in "<<timeMap/CLOCKS_PER_SEC<<" seconds"<<endl;
}

void CFAlgorithm::execute(int how){
    cout << "--------------------------------LOADING COLLABORATIVE FILTERING ALGORITHM--------------------------------\n\n";
    loadMovies();
    loadUsers();
    cout << allMovies.size() << " Movies and " << allUsers.size() <<" Users loaded !\n";
    learning(allMovies,allUsers);
    reuse:
    int method;
    cout << "Select a method of collaborative filtering :\n1/USER-USER\n2/ITEM-ITEM\n";
    ASSERT://Make sure the input is good
    cout << "Method : ";
    cin >> method;
    if ((method!=1)and(method!=2)) {goto ASSERT;}
    if (method==1){
        cfuser(allUsers,allMovies,how);
    }
    else if(method==2){
        cfitem(allUsers,allMovies,how);
    }
    int choice;
    cout << "\nSelect an action :\n1/Reuse\n2/Quit\n";
    cin >> choice;
    if (choice==1)
        goto reuse;
    else
        cout << "GOOD BYE !";
}

