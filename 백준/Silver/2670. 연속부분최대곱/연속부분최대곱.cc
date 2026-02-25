#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
    // [최적화] C++ 표준 입출력 속도 향상을 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<double> arr(N);

    for(int i=0; i<N; i++){
        double input;
        cin >> input;
        arr[i] = input;
    }

    // [핵심 초기화] 
    // 곱셈 누적을 위해 1.0으로 시작하지 않고, 
    // 배열의 첫 번째 원소부터 시작하여 카다네 알고리즘 적용
    double current_max = arr[0]; // 현재 인덱스에서 끝나는 연속 구간의 최대 곱
    double total_max   = arr[0]; // 전체 배열을 통틀어 발견한 가장 큰 연속 구간의 곱

    // 1번 인덱스부터 끝까지 단 한 번만 순회 (O(N) 시간 복잡도)
    for(int i=1; i<N; i++){
        // [동적 계획법 핵심 점화식]
        // 1. (이전까지의 최대 곱 * 현재 값): 기존 구간을 연장하는 경우
        // 2. (현재 값): 기존 구간을 버리고 현재 위치부터 새로 구간을 시작하는 경우
        // 둘 중 더 큰 값을 현재 위치의 최대 곱으로 갱신
        current_max = max(current_max * arr[i], arr[i]);
        
        // 전체 최댓값을 지속적으로 갱신
        total_max   = max(total_max, current_max);
    }
    
    // [출력 포맷팅]
    // 지수 표기법(e)을 방지하고 일반 고정 소수점(fixed)으로 출력
    // 소수점 4번째 자리에서 자동으로 반올림하여 3째 자리까지 출력(setprecision)
    cout << fixed << setprecision(3);

    cout << total_max << "\n";

    return 0;
}
