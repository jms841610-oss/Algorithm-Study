#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    vector<char> ans;

    cin >> str;
    ans.reserve(str.length());

    char prev = '0';

    for(int i=0;i<str.length();i++){
        if(prev!=str[i]){
            ans.push_back(str[i]);
            prev = str[i];
        }
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}