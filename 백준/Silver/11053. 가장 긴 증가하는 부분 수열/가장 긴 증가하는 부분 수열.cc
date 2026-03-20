#include <iostream>
#include <vector>
#include <algorithm> // max 함수 사용을 위해 추가

using namespace std;

int N;
int ans = 0;
vector<int> arr;

// temp 배열이나 백트래킹 재귀 함수 대신 dp 배열을 사용합니다.
vector<int> dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    arr.assign(N, 0); // 크기 N짜리 배열 생성
    dp.assign(N, 1);  // 모든 위치의 최소 LIS 길이는 1이므로 1로 초기화

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    // DP 로직 시작
    for(int i = 1; i < N; i++){ // i: 현재 기준이 되는 원소의 인덱스
        for(int j = 0; j < i; j++){ // j: i보다 앞에 있는 원소들의 인덱스
            
            // 증가하는 관계인지 확인
            if(arr[j] < arr[i]){
                // 기존에 저장된 dp[i] 길이와, j번째 원소 뒤에 i번째 원소를 붙였을 때의 길이(dp[j] + 1) 중 최댓값 저장
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // dp 배열에 저장된 값들 중 가장 큰 값이 우리가 찾는 최대 길이입니다.
    for(int i = 0; i < N; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";

    return 0;
}
