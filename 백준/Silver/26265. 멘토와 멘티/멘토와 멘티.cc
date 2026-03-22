#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    map<string,vector<string>> m;
    
    for(int i=0;i<N;i++){
        string mento,menti;
        cin >> mento >> menti;
        m[mento].push_back(menti);
    }
    for(auto& pair : m){
        sort(pair.second.begin(),pair.second.end(),greater<string>());

        for(const string& menti : pair.second){
            cout << pair.first << " " << menti << "\n";
        }
    }
    return 0;
}