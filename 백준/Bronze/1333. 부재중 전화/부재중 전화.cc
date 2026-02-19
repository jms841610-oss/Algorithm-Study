#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,L,D;
    cin >> N >> L >> D;
    
    int T = D;
    int cycle = L+5;

    while(true){
        if(T >= (N*cycle -5)) break;

        int time_in_cycle = T % cycle;

        if(time_in_cycle < L) T += D;
        else                  break;
    }
    cout << T << endl;

    return 0;
}