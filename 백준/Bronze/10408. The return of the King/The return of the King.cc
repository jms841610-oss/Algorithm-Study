#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    getline(cin,line);
    
    int len = line.length();

    int cnt = 0;
    int total = 0;
    bool is_ten = false;

    for(int i=len-1;i>=0;i--){
        if((is_ten)&&(line[i]=='1')){
            total += 10;
            cnt++;
            is_ten = false;
        }else if(line[i]=='0'){
            is_ten = true;
        }else{
            total += line[i] - '0';
            cnt++;
            is_ten = false;
        }
    }
    double avg = (double)total / cnt;

    cout << fixed << setprecision(2);

    cout << avg << "\n";

    return 0;
}