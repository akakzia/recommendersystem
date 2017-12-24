#include <iostream>
#include<vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "Rating.h"
#include "Movie.h"
using namespace std;

Rating* fill_rating();
//Movie * fill_movies();

int main()
{

    Rating *R;
    R=fill_rating();
    //R=fill_rating();
    //Movie M(1, "Home", "today", "ii");
    //M.addRating(5);
    //vector<float> s=M.getRating();
    //cout << s.size();
    return 0;
}

//fct tekhdem ama ma3raftech na3mel return shih
Rating* fill_rating(){ //create set of all ratings

    ifstream in_stream;
    int loop=0;
    string line;
    float rate,movieid,userid;
    Rating R[11];

    //Open input file.
    in_stream.open("r.dat");

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
/*
Movie * fill_movies(){ //create set of all movies

    ifstream in_stream;
    int loop=1;
    string line;
    float id;
    string title;
    Movie *M[10198];

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
            M[loop] = new Movie(id,title);
			loop++; //Does an increment to the variable 'loop'
		}
		in_stream.close(); //Closes the file
    return *M;
}

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
