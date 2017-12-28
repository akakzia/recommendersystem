#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<iostream>
using namespace std;
map<int,Movie> loadMovies();
map<int,User> loadUsers();
Rating *fill_rating();
Movie  *fill_movies();
User *fill_User();
MatrixVector learning(map<int,Movie>, map<int,User>);
map<int,int> H_movies_id;
map<int,int> H_users_id;
#endif
