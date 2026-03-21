#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        string key;
        cin >> key;

        if(key=="0") break;

        string plain;
        cin >> plain;

        string result = "";

        for(int i=0;i<plain.length();i++){
            char sub = plain[i] + (key[i%key.length()] - 'A' + 1);
            char cipher = (sub>'Z') ? 'A' + sub%'Z' - 1 : sub;
            result.push_back(cipher);
        }
        cout << result << "\n";
    }
    return 0;
}