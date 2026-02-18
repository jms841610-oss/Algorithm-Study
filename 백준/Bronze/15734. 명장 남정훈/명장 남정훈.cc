#include <iostream>

using namespace std;

int main() {
    // [입출력 최적화]
    // C++의 표준 스트림과 C 스트림 간의 동기화를 끊어 입출력 속도를 높임.
    // 대량의 데이터를 처리할 때 필수적임.
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, R, A; // [자료형 주의] 입력값이 21억을 넘을 경우 int는 오버플로우 발생 가능. 안전하게 long long 권장.
    cin >> L >> R >> A;

    // [핵심 로직: 시뮬레이션]
    // A(추가 인원/점수)를 하나씩 소모하며 L과 R의 균형을 맞춤.
    // 주의: 이 방식은 A나 |L-R|이 매우 클 경우(예: 10억) 시간 초과(TLE)가 발생할 수 있음.
    while (A != 0) {
        if (L > R) {
            // L이 더 크면 R을 키워 격차를 줄임
            R++;
            A--;
        } else if (R > L) {
            // R이 더 크면 L을 키워 격차를 줄임
            L++;
            A--;
        } else {
            // [최적화 로직] L == R 인 경우
            // 남은 A를 공평하게 나누어 가지고 반복문을 탈출함.
            // 하나씩 분배하는 시뮬레이션을 수학적 연산(O(1))으로 단축시킨 부분.
            long long half = A / 2;
            L += half;
            R += half;
            // A를 홀수만큼 가지고 있었다면 1이 남지만, 
            // 어차피 균형을 깰 수 없으므로 버리는 것이 최적해임.
            break; 
        }
    }

    // [결과 출력]
    // 둘 중 작은 값 * 2가 만들 수 있는 최대 균형 팀 사이즈
    // min(L, R) * 2 와 동일한 로직
    if (L < R) cout << L * 2 << endl;
    else       cout << R * 2 << endl;

    return 0;
}
