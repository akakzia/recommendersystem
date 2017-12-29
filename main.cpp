#include <iostream>
#include<vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "Rating.h"
#include "Movie.h"
#include "User.h"
#include "Matrix.h"
#include "Matrix2D.h"
#include "MatrixMap.h"
#include "MatrixVector.h"
#include "Similarity.h"
#include "functions.h"
using namespace std;

Rating *fill_rating();
Movie  *fill_movies();
User *fill_User();
map<int,int> H_movies_id;
map<int,int> H_users_id;

int main()
{

    map<int,Movie> allMovies;
    allMovies=loadMovies();
    map<int,User> allUsers;
    allUsers=loadUsers();
    int n=allUsers.size();
    int m=allMovies.size();
    MatrixVector U(n+1,m+1);
    U=learning(allMovies,allUsers);
    int a=0;
    int index=allUsers[a].gethId();
    while ((index > 2113) or (index < 1)){
        cout << "Enter the id of the user you want to recommend to : ";
        cin >> a;
        index=allUsers[a].gethId();
    }
    allUsers[a].assignRatings(U.getColumn(index));
    allUsers[a].getAvg();
    vector<float> c=allUsers[a].getRatings();
    int mo;
    int indexm=0;
    while (((indexm > 10197) or (indexm < 1))or(c[mo]!=0)){
        cout << "Enter the id of the movie to predict (Not seen before) : ";
        cin >> mo;
        indexm=allMovies[mo].gethId();
    }
    //Calculate correlation with all the users
    Similarity S;

    map<int,float> correlation;
    int loop=1;
    for (std::map<int,User>::iterator it=allUsers.begin(); it!=allUsers.end(); ++it){
            if ((it->first)!=a){
                it->second.assignRatings(U.getColumn(loop));
                if (it->second.getRatings()[mo]!=0){//if movie watched
                    it->second.getAvg();
                    vector<float> d=it->second.getRatings();

                    correlation.insert(std::pair<int,float>(it->first,S.cos_similarity(U.getColumn(index),U.getColumn(loop))));
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
    float e=predictRate(allUsers, correlation,mo, N);
    cout << "The predicted rate for " << allMovies[mo].getTitle() << " is : " << e << "\n";
    if (e>3.5)
        cout << allMovies[mo].getTitle() <<" is HIGHLY recommended for the user !";
    else if (e>2.5)
        cout << allMovies[mo].getTitle() << " is recommended for the user !";
    else
        cout << allMovies[mo].getTitle() << " is NOT recommended for the user !";
    return 0;
}
