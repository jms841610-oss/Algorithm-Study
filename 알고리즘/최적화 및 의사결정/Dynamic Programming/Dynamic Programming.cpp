#include <iostream>
#include <vector>

using namespace std;

// 피보나치 수열을 바텀업(Bottom-up) 방식으로 구하는 DP 함수
long long getFibonacci(int n) {
    // 1. n이 0이나 1일 경우의 예외 처리
    if (n == 0) return 0;
    if (n == 1) return 1;

    // 2. 작은 문제들의 결과를 기억할 '메모장(DP 테이블)' 생성
    // 인덱스와 몇 번째 수인지 일치시키기 위해 n + 1 크기로 만듭니다.
    vector<long long> dp(n + 1, 0);

    // 3. 가장 작은 문제들의 초기값 설정 (0번째는 0, 1번째는 1)
    dp[0] = 0;
    dp[1] = 1;

    // 4. 점화식을 바탕으로 바텀업 방식으로 테이블 채우기
    // 점화식: 앞의 두 수를 더하면 현재 수가 된다 (dp[i] = dp[i-1] + dp[i-2])
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // 5. 최종적으로 구하고자 하는 n번째 결과 반환
    return dp[n];
}

int main() {
    // 구하고자 하는 피보나치 수열의 번째 수
    // 50번째 피보나치 수는 매우 크기 때문에 일반 재귀로 풀면 엄청난 시간이 걸립니다!
    int n = 50; 

    cout << "계산할 피보나치 수열의 순서: " << n << "번째\n";

    // DP 알고리즘 실행
    long long result = getFibonacci(n);

    // 결과 출력
    cout << "정답! " << n << "번째 피보나치 수: " << result << "\n";

    return 0;
}
