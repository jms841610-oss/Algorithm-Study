#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string,int> votes;

    int max_votes = 0;

    while(true){
        string name;

        getline(cin,name);

        if(name == "***") break;

        votes[name]++;

        max_votes = max(max_votes,votes[name]);
    }
    string candidate = "";

    int cnt = 0;

    for(const auto &pair : votes){
        if(pair.second==max_votes){
            candidate = pair.first;
            cnt++;
        }
    }
    if(cnt==1){
        cout << candidate << "\n";
    }else{
        cout << "Runoff!\n";
    }
    return 0;
}