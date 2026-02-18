#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int L,R,A;
    cin >> L >> R >> A;

    int diff = abs(L-R);
    int max_val = max(L,R);
    int min_val = min(L,R);

    if(diff>A){
        diff -= A;
        A = 0;
    }else{
        A -= diff;
        diff = 0;
    }
    min_val = max_val - diff;
    
    int result = (min_val + (A/2)) * 2;

    cout << result << endl;

    return 0;
}