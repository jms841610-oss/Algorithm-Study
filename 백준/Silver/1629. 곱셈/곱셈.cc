#include <iostream>

using namespace std;

int solve(int a,int b,int c){
    long long remainder;

    if(b==0){
        return 1;
    }
    long long half = solve(a,b/2,c);

    if(b%2==0) remainder = (half * half)%c;
    else       remainder = ((half * half)%c * a)%c;

    return remainder;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A,B,C;
    cin >> A >> B >> C;

    long long remainder = solve(A,B,C);

    cout << remainder << "\n";
    return 0;
}