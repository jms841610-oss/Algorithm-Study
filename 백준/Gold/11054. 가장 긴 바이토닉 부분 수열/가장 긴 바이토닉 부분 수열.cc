#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // [1] 입출력 속도 향상
    // C++의 표준 스트림 동기화를 끊어 입출력 속도를 높여주는 알고리즘 문제 풀이의 필수 공식입니다.
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> seq(N);
    for(int i=0;i<N;i++){
        cin >> seq[i];
    }
    
    // [2] 왼쪽에서 오른쪽으로 가는 '가장 긴 증가하는 부분 수열(LIS)' 구하기
    // increase[i] : i번째 원소를 마지막으로 하는 증가 부분 수열의 최대 길이
    // 자기 자신만으로도 길이가 1인 수열이 되므로, 모든 값을 1로 초기화합니다.
    vector<int> increase(N,1);

    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            int current  = seq[i]; // 현재 기준이 되는 값
            int possible = seq[j]; // 현재 값보다 앞서 있는(이전) 값

            // 이전 값이 현재 값보다 작다면, 증가하는 수열을 이어갈 수 있습니다.
            if(possible < current){
                // 이전 값(j)까지의 최대 길이에 현재 값(i)을 더해 1을 증가시킨 길이
                int possible_len = increase[j] + 1;
                // 기존에 구해둔 현재 값(i)의 최대 길이
                int current_len = increase[i];

                // 두 길이 중 더 큰 값으로 갱신해 줍니다.
                increase[i] = max(current_len, possible_len);
            }
        }
    }
    
    // [3] 오른쪽에서 왼쪽으로 가는 '가장 긴 감소하는 부분 수열(LDS)' 구하기
    // decrease[i] : i번째 원소를 시작으로 하는 감소 부분 수열의 최대 길이
    // 마찬가지로 최소 길이는 1입니다.
    vector<int> decrease(N,1);

    // 이번에는 맨 뒤(N-2)에서부터 거꾸로 역추적하며 계산합니다.
    for(int i=N-2;i>=0;i--){
        for(int j=N-1;j>i;j--){
            int current  = seq[i]; // 현재 기준이 되는 값
            int possible = seq[j]; // 현재 값보다 뒤에 있는 값

            // 현재 값이 뒤에 있는 값보다 크다면, 감소하는 수열을 이어갈 수 있습니다.
            if(current > possible){
                // 뒤의 값(j)까지의 최대 길이에 현재 값(i)을 더해 1을 증가시킨 길이
                int possible_len = decrease[j] + 1;
                // 기존에 구해둔 현재 값(i)의 최대 길이
                int current_len = decrease[i];

                // 두 길이 중 더 큰 값으로 갱신해 줍니다.
                decrease[i] = max(current_len, possible_len);
            }
        }
    }
    
    // [4] 가장 긴 바이토닉 부분 수열의 길이 찾기
    int ans = 0;
    for(int i=0;i<N;i++){
        // i번째 원소를 산의 꼭대기(최고점)로 생각합니다.
        // i까지 증가하는 길이 + i부터 감소하는 길이 - 1 (꼭대기인 i가 두 번 더해졌으므로 1을 뺌)
        int now = increase[i] + decrease[i] - 1;
        
        // 여태까지 구한 길이 중 가장 긴 길이를 정답으로 저장합니다.
        ans = max(ans, now);
    }
    
    cout << ans << "\n";
    return 0;
}
