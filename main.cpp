#include <iostream>
#include "Movie.h"
#include<vector>
using namespace std;

int main()
{
    Movie M(1, "Home", "today", "ii");
    M.addRating(5);
    vector<float> s=M.getRating();
    cout << s.size();
    return 0;
}
