#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // [복습 포인트 1] 빠른 입출력 처리를 위한 세팅
    // C++의 표준 스트림 동기화를 끊어 입출력 속도를 높입니다. 알고리즘 문제 풀이 시 시간 초과 방지에 유용합니다.
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M; // N: 물건의 개수, M: 배낭이 버틸 수 있는 최대 무게

    // [복습 포인트 2] DP 테이블 및 물건 정보 배열 초기화
    // dp[i][j]: i번째 물건까지 탐색했고, 배낭의 허용 무게가 j일 때의 최대 가치
    // 물건 번호와 무게를 1부터 시작하기 위해 크기를 (N+1) x (M+1)로 설정합니다.
    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
    
    // arr[i].first: 무게(W), arr[i].second: 가치(V)
    vector<pair<int,int>> arr(N+1);
    arr[0] = {0,0}; // 0번째 인덱스는 사용하지 않으므로 0으로 비워둡니다.

    // 물건 정보 입력받기
    for(int i=1; i<=N; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    // [복습 포인트 3] 본격적인 DP (Bottom-Up 방식)
    for(int i=1; i<=N; i++){
        int now_wei = arr[i].first;  // 현재 탐색 중인 물건의 무게
        int now_val = arr[i].second; // 현재 탐색 중인 물건의 가치

        for(int j=1; j<=M; j++){
            // 경우 1: 현재 배낭의 허용 무게(j)가 현재 물건의 무게(now_wei)보다 크거나 같을 때 -> 물건을 넣을 수 있음!
            if(now_wei <= j){
                // (이전 물건까지의 최댓값) vs (현재 물건을 넣기 위해 공간을 확보했을 때의 최댓값 + 현재 물건의 가치)
                dp[i][j] = max(dp[i-1][j], (dp[i-1][j-now_wei] + now_val));
            }
            // 경우 2: 현재 배낭의 허용 무게보다 물건이 무거울 때 -> 물건을 넣을 수 없음!
            else{
                // 이전 물건까지 탐색했을 때의 최댓값을 그대로 물려받음
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // [복습 포인트 4] 정답 도출
    // 사실 dp[N][M]에 최적의 해(최대 가치)가 이미 들어있으므로 바로 cout << dp[N][M]; 을 해도 무방합니다.
    // 하지만 M 이하의 무게로도 최대 가치가 나올 수 있으므로, 마지막 행(N번째 물건까지 본 상태)에서 최댓값을 찾는 것도 안전한 방법입니다.
    int ans = 0;
    for(int i=1; i<=M; i++){
        ans = max(ans, dp[N][i]);
    }
    
    cout << ans << "\n";
    
    return 0;
}
