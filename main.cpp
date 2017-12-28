#include <iostream>
#include<vector>
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

int main()
{
    /*
    //Movie function test
    Movie *M;
    M=fill_movies();
    cout<<M[10196].getId()<<" "<<M[10196].getTitle()<<endl;
    cout<<H_movies_id[6323]<<endl;
    //Rating function test
    Rating *R;
    R=fill_rating();
    cout<<R[855597].getIdUser()<<" "<<R[855597].getIdMovie()<<" "<<R[855597].getRate()<<endl;
    //User function test
    User *U;
    U=fill_User();
    cout<<U[2112].getId()<<endl;
    cout<<H_users_id[267]<<endl;
    */
    //Load Movies in map
    /*map<int,Movie> allMovies;
    allMovies=loadMovies();*/
    //Load Users in map
    /*map<int,User> allUsers;
    allUsers=loadUsers();*/
    // Test learning and fill matrix U;
    map<int,Movie> allMovies;
    allMovies=loadMovies();
    map<int,User> allUsers;
    allUsers=loadUsers();
    int n=allUsers.size();
    int m=allMovies.size();
    MatrixVector U(n+1,m+1);
    U=learning(allMovies,allUsers);
    cout<<U.getEl(1,32)<<endl;//Test
    return 0;
}
