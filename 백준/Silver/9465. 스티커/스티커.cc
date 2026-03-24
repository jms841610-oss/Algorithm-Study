#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        int N;
        cin >> N;

        vector<vector<int>> scr(2,vector<int>(N));
        vector<vector<int>> dp(2,vector<int>(N));
        
        for(int i=0;i<2;i++){
            for(int j=0;j<N;j++){
                cin >> scr[i][j];
            }
        }
        dp[0][0] = scr[0][0];
        dp[1][0] = scr[1][0];

        dp[0][1] = scr[0][1] + scr[1][0];
        dp[1][1] = scr[1][1] + scr[0][0];

        for(int i=2;i<N;i++){
            dp[0][i] = scr[0][i] + max(dp[1][i-1],dp[1][i-2]);
            dp[1][i] = scr[1][i] + max(dp[0][i-1],dp[0][i-2]);
        }
        int ans = max(dp[0][N-1],dp[1][N-1]);
        cout << ans << "\n";
    }
    return 0;
}