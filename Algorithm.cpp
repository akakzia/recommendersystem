#include "Algorithm.h"


Algorithm::Algorithm(string uAd,string mAd,string rAd){
    userFileAddress = uAd;
    movieFileAddress = mAd;
    ratingFileAddress = rAd;
}
Algorithm::Algorithm(){

}
Algorithm::~Algorithm(){
    M_map.~MatrixMap();
    M_2D.~Matrix2D();
    M_vector.~MatrixVector();
    allMovies.clear();
    allUsers.clear();
}
//Load Movies in Map : used .csv instead of .dat faster access to data
void Algorithm::loadMovies(){
    std::ifstream file(movieFileAddress.c_str());
    std::string line,line1,line2;
    ifstream in_stream;
    std::getline(file, line);
    int row=1;
    int id;
    int movieid,tagid;
    float tag_weight;

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
        allMovies.insert(std::pair<int,Movie>(id,O));
        row++;
    }

    //Open input file.
    in_stream.open("data/movie_tags.dat");

    if (in_stream.fail())
    {
        cout << "Input file opening failed";
        exit(1);
    }
    getline(in_stream,line1);
    while (! in_stream.eof() ) //Runs while the file is NOT at the end
		{
            getline(in_stream,line1);//Gets a single line from file
			std::istringstream iss(line1); //get numbers in the line
            iss >>movieid>>tagid>>tag_weight;
            allMovies[movieid].setTag(tagid,tag_weight);
		}
		in_stream.close(); //Closes the file
    cout << "Movies loading succeeded!" << "\n";
}

//Load Users in Map : .csv gets full Title because its ; separated
void Algorithm::loadUsers(){
    std::ifstream file(userFileAddress.c_str());
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
            allUsers.insert(std::pair<int,User>(id,O));
            temp=id;
            row++;
        }

    }
    cout << "Users loading succeeded !" << "\n";
}

void Algorithm::loadRatings(){ //create vector of all ratings

    ifstream in_stream;
    string line;
    float rate,movieid,userid;

    //Open input file.
    in_stream.open(ratingFileAddress.c_str());

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
            allRatings.push_back(Rating(rate,userid,movieid));
		}
		in_stream.close(); //Closes the file
}
map<int, float> Algorithm::getNeighbors(map<int, float> mymap, int N){
    map<int,float> temp=mymap;
    map<int,float> res;
    int maximum;
    for (int i=0;i<N;i++){
        maximum=0;
        temp[maximum]=-2;
        for (std::map<int,float>::iterator it=temp.begin(); it!=temp.end(); ++it){
            if (it->second > temp[maximum]){
                maximum=it->first;
            }
        }
        res.insert(std::pair<int,float>(maximum,temp[maximum]));
        temp.erase(maximum);
    }
    return res;
}
void Algorithm::execute(int m){
}

void Algorithm::learning_vector(map<int,Movie> M, map<int,User> U){
    //Filling the matrix vector
    ifstream in_stream;
    string line;
    float rate;
    int movieid,userid;
    cout << "Learning for Vector Matrix in progress ..." << "\n";
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
		}
		in_stream.close(); //Closes the file
		cout << "Learning complete !" << "\n";
}

void Algorithm::learning_2D(map<int,Movie> M, map<int,User> U){
    //Filling the matrix vector
    ifstream in_stream;
    string line;
    float rate;
    int movieid,userid;
    cout << "Learning for 2D Matrix in progress ..." << "\n";
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
            M_2D.setEl(M[movieid].gethId(),U[userid].gethId(),rate); //sets element rate at i= movieid and j= userid (i and j start from 1)
		}
		in_stream.close(); //Closes the file
		cout << "Learning complete !" << "\n";
}

void Algorithm::learning_map(map<int,Movie> M, map<int,User> U){
    //Filling the matrix vector
    ifstream in_stream;
    string line;
    float rate;
    int movieid,userid;
    cout << "Learning for Map Matrix in progress ..." << "\n";
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
            M_map.setEl(U[userid].gethId(),M[movieid].gethId(),rate); //sets element rate at i= movieid and j= userid (i and j start from 1)
		}
		in_stream.close(); //Closes the file
		cout << "Learning complete !" << "\n";
}
