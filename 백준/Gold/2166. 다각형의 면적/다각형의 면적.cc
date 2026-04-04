#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // 입출력 속도 향상을 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // 오버플로우 방지를 위해 x, y 좌표를 double형으로 받거나 계산 시 형변환을 합니다.
    // 여기서는 넓이를 구할 때 바로 double형으로 계산되도록 타입을 지정했습니다.
    vector<pair<double, double>> poly(N);

    // 1단계: 꼭짓점 좌표 입력받기
    for(int i = 0; i < N; i++) {
        cin >> poly[i].first >> poly[i].second;
    }

    double area = 0.0;

    // 2단계: 신발끈 공식 적용
    for(int i = 0; i < N; i++) {
        // 다음 꼭짓점의 인덱스를 구합니다. 
        // 마지막 꼭짓점(N-1)의 다음은 다시 첫 번째(0)로 돌아가도록 모듈로(%) 연산을 사용합니다.
        int next_i = (i + 1) % N; 

        // 외적 공식을 이용해 다각형의 넓이를 누적합니다.
        area += (poly[i].first * poly[next_i].second) - (poly[i].second * poly[next_i].first);
    }

    // 3단계: 절댓값을 씌우고 2로 나누어 최종 넓이 산출
    area = abs(area) / 2.0;

    // 4단계: 소수점 첫째 자리까지 출력
    cout << fixed << setprecision(1);
    cout << area << "\n";

    return 0;
}
