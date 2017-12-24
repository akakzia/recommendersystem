#include <iostream>
#include<vector>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "Movie.h"
using namespace std;

Matrix read_data();

int main()
{
    Movie M(1, "Home", "today", "ii");
    M.addRating(5);
    vector<float> s=M.getRating();
    cout << s.size();
    return 0;
}

Rating * fill_rating(){ //creat set of all ratings
    
    ifstream in_stream;
    int loop=1;
    string line;
    float rate,movieid,userid;
    Rating *R = new Rating[855599]

    //Open input file.
    in_stream.open("/data/user_ratedmovies-timestamps.dat");

    if (in_stream.fail())
    {
        cout << "Input file opening failed";
        exit(1);
    }

    while (! in_stream.eof() ) //Runs while the file is NOT at the end
		{
            getline(in_stream,line);//Gets a single line from file
			std::istringstream iss(line); //get numbers in the line
            iss >>user>>movie>>rate;
            R[loop] = Rating(rate,user,movie);
			loop++; //Does an increment to the variable 'loop'
		}
		in_stream.close(); //Closes the file
    return R;
}

Rating * fill_rating(){ //creat set of all movies
    
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
}