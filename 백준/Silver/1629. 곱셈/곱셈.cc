#include <iostream>

using namespace std;

// a^b % c를 빠르게 구하는 재귀 함수 (분할 정복)
int solve(int a, int b, int c) {
    long long remainder;

    // 1. Base Case (종료 조건)
    // 지수(b)가 0이 되면 어떤 수의 0제곱은 항상 1이므로 1을 반환합니다.
    if (b == 0) {
        return 1;
    }
    
    // 2. 분할 (Divide)
    // b번을 모두 곱하는 대신, 지수를 절반(b/2)으로 나누어 한 번만 계산합니다.
    // 예: 2^10을 구할 때 2^5만 먼저 구합니다.
    long long half = solve(a, b / 2, c);

    // 3. 정복 (Conquer) 및 모듈러 연산
    // 모듈러 분배 법칙: (A * B) % C = ((A % C) * (B % C)) % C
    // 자료형 범위를 초과(오버플로우)하지 않도록 곱셈마다 % c를 해줍니다.
    if (b % 2 == 0) {
        // 지수가 짝수인 경우: a^b = a^(b/2) * a^(b/2)
        // 예: 2^10 = 2^5 * 2^5
        remainder = (half * half) % c;
    } else {
        // 지수가 홀수인 경우: a^b = a^(b/2) * a^(b/2) * a
        // 예: 2^11 = 2^5 * 2^5 * 2^1
        // (half * half) % c를 먼저 한 후 a를 곱하고 다시 % c를 해줍니다.
        remainder = ((half * half) % c * a) % c;
    }

    return remainder;
}

int main() {
    // C++ 입출력 속도 최적화 (알고리즘 문제 풀이 시 필수적인 테크닉)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C;
    // A: 밑, B: 지수, C: 나눌 수
    cin >> A >> B >> C;

    // 계산 결과 받아오기
    long long remainder = solve(A, B, C);

    // 정답 출력
    cout << remainder << "\n";
    
    return 0;
}
