#ifndef DATA_H
#define DATA_H
#include<iostream>

using namespace std;

vector<Rating> loadRatings();
map<int,Movie> loadMovies();
map<int,User> loadUsers();

#endif // DATA_H
