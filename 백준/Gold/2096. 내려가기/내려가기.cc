#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> max_dp(3,0);
    vector<int> min_dp(3,0);

    int A_max = 0;
    int B_max = 0;
    int C_max = 0;

    int A_min = 0;
    int B_min = 0;
    int C_min = 0;

    for(int i=0;i<N;i++){
        int A, B, C;
        cin >> A >> B >> C;

        A_max = A + max(max_dp[0], max_dp[1]);
        int temp_max = max(max_dp[0], max_dp[1]);
        B_max = B + max(temp_max, max_dp[2]);
        C_max = C + max(max_dp[1], max_dp[2]);

        max_dp[0] = A_max;
        max_dp[1] = B_max;
        max_dp[2] = C_max;

        A_min = A + min(min_dp[0], min_dp[1]);
        int temp_min = min(min_dp[0], min_dp[1]);
        B_min = B + min(temp_min, min_dp[2]);
        C_min = C + min(min_dp[1], min_dp[2]);

        min_dp[0] = A_min;
        min_dp[1] = B_min;
        min_dp[2] = C_min;
    }
    int temp_max = max(max_dp[0], max_dp[1]);
    int max_sum = max(temp_max, max_dp[2]);
    int temp_min = min(min_dp[0], min_dp[1]);
    int min_sum = min(temp_min, min_dp[2]);

    cout << max_sum << " " << min_sum << "\n";
    return 0;
}