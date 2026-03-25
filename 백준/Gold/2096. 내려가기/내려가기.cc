#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // [1] 입출력 속도 최적화
    // C++의 표준 스트림 동기화를 끊어 입출력 속도를 높입니다. (알고리즘 문제 풀이 필수 설정)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N; // 전체 줄(행)의 개수 입력

    // [2] DP 배열 초기화 (공간 최적화 핵심)
    // N x 3 배열을 만들지 않고, 메모리 절약을 위해 길이가 3인 1차원 배열만 사용합니다.
    // 각 시점에서 '바로 이전 줄'까지의 최대/최소 누적합만 기억합니다.
    vector<int> max_dp(3,0); 
    vector<int> min_dp(3,0); 

    // 현재 행의 계산 결과를 임시로 저장할 변수들
    // 이 변수들이 필요한 이유는 계산 중간에 이전 상태(max_dp, min_dp)가 덮어씌워지는 것을 방지하기 위함입니다.
    int A_max = 0; int B_max = 0; int C_max = 0;
    int A_min = 0; int B_min = 0; int C_min = 0;

    // [3] 줄(행) 단위로 내려가며 DP 테이블 갱신
    for(int i=0; i<N; i++){
        int A, B, C;
        cin >> A >> B >> C; // 현재 줄의 숫자 3개 입력

        // --- 최대 점수 계산 (max_dp) ---
        // 1. 왼쪽(0번) 칸으로 내려오는 경우: 이전 줄의 0번, 1번에서만 올 수 있음
        A_max = A + max(max_dp[0], max_dp[1]);
        
        // 2. 가운데(1번) 칸으로 내려오는 경우: 이전 줄의 0번, 1번, 2번 모두에서 올 수 있음
        int temp_max = max(max_dp[0], max_dp[1]); 
        B_max = B + max(temp_max, max_dp[2]);
        
        // 3. 오른쪽(2번) 칸으로 내려오는 경우: 이전 줄의 1번, 2번에서만 올 수 있음
        C_max = C + max(max_dp[1], max_dp[2]);

        // 계산된 현재 줄의 최대 점수로 DP 배열을 덮어씌움 (다음 줄 계산을 위한 준비)
        max_dp[0] = A_max;
        max_dp[1] = B_max;
        max_dp[2] = C_max;

        // --- 최소 점수 계산 (min_dp) ---
        // 최대 점수와 원리는 완전히 동일하며, max 대신 min을 사용합니다.
        // 1. 왼쪽 칸
        A_min = A + min(min_dp[0], min_dp[1]);
        
        // 2. 가운데 칸
        int temp_min = min(min_dp[0], min_dp[1]);
        B_min = B + min(temp_min, min_dp[2]);
        
        // 3. 오른쪽 칸
        C_min = C + min(min_dp[1], min_dp[2]);

        // 계산된 현재 줄의 최소 점수로 DP 배열 덮어씌움
        min_dp[0] = A_min;
        min_dp[1] = B_min;
        min_dp[2] = C_min;
    }

    // [4] 최종 결과 도출
    // 모든 줄을 다 내려왔을 때, 배열에 남아있는 3개의 값 중 가장 큰 값과 가장 작은 값을 찾습니다.
    int temp_max = max(max_dp[0], max_dp[1]);
    int max_sum = max(temp_max, max_dp[2]);
    
    int temp_min = min(min_dp[0], min_dp[1]);
    int min_sum = min(temp_min, min_dp[2]);

    // 결과 출력
    cout << max_sum << " " << min_sum << "\n";
    
    return 0;
}
