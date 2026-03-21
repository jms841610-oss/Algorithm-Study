#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> cost(N+1,vector<int>(3,0));
    vector<vector<int>> dp(N+1,vector<int>(3,0));

    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            cin >> cost[i][j];
        }
    }
    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];

    for(int i=2;i<=N;i++){
        for(int j=0;j<3;j++){
            dp[i][j] = cost[i][j] + min(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3]);
        }
    }
    int ans = numeric_limits<int>::max();

    for(int i=0;i<3;i++){
        ans = min(ans,dp[N][i]);
    }
    cout << ans << "\n";
    
    return 0;
}