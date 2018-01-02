#include "CBAlgorithm.h"

CBAlgorithm::CBAlgorithm(){}
CBAlgorithm::CBAlgorithm(string a,string b,string c):Algorithm(a,b,c){}

float CBAlgorithm::cos_similarity(vector <float> U1, vector <float>U2){
    /*

    */
    float a,b,c;
    for (int i=1; i<U1.size(); i++){
        a=a+((U1[i]!=0)*U1[i]*U2[i]*(U2[i]!=0));
        b=b+((U1[i]!=0)*U1[i]*U1[i]);
        c=c+(U2[i]*(U2[i]!=0)*U2[i]);
    }
        b=sqrt(b);
        c=sqrt(c);
        if(b*c!=0)
        {
            return a/(b*c);
        }
        else {
            return 0;
        }

}



void CBAlgorithm::execute(){
    /*

    */

    int user=0; // user to predict
    map <int, float> similarity; //map of similarities of user with all movies
    map <int, float> top_sim;
    int top=10;


    cout << "--------------------------------LOADING CONTENT BASED ALGORITHM--------------------------------\n\n";
    loadMovies();
    loadUsers();
    cout << allMovies.size() << " Movies and " << allUsers.size() <<" Users loaded !\n";

    int index=0;
        while ((index > 2113) or (index < 1)){
            cout << "Enter the id of the user you want to recommend to : ";
            cin >> user;
            index=allUsers[user].gethId(); // return what when not found ?
        }

    allUsers[user].setProfile(allMovies);

    for(std::map<int,Movie>::iterator it=allMovies.begin();it!=allMovies.end();it++){
        cout<<it->first<<endl;
        similarity.insert(pair<int,float>(it->first,cos_similarity(allUsers[user].getProfile(),it->second.getProfile())));
    }

    top_sim=getNeighbors(similarity,top);
    cout<<"The top 10 recommended movies are:"<<endl;
    for(std::map<int,float>::iterator it=top_sim.begin();it!=top_sim.end();it++){
            cout<<"x-"<<it->first<<endl;
    }

}
