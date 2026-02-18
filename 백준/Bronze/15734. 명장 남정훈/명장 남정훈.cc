#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int L,R,A;
    cin >> L >> R >> A;

    while(A!=0){
        if(L>R){
            R++;
            A--;
        }else if(R>L){
            L++;
            A--;
        }else{
            A /= 2;
            L += A;
            R += A;
            break;
        }
    }
    if(L<R) cout << L*2 << endl;
    else    cout << R*2 << endl;

    return 0;
}