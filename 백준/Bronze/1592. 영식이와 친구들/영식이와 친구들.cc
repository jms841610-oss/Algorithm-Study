#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, L;
    cin >> N >> M >> L;

    vector<int> cnt(N+1,0);
    int ans = -1;
    int current = 1;

    while(true){
        if(cnt[current] < M){
            cnt[current]++;
            ans++;

            if(cnt[current]==M) break;
        }
        if(cnt[current]%2 == 1){
            current = (current + L) % N;
        }else if(cnt[current]%2 == 0){
            current = ((current - L) < 0 ) ? (current - L) + N : (current - L);
        }
    }
    cout << ans << "\n";
    return 0;
}