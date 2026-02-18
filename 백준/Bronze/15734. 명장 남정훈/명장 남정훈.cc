#include <iostream>
#include <algorithm> // max, min, abs 함수 사용을 위해 권장

using namespace std;

/**
 * [문제 해결 전략: 수학적 접근 (Mathematical approach)]
 * * 1. 목표: 두 그룹(L, R)의 차이(diff)를 A(보조 인원)로 메워 균형을 맞춘 뒤,
 * 최대 쌍(Pair)의 수를 구하는 것.
 * * 2. 접근 방식:
 * - 반복문(Simulation)을 사용하면 A가 클 때 시간 초과(TLE) 발생 가능성 있음.
 * - 따라서, 조건문(if-else)과 산술 연산만을 사용하여 O(1)로 해결함.
 */

int main() {
    // [입출력 최적화]
    // C++ 표준 스트림의 버퍼 동기화를 끊어 대량의 입출력 속도를 향상시킴.
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int L, R, A;
    cin >> L >> R >> A;

    // 현재 두 그룹 간의 격차 계산
    int diff = abs(L - R);
    int max_val = max(L, R);
    
    // [핵심 로직]
    // Case 1: A가 부족하여 격차를 완전히 메울 수 없는 경우
    if (diff > A) {
        // A를 전부 소모하여 격차를 줄임 (A는 0이 됨)
        diff -= A; 
        A = 0; 
    } 
    // Case 2: A가 충분하여 격차를 메우고도 남거나 딱 맞는 경우
    else {
        // 격차를 메우는 데 필요한 만큼 A를 사용
        A -= diff; 
        diff = 0; // 이제 두 그룹의 크기는 같아짐 (max_val로 평준화)
    }

    // [결과 도출]
    // diff가 남아있다면(Case 1), min_val은 원래 작은 값 + A가 됨.
    // diff가 0이라면(Case 2), min_val은 max_val과 같아짐.
    int current_balanced_min = max_val - diff;
    
    // 최종 쌍의 개수 = (균형 맞춰진 최소값 + 남은 A를 반으로 나눈 값) * 2
    // 남은 A가 홀수일 경우, 1명은 짝을 이룰 수 없으므로 버림(integer division).
    int result = (current_balanced_min + (A / 2)) * 2;

    cout << result << endl;

    return 0;
}
