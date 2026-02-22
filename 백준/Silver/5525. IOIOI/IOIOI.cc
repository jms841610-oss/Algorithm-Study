#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    string line;
    cin >> line;

    int idx = 0;
    int num = 0;
    int cnt = 0;

    while(idx+2<M){
        if((line[idx]=='I')&&(line[idx+1]=='O')&&(line[idx+2]=='I')){
            cnt++;
            if(cnt==N){
                cnt--;
                num++;
            }
            idx += 2;
        }else{
            cnt = 0;
            idx++;
        }
    }
    cout << num << "\n";

    return 0;
}