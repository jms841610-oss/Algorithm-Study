#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    vector<char> st;

    char stack[1000000] = {};
    int idx = 0;

    int len1 = str1.length();
    int len2 = str2.length();

    for(int i=0;i<len1;i++){
        stack[idx++] = str1[i];

        if(stack[idx-1] == str2[len2-1]){
            bool possible = false;

            if(idx >= len2){
                possible = true;

                for(int j=2;j<=len2;j++){
                    if(stack[idx-j] != str2[len2-j]){
                        possible = false;
                        break;
                    }
                }
            }
            if(possible){
                idx = idx - len2;
            }
        }
    }
    if(idx != 0){
        for(int i=0;i<idx;i++){
            cout << stack[i];
        }
        cout << "\n";
    }else{
        cout << "FRULA\n";
    }
    return 0;
}