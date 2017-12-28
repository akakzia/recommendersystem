#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<iostream>
using namespace std;
map<int,Movie> loadMovies();
map<int,User> loadUsers();
MatrixVector learning(map<int,Movie>, map<int,User>);
#endif
