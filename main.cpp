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

    //Movie function test
    /*Movie *M;
    M=fill_movies();
    cout<<M[10196].getId()<<" "<<M[10196].getTitle()<<endl;
    cout<<H_movies_id[6323]<<endl;*/
    //Rating function test
    /*Rating *R;
    R=fill_rating();
    cout<<R[855597].getIdUser()<<" "<<R[855597].getIdMovie()<<" "<<R[855597].getRate()<<endl;*/
    //User function test
    /*User *U;
    U=fill_User();
    cout<<U[2112].getId()<<endl;
    cout<<H_users_id[267]<<endl;*/
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



//Temchi to93ed 15
Rating *fill_rating(){ //create set of all ratings

    ifstream in_stream;
    int loop=0;
    string line;
    float rate,movieid,userid;
    static Rating R[855598];

    //Open input file.
    in_stream.open("data/user_ratedmovies-timestamps.dat");

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
            R[loop] =Rating(rate,userid,movieid);
			loop++; //Does an increment to the variable 'loop'
		}
		in_stream.close(); //Closes the file
    return R;
}
// Temchi
Movie  *fill_movies(){ //create set of all movies

    ifstream in_stream;
    int loop=0;
    string line;
    int id;
    string title;
    static Movie M[10197];

    //Open input file.
    in_stream.open("data/movies.dat");

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
            iss>>id>>title;
            M[loop] = Movie(id,title);
            H_movies_id.insert(pair <int,int> (id,loop));
			loop++; //Does an increment to the variable 'loop'
		}
		in_stream.close(); //Closes the file
    return M;
}
User *fill_User(){ //creat set of all moies

    ifstream in_stream;
    int loop=0,loop2=0;
    string line;
    float userid;
    static User U[2113];

    //Open input file.
    in_stream.open("data/user_ratedmovies-timestamps.dat");

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
            iss >>userid;
            if (userid!=U[loop2-1].getId()){

            U[loop2] =User(userid);
            H_users_id.insert(pair <int,int> (userid,loop2));
            loop2++;

            }
			loop++; //Does an increment to the variable 'loop'
		}
		in_stream.close(); //Closes the file
    return U;
}
