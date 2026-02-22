#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    string line;
    cin >> line;

    int len = 1 + (2 * N);
    int cnt = 0;
    string ans = "I";

    for(int i=0;i<N;i++){
        ans += "OI";
    }
    for(int front=0;front<=M-len;front++){
        string current = "";
        
        for(int ele=front;ele<front+len;ele++){
            current += line[ele];
        }
        if(current==ans) cnt++;
    }
    cout << cnt << "\n";

    return 0;
}