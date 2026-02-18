/**
 * @file main.cpp
 * @brief 면적 계산 및 필요 물품 개수 구하기 (Ceiling Division)
 * @details
 * - 입력받은 가로(X), 세로(Y)를 이용해 전체 면적을 구하고,
 * - 특정 단위(one_bag)로 나누었을 때 필요한 최소 개수를 구하는 로직.
 * - 핵심: 나눗셈의 나머지가 있을 때 무조건 올림 처리하는 정수 연산 테크닉 사용.
 *
 * @author (작성자 성함)
 * @date 2026-02-18
 */

#include <iostream>

using namespace std;

int main() {
    // [Fast I/O] 입출력 속도 향상 (대량의 데이터 입력 시 필수)
    // C++의 iostream과 C의 stdio 동기화를 끊어 속도를 높임
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // [자료형 선택 중요]
    // 입력값 X, Y의 범위에 따라 곱셈 결과가 int 범위를 초과할 수 있음 (21억 이상).
    // 따라서 안전하게 64비트 정수형인 long long을 사용함.
    long long X, Y;

    if (!(cin >> X >> Y)) return 0; // 입력 예외 처리 (선택 사항)

    // [면적 계산]
    // X와 Y가 큰 경우, 결과가 int를 넘을 수 있으므로 area 변수도 long long이어야 함.
    long long area = X * Y;

    // [단위 상수 정의]
    // 한 포대가 커버하는 면적: 5 * 4840
    // one_bag은 약 24,200으로 int 범위 내에 충분히 들어옴.
    int one_bag = 5 * 4840;

    // [핵심 로직: 올림 나눗셈 (Ceiling Division)]
    // 일반적인 정수 나눗셈(area / one_bag)은 소수점을 버림(Floor).
    // 나머지가 있을 때 1을 더해주기 위해 다음과 같은 공식을 사용함.
    // 공식: ceil(A / B) = (A + B - 1) / B  또는  (A - 1) / B + 1
    //
    // * 주의: area가 0일 경우 이 식은 1을 반환할 수 있으므로, area > 0 인 전제 하에 유효함.
    // * 주의: need 값 자체가 int 범위를 넘을 수도 있으므로(면적이 매우 클 때),
    //         안전하게 long long을 사용하는 것이 더 좋음.
    long long need = ((area - 1) / one_bag) + 1;

    cout << need << endl;

    return 0;
}
