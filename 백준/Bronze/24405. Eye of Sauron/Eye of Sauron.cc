#include <iostream>

using namespace std;

int main(){
    string line;
    cin >> line;

    int index;

    for(int i=0;i<line.size();i++){
        if(line[i]=='('){
            index = i;
            break;
        }
    }
    int left = index;
    int right = line.size() - (index+2);

    if(left==right) cout << "correct" << endl;
    else            cout << "fix"     << endl;

    return 0;
}