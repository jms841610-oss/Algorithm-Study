#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    cin >> line;
    
    for(int i=0;i<4;i++){
        line.push_back(line[i]);
    }
    line.erase(line.begin(),line.begin()+4);

    string result = "";

    for(int i=0;i<line.size();i++){
        if(('0'<=line[i])&&(line[i]<='9')){
            result.push_back(line[i]);
        }else{
            int num = 10 + line[i] - 'A';
            string str = to_string(num);
            result += str;
        }
    }
    long long remainder = 0;

    for(int i=0;i<result.size();i++){
        remainder = (remainder * 10 + (result[i] - '0')) % 97;
    }
    if(remainder==1){
        cout << "correct\n";
    }else{
        cout << "incorrect\n";
    }
    return 0;
}