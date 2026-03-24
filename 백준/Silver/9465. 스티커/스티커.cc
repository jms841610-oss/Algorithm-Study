#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        // 2행 N열의 스티커 점수를 저장할 배열
        vector<vector<int>> scr(2, vector<int>(N));
        // 2행 N열의 DP 결과를 저장할 배열 (0으로 초기화)
        vector<vector<int>> dp(2, vector<int>(N, 0));
        
        // 스티커 점수 입력받기
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < N; j++){
                cin >> scr[i][j];
            }
        }

        // 1. 초기값 설정 (N=1일 때를 위한 세팅)
        dp[0][0] = scr[0][0];
        dp[1][0] = scr[1][0];

        // N이 2 이상일 때만 아래 로직 실행 (N=1일 때의 Out of Bounds 에러 방지)
        if (N > 1) {
            // 2. N=2일 때의 초기값 설정
            dp[0][1] = scr[1][0] + scr[0][1];
            dp[1][1] = scr[0][0] + scr[1][1];

            // 3. N=3부터 반복문을 돌며 점화식 적용
            for(int i = 2; i < N; i++){
                dp[0][i] = scr[0][i] + max(dp[1][i-1], dp[1][i-2]);
                dp[1][i] = scr[1][i] + max(dp[0][i-1], dp[0][i-2]);
            }
        }

        // 4. 마지막 열에서 위쪽을 선택한 경우와 아래쪽을 선택한 경우 중 더 큰 값 출력
        cout << max(dp[0][N-1], dp[1][N-1]) << "\n";
    }
    
    return 0;
}
