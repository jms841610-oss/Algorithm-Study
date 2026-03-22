#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> triangle(N+1);
    
    // 🌟 수정된 부분: dp 벡터의 행과 열 크기를 미리 지정하고 0으로 초기화합니다.
    // 행의 개수는 N+1, 각 행의 길이도 N+1로 넉넉하게 잡아줍니다.
    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));

    // 1. 삼각형 데이터 입력받기
    for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++){
            int digit;
            cin >> digit;
            triangle[i].push_back(digit);
        }
    }
    
    // 2. 초기값 설정 (이제 공간이 할당되어 있으므로 에러가 나지 않습니다!)
    dp[1][0] = triangle[1][0];

    // 3. DP 배열 채우기
    for(int i=2;i<=N;i++){
        for(int j=0;j<i;j++){
            if(j==0){
                dp[i][j] = triangle[i][j] + dp[i-1][j];
            }else if(j==i-1){
                dp[i][j] = triangle[i][j] + dp[i-1][j-1];
            }else{
                dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    
    int ans = 0;

    // 🌟 수정된 부분: N번째 줄에 채워진 값들 중 최댓값을 찾습니다.
    // dp의 크기를 N+1로 넉넉히 잡았기 때문에, 딱 채워진 데이터만큼(0부터 N-1까지)만 순회하도록 변경했습니다.
    for(int j=0; j<N; j++){
        ans = max(ans, dp[N][j]);
    }
    
    cout << ans << "\n";
    return 0;
}
