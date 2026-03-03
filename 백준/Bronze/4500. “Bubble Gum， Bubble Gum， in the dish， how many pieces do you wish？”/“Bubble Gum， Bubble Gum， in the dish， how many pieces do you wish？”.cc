#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        vector<string> list;

        string line;
        string word;

        cin.ignore();
        getline(cin,line);
        stringstream ss(line);

        while(ss >> word){
            list.push_back(word);
        }
        string start;
        cin >> start;

        int num;
        cin >> num;

        int size = list.size();
        int start_idx = -1;

        for(int j=0;j<size;j++){
            if(list[j]==start){
                start_idx = j;
                break;
            }
        }
        int end_idx = (start_idx + (num-1)) % size;

        cout << list[end_idx] << "\n";
    }
    return 0;
}