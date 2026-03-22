#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> triangle(N+1);
    vector<vector<int>> dp(N+1,vector<int>(N,0));

    for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++){
            int digit;
            cin >> digit;
            triangle[i].push_back(digit);
        }
    }
    dp[1][0] = triangle[1][0];

    for(int i=2;i<=N;i++){
        for(int j=0;j<i;j++){
            if(j==0){
                dp[i][j] = triangle[i][j] + dp[i-1][j];
            }else if(j==i-1){
                dp[i][j] = triangle[i][j] + dp[i-1][j-1];
            }else{
                dp[i][j] = triangle[i][j] + max(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }
    int ans = 0;

    for(const int& val : dp[N]){
        ans = max(ans,val);
    }
    cout << ans << "\n";
    return 0;
}