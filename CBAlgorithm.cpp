#include "CBAlgorithm.h"

CBAlgorithm::CBAlgorithm(){}
CBAlgorithm::CBAlgorithm(string a,string b,string c):Algorithm(a,b,c){
    std::ifstream file("data/tags.csv");

    std::string line;
    std::getline(file, line);
    int id;

    //loading tags
    while (file.good())
    {

        std::getline(file, line);
        if ( !file.good() )
            break;

        std::stringstream iss(line);
        std::string val;
        std::getline(iss, val, ';');
        std::stringstream convertor(val);
        convertor >> id;
        std::getline(iss, val, ';');
        tags.insert(std::pair<int,string>(id,val));
    }
}

CBAlgorithm::~CBAlgorithm() {
    tags.clear();
}
float CBAlgorithm::cos_similarity(map <int,float> U1, map <int,float>U2){
    /*

    */
    float a,b,c;
    for (std::map<int,string>::iterator it = tags.begin(); it != tags.end(); ++it){
        a=a+((U1[it->first]!=0)*U1[it->first]*U2[it->first]*(U2[it->first]!=0));
        b=b+((U1[it->first]!=0)*U1[it->first]*U1[it->first]);
        c=c+(U2[it->first]*(U2[it->first]!=0)*U2[it->first]);
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

map <int,float> CBAlgorithm::getTop(map <int,float> sim,int top){
    map<int,float> res;
    int maximum;
    for (int i=0;i<top;i++){
        maximum=0;
        sim[maximum]=-2;
        for (std::map<int,float>::iterator it=sim.begin(); it!=sim.end(); ++it){
            if (it->second > sim[maximum]){
                maximum=it->first;
            }
        }
        cout<<maximum<<endl;
        res.insert(std::pair<int,float>(maximum,sim[maximum]));
        sim.erase(maximum);
    }
    return res;
}
void CBAlgorithm::execute(int methode){
    /*
    */

    int user=0; // user to predict
    map <int, float> similarity; //map of similarities of user with all movies
    map <int, float> top_sim;
    int top=10;
    int index=0;

    cout << "--------------------------------LOADING CONTENT BASED ALGORITHM--------------------------------\n\n";
    loadMovies();
    loadUsers();
    cout << allMovies.size() << " Movies and " << allUsers.size() <<" Users loaded !\n";
    while ((index > 2113) or (index < 1)){
        cout << "Enter the id of the user you want to recommend to : ";
        cin >> user;
        index=allUsers[user].gethId(); // return what when not found ?
    }
    if (methode==1){

            learning_2D(allMovies,allUsers);
            allUsers[user].assignRatings(M_2D.getColumn(index));
            allUsers[user].setProfile(allMovies);
            cout<<"calculating similarities..."<<endl;
            for(std::map<int,Movie>::iterator it=allMovies.begin();it!=allMovies.end();it++){
                if (allUsers[user].getRatings()[it->second.gethId()]==0){
                similarity.insert(pair<int,float>(it->first,cos_similarity(allUsers[user].getProfile(),it->second.getProfile())));
                }
            }
            top_sim=getNeighbors(similarity,top);
            cout<<"The top 10 recommended movies are:"<<endl;
            for(std::map<int,float>::iterator it=top_sim.begin();it!=top_sim.end();it++){
                cout<<allMovies[it->first].getTitle()<<":"<<it->first<<endl;
            }
    }

    else if (methode==2){

            learning_vector(allMovies,allUsers);
            allUsers[user].assignRatings(M_vector.getColumn(index));
            allUsers[user].setProfile(allMovies);
            cout<<"calculating similarities..."<<endl;
            for(std::map<int,Movie>::iterator it=allMovies.begin();it!=allMovies.end();it++){
                if (allUsers[user].getRatings()[it->second.gethId()]==0){
                similarity.insert(pair<int,float>(it->first,cos_similarity(allUsers[user].getProfile(),it->second.getProfile())));
                }
            }
            top_sim=getNeighbors(similarity,top);
            cout<<"The top 10 recommended movies are:"<<endl;
            for(std::map<int,float>::iterator it=top_sim.begin();it!=top_sim.end();it++){
                cout<<allMovies[it->first].getTitle()<<":"<<it->first<<endl;
            }
    }
    else if (methode==3){

            learning_map(allMovies,allUsers);
            allUsers[user].assignRatings(M_map.getColumn(index));
            allUsers[user].setProfile(allMovies);
            cout<<"calculating similarities..."<<endl;
            for(std::map<int,Movie>::iterator it=allMovies.begin();it!=allMovies.end();it++){
                if (allUsers[user].getRatings()[it->second.gethId()]==0){
                similarity.insert(pair<int,float>(it->first,cos_similarity(allUsers[user].getProfile(),it->second.getProfile())));
                }
            }
            top_sim=getNeighbors(similarity,top);
            cout<<"The top 10 recommended movies are:"<<endl;
            for(std::map<int,float>::iterator it=top_sim.begin();it!=top_sim.end();it++){
                cout<<allMovies[it->first].getTitle()<<":"<<it->first<<endl;
            }



    }
}
