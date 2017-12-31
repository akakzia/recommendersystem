#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <map>
#include <vector>

#include"Movie.h"
#include"Rating.h"
#include"User.h"
//Useless

//Load Movies in Map : used .csv instead of .dat faster access to data
map<int,Movie> loadMovies(){
    map<int,Movie> M;
    std::ifstream file("data/movies.csv");
    std::string line;
    std::getline(file, line);
    int row=1;
    int id;
    cout << "Loading movies..." << "\n";
    while (file.good())
    {

        std::getline(file, line);
        if ( !file.good() )
            break;

        std::stringstream iss(line);
        std::string val;
        std::getline(iss, val, ';');
        if ( !iss.good() )
            break;

        std::stringstream convertor(val);
        convertor >> id;
        std::getline(iss, val, ';');
        if ( !iss.good() )
            break;
        Movie O(id,row,val);
        M.insert(std::pair<int,Movie>(id,O));
        row++;
    }
    cout << "Movies loading succeeded!" << "\n";
    return M;
}

//Load Users in Map : .csv gets full Title because its ; separated
map<int,User> loadUsers(){
    map<int,User> U;
    std::ifstream file("data/user_taggedmovies.csv");
    std::string line;
    std::getline(file, line);
    int row=1;
    int id;
    int temp=0;
    cout << "Loading users..." << "\n";
    while (file.good())
    {
        std::getline(file, line);
        if ( !file.good() )
            break;
        std::stringstream iss(line);
        std::string val;
        std::getline(iss, val, ';');
        if ( !iss.good() )
            break;
        std::stringstream convertor(val);
        convertor >> id;
        while (id!=temp){
            User O(id,row);
            U.insert(std::pair<int,User>(id,O));
            temp=id;
            row++;
        }

    }
    cout << "Users loading succeeded !" << "\n";
    return U;
}

vector<Rating> loadRatings(){ //create vector of all ratings

    ifstream in_stream;
    string line;
    float rate,movieid,userid;
    vector<Rating> R;

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
            R.push_back(Rating(rate,userid,movieid));
		}
		in_stream.close(); //Closes the file
    return R;
}
