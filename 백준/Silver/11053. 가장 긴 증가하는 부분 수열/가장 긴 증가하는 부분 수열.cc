#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    arr.assign(N,0);
    dp.assign(N,1);

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
    }
    int ans = 0;

    for(int i=0;i<N;i++){ 
        ans = max(ans,dp[i]);
    }
    cout << ans << "\n";

    return 0;
}