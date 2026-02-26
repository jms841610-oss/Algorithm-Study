#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<string> list(N);
    vector<bool> exist(26,false);

    for(int i=0;i<N;i++){
        string word;
        cin >> word;
        list[i] = word;
        exist[word[0]-'A'] = true;
    }
    for(int i=0;i<N;i++){
        string current = list[i];

        int len = current.length();
        bool is_possible = true;

        for(int j=0;j<len;j++){
            if(!exist[current[j]-'A']){
                is_possible = false;
                break;
            }
        }
        if(is_possible){
            cout << "Y\n";

            return 0;
        }
    }
    cout << "N\n";

    return 0;
}