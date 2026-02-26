#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string,int> votes;
    vector<string> possible;

    int max_votes = 0;

    while(true){
        string name;

        getline(cin,name);

        if(name == "***") break;

        if(votes.find(name)!=votes.end()){
            votes[name]++;
        }else{
            votes[name] = 0;
            possible.push_back(name);
        }
        max_votes = max(max_votes,votes[name]);
    }
    string candidate = "";

    int cnt = 0;

    for(int i=0;i<possible.size();i++){
        if(votes[possible[i]]==max_votes){
            cnt++;
            candidate = possible[i];
        }
    }
    if(cnt==1){
        cout << candidate << "\n";
    }else{
        cout << "Runoff!\n";
    }
    return 0;
}