#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<iostream>



using namespace std;
map<int,Movie> loadMovies();
map<int,User> loadUsers();
MatrixMap learning_Map(map<int,Movie> M, map<int,User> U);
Matrix2D learning_2D(map<int,Movie>, map<int,User>);
MatrixVector learning_Vector(map<int,Movie>, map<int,User>);
map<int, float> getNeighbors(map<int, float>, int);
float predictRate(map<int,User>, map<int,float>,int, int);
float predictRate(map<int,Movie>, map<int,float>,int, int);
void CFuser(map<int,User> allUsers,map<int,Movie> allMovies,MatrixVector U);
void CFmovie(map<int,User> allUsers,map<int,Movie> allMovies,MatrixVector U);
MatrixVector Similarity_Vector(MatrixVector);
float cos_similarity(vector<float>,vector<float> );
#endif
