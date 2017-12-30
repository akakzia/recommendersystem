#include "Rating.h"
#include "Movie.h"
#include "User.h"
#include "Matrix.h"
#include "Matrix2D.h"
#include "MatrixMap.h"
#include "MatrixVector.h"
#include "functions.h"
#include "Data.h"

using namespace std;


int main()
{

    map<int,Movie> allMovies;
    allMovies = loadMovies();
    map<int,User> allUsers;
    allUsers = loadUsers();
    int n = allUsers.size();
    int m = allMovies.size();
    MatrixVector U(n+1,m+1);
    U=learning_Vector(allMovies,allUsers);
    int method=-1;
    cout << "Select the method :\n1/Collaborative Filtering user-user\n2/Collaborative filtering movie-movie\n";
    while ((method!=1)and(method!=2)){cin >> method;}
    if (method==1){
        //USER-USER
        CFuser(allUsers,allMovies,U);
    }
    else {
        //MOVIE-MOVIE
        CFmovie(allUsers,allMovies,U);
    }
    return 0;
}
