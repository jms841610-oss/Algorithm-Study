#include <iostream>
#include <vector>
#include <algorithm> // min 함수를 사용하기 위해 포함

using namespace std;

int main() {
    // 입출력 속도 향상을 위한 최적화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // DP 배열과 비용(cost) 배열 선언 (인덱스 1부터 사용하기 위해 N+1 크기로 할당)
    // 열 크기는 3 (0: R, 1: G, 2: B)
    vector<vector<int>> dp(N + 1, vector<int>(3, 0));
    vector<vector<int>> cost(N + 1, vector<int>(3, 0));

    // 1. 각 집을 칠하는 비용 입력받기
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }

    // 2. 초기값 설정 (첫 번째 집을 칠하는 최소 비용은 자기 자신의 비용)
    dp[1][0] = cost[1][0]; // 1번 집을 Red로 칠할 때의 누적 최소 비용
    dp[1][1] = cost[1][1]; // 1번 집을 Green으로 칠할 때의 누적 최소 비용
    dp[1][2] = cost[1][2]; // 1번 집을 Blue로 칠할 때의 누적 최소 비용

    // 3. DP를 이용해 2번째 집부터 N번째 집까지 최소 비용 계산 (Bottom-Up 방식)
    for (int i = 2; i <= N; i++) {
        // 현재 집을 Red(0)로 칠할 때: 이전 집은 Green(1) 또는 Blue(2)여야 함
        dp[i][0] = cost[i][0] + min(dp[i-1][1], dp[i-1][2]);
        
        // 현재 집을 Green(1)으로 칠할 때: 이전 집은 Red(0) 또는 Blue(2)여야 함
        dp[i][1] = cost[i][1] + min(dp[i-1][0], dp[i-1][2]);
        
        // 현재 집을 Blue(2)로 칠할 때: 이전 집은 Red(0) 또는 Green(1)이어야 함
        dp[i][2] = cost[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }

    // 4. 마지막 N번째 집을 각각 R, G, B로 칠했을 때의 누적 비용 중 최솟값 찾기
    int ans = min({dp[N][0], dp[N][1], dp[N][2]});

    // 결과 출력
    cout << ans << "\n";

    return 0;
}
