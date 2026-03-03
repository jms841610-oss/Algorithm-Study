#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool is_rising = true;
    bool is_diving = true;
    bool is_constant = true;

    int prev;
    cin >> prev;

    for(int i=0;i<3;i++){
        int current;
        cin >> current;

        if(current<prev){
            is_rising = false;
            is_constant = false;
        }else if(current>prev){
            is_diving = false;
            is_constant = false;
        }else{
            is_rising = false;
            is_diving = false;
        }
        prev = current;
    }
    if(is_rising)        cout << "Fish Rising\n";
    else if(is_diving)   cout << "Fish Diving\n";
    else if(is_constant) cout << "Fish At Constant Depth\n";
    else                 cout << "No Fish\n";

    return 0;
}