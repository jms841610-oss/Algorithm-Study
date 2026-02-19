#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,L,D;
    cin >> N >> L >> D;
    
    int start = L;
    int end = L+5;
    int n = 1;

    for(int i=0;i<N-1;i++){
        while((D*n) < start) n++;
        if((start <= (D*n))&&((D*n) < end)) break;
        start += (L+5);
        end += (L+5);
    }
    while((D*n) < start) n++;

    cout << D*n << endl;

    return 0;
}