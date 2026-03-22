#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    multimap<string,string> m;
    set<string> key;
    vector<vector<string>> val(N);

    for(int i=0;i<N;i++){
        string mento,menti;
        cin >> mento >> menti;

        m.insert({mento,menti});
        key.insert(mento);
    }
    int idx = 0;

    for(const string ele : key){
        auto range = m.equal_range(ele);

        for(auto it=range.first;it!=range.second;++it){
            val[idx].push_back(it->second);
        }
        sort(val[idx].begin(),val[idx].end(),greater<string>());
        idx++;
    }
    idx = 0;

    for(const string ele : key){
        auto range = key.equal_range(ele);

        for(int i=0;i<val[idx].size();i++){
            cout << ele << " " << val[idx][i] << "\n";
        }
        idx++;
    }
    return 0;
}