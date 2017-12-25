#include <iostream>
#include<map>
#include<vector>
#include <fstream>
#include <sstream>
#include"MatrixMap.h"
#include"Similarity.h"
using namespace std;

int main()
{
    float data[5][3];
    std::ifstream file("database/user_ratedmovies.csv");
    std::string line;
    std::getline(file, line);
    for(int row = 0; row < 5; ++row)
    {

        std::getline(file, line);
        if ( !file.good() )
            break;

        std::stringstream iss(line);

        for (int col = 0; col < 3; ++col)
        {
            std::string val;
            std::getline(iss, val, ';');
            if ( !iss.good() )
                break;

            std::stringstream convertor(val);
            convertor >> data[row][col];
        }
    }
    for (int row=0;row<5;row++){
        for(int col=0;col<3;col++){
            cout << data [row][col] << " | ";
        }
        cout << "\n";
    }
    /*MatrixMap mm(2,3);
    mm.setEl(0,1,8.0);
    mm.setEl(1,1,2.0);
    mm.setEl(0,2,1.0);
    mm.setEl(1,2,5.0);
    mm.setEl(0,0,4.5);
    mm.setEl(1,0,3.5);
    int i,j;
    for (i=0;i<2;i++){
        for (j=0;j<3;j++){
            cout << mm.getEl(i,j);
        }
        cout << "\n";
    }
    Similarity S;
    float c=S.cos_similarity(mm.data.at(0),mm.data.at(1));
    cout << c;*/
    return 0;
}
