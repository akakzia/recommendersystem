#include<string>
#include<map>
#include<iostream>
#include"Movie.h"
#include"Rating.h"
#include"User.h"
#include"Similarity.h"
#include"MatrixVector.h"
#include <fstream>
#include <cstdlib>
#include <sstream>
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
MatrixVector learning(map<int,Movie> M, map<int,User> U){ //Fills the matrix directly from the ratings file
    ifstream in_stream;
    string line;
    float rate;
    int movieid,userid;
    MatrixVector P(10198,2114);
    static Rating R[855598];
    cout << "Learning in progress ..." << "\n";
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
            P.setEl(M[movieid].gethId(),U[userid].gethId(),rate);
            //M[movieid].addRating(rate);
            //U[userid].addRating(rate);//Will be used to calculate average later on
		}
		in_stream.close(); //Closes the file
		cout << "Learning completed. Utility Matrix is ready for predict." << "\n";
		return P;
}
map<int, float> getNeighbors(map<int, float> mymap, int N){
    map<int,float> temp=mymap;
    map<int,float> res;
    int maximum;
    for (int i=0;i<N;i++){
        maximum=0;
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
float predictRate(map<int,User> U, map<int,float> c,int m, int v){
    map<int,float> neigh=getNeighbors(c, v);
    float num=0;
    float denom=0;
    std::map<int,float>::iterator it;
    for (it=neigh.begin(); it!=neigh.end(); ++it){
        num=num + it->second*U[it->first].getRatings()[m];
        denom=denom + it->second;
    }
        return num/denom;
}
float predictRate(map<int,Movie> U, map<int,float> c,int m, int v){
    map<int,float> neigh=getNeighbors(c, v);
    float num=0;
    float denom=0;
    std::map<int,float>::iterator it;
    for (it=neigh.begin(); it!=neigh.end(); ++it){
        num=num + it->second*U[it->first].getRatings()[m];
        denom=denom + it->second;
    }
        return num/denom;
}

void CFuser(map<int,User> allUsers,map<int,Movie> allMovies,MatrixVector U){
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
    while (((indexm > 10197) or (indexm < 1))or(c[indexm]!=0)){
        cout << "Enter the id of the movie to predict (Not seen before) : ";
        cin >> mo;
        indexm=allMovies[mo].gethId();
    }
    //Calculate correlation with all the users
    map<int,float> correlation;
    int loop=1;
    Similarity S;
    for (std::map<int,User>::iterator it=allUsers.begin(); it!=allUsers.end(); ++it){
            if ((it->first)!=a){
                it->second.assignRatings(U.getColumn(loop));
                if (it->second.getRatings()[indexm]!=0){//if movie watched
                    it->second.getAvg();
                    vector<float> d=it->second.getRatings();
                    correlation.insert(std::pair<int,float>(it->first,S.cos_similarity(c,d)));
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
    float e=predictRate(allUsers, correlation,indexm, N);
    cout << "The predicted rate for " << allMovies[mo].getTitle() << " is : " << e << "\n";
    if (e>3.5)
        cout << allMovies[mo].getTitle() <<" is HIGHLY recommended for the user !";
    else if (e>2.5)
        cout << allMovies[mo].getTitle() << " is recommended for the user !";
    else
        cout << allMovies[mo].getTitle() << " is NOT recommended for the user !";
}
void CFmovie(map<int,User> allUsers,map<int,Movie> allMovies,MatrixVector U){
    int a=0;
    int index=allUsers[a].gethId();
    int mo;
    int indexm=0;
    while ((indexm > 10197) or (indexm < 1)){
        cout << "Enter the id of the movie to predict : ";
        cin >> mo;
        indexm=allMovies[mo].gethId();
    }
    allMovies[mo].assignRatings(U.getRow(indexm));
    allMovies[mo].getAvg();
    vector<float> c=allMovies[mo].getRatings();
    while (((index > 2113)or(index < 1))or(c[index]!=0)){
        cout << "Enter the id of the user you want to recommend to (Not have seen the movie) : ";
        cin >> a;
        index=allUsers[a].gethId();
    }
    //Calculate correlation with all the movies
    map<int,float> correlation;
    int loop=1;
    Similarity S;
    for (std::map<int,Movie>::iterator it=allMovies.begin(); it!=allMovies.end(); ++it){
            if ((it->first)!=mo){
                it->second.assignRatings(U.getRow(loop));
                if (it->second.getRatings()[index]!=0){//if movie watched
                    it->second.getAvg();
                    vector<float> d=it->second.getRatings();
                    correlation.insert(std::pair<int,float>(it->first,S.cos_similarity(c,d)));
                }
                loop++;
            }
    }
    cout << correlation.size() << " Movies have been watched by this user ! \n";
    //Handling neighborhood
    int N;
    cout << "Select the size of your neighborhood : ";
    cin >> N;
    //Predict the rate
    float e=predictRate(allMovies, correlation,index, N);
    cout << "The predicted rate for " << allMovies[mo].getTitle() << " is : " << e << "\n";
    if (e>3.5)
        cout << allMovies[mo].getTitle() <<" is HIGHLY recommended for the user !";
    else if (e>2.5)
        cout << allMovies[mo].getTitle() << " is recommended for the user !";
    else
        cout << allMovies[mo].getTitle() << " is NOT recommended for the user !";
}
