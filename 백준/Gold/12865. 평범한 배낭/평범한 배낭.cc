#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> dp(N+1,vector<int>(M+1,0));
    vector<pair<int,int>> arr(N+1);

    arr[0] = {0,0};

    for(int i=1;i<=N;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    for(int i=1;i<=N;i++){
        int now_wei = arr[i].first;
        int now_val = arr[i].second;

        for(int j=1;j<=M;j++){
            if(now_wei <= j){
                dp[i][j] = max(dp[i-1][j], (dp[i-1][j-now_wei] + now_val));
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[N][M] << "\n";
    return 0;
}