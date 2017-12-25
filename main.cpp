#include <iostream>
#include<vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "Rating.h"
#include "Movie.h"
using namespace std;

Rating *fill_rating();
Movie  *fill_movies();

int main()
{


    //Movie function test
    Movie *M;
    M=fill_movies();
    cout<<M[5000].getId()<<" "<<M[5000].getTitle()<<endl;
    //Rating function test
    Rating *R;
    R=fill_rating();
    cout<<R[1].getIdUser()<<" "<<R[1].getIdMovie()<<" "<<R[100].getRate()<<endl;
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
    float id;
    string title;
    static Movie M[20000];

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
			loop++; //Does an increment to the variable 'loop'
		}
		in_stream.close(); //Closes the file
    return M;
}
/* Not done yet
User * fill_User(){ //creat set of all moies

    ifstream in_stream;
    int loop=1;
    string line;
    float id;
    string title;
    Movie *M = new Movie[10198]

    //Open input file.
    in_stream.open("/data/movies.dat");

    if (in_stream.fail())
    {
        cout << "Input file opening failed";
        exit(1);
    }

    while (! in_stream.eof() ) //Runs while the file is NOT at the end
		{
            getline(in_stream,line);//Gets a single line from file
			std::istringstream iss(line); //get numbers in the line
            iss >>id>>title;
            M[loop] = Movie(id,title);
			loop++; //Does an increment to the variable 'loop'
		}
		in_stream.close(); //Closes the file
    return M;
}*/
