#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a,b;
    cin >> a >> b;

    if(b==0){
        cout << 0 << "\n";
    }else if(a>=b){
        cout << b << "\n";
    }else{
        cout << a+1 << "\n";
    }
    return 0;
}