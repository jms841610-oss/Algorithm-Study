#include <iostream>
#include <string>
#include <cmath>     // abs() 함수 사용을 위해 추가
#include <algorithm> // min() 함수 사용을 위해 추가

using namespace std;

int main() {
    // 입출력 속도 향상을 위한 C++ 최적화 코드 (선택 사항)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string winner, mine;
    cin >> winner >> mine;

    int cost_sum = 0;

    for (int i = 0; i < n; i++) {
        // 1. 두 문자의 아스키코드 차이(절대값) 계산
        int diff = abs(winner[i] - mine[i]);
        
        // 2. 정방향 거리(diff)와 역방향 거리(26 - diff) 중 최소값을 누적
        cost_sum += min(diff, 26 - diff);
    }

    cout << cost_sum << "\n";

    return 0;
}
