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

Matrix read_data(){
    
    ifstream in_stream;
    int loop=1;
    string line;
    float a, b, c;

    //Check input and output file.
    in_stream.open("test.txt");

    if (in_stream.fail())
    {
        cout << "Input file opening failed";
        exit(1);
    }
    while (! in_stream.eof() ) //Runs while the file is NOT at the end
		{
            getline(in_stream,line);//Gets a single line from example.txt
			std::istringstream iss(line);
            iss >>a>>b>>c;
            cout<<a<<" "<<b<<" "<<c<<endl; //Saves that line in the array
			loop++; //Does an increment to the variable 'loop'
		}
		in_stream.close(); //Closes the file

}