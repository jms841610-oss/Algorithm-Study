#include <iostream>

using namespace std;

int main(){
    // [최적화] C++ 표준 입출력 속도 향상을 위한 구문 (알고리즘 문제 풀이 시 필수적)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // [초기화] 소거법 사용: 처음에는 모든 가능성이 존재한다고 가정 (Flag 변수)
    bool is_rising = true;
    bool is_diving = true;
    bool is_constant = true;

    // [입력] 첫 번째 깊이를 입력받아 초기 비교 기준으로 설정
    int prev;
    cin >> prev;

    // [탐색] 나머지 3개의 깊이 데이터 처리
    for(int i = 0; i < 3; i++){
        int current;
        cin >> current;

        // [비교 및 소거] 이전 값과 현재 값을 비교하여 불가능한 상태를 제거(false)
        if(current < prev){
            // 값이 작아졌으므로 상승(Rising)이거나 일정(Constant)할 수 없음
            is_rising = false;
            is_constant = false;
        }else if(current > prev){
            // 값이 커졌으므로 하강(Diving)이거나 일정(Constant)할 수 없음
            is_diving = false;
            is_constant = false;
        }else{
            // 값이 같으므로 엄격한 상승(Rising)이나 하강(Diving)일 수 없음
            is_rising = false;
            is_diving = false;
        }
        
        // [갱신] 핵심: 다음 반복에서 현재 값을 이전 값으로 사용하기 위해 덮어쓰기
        prev = current;
    }
    
    // [출력] 반복문 종료 후, 끝까지 true로 살아남은 단 하나의 상태를 찾아 출력
    if(is_rising)        cout << "Fish Rising\n";
    else if(is_diving)   cout << "Fish Diving\n";
    else if(is_constant) cout << "Fish At Constant Depth\n";
    else                 cout << "No Fish\n"; // 모든 플래그가 false라면 섞여 있는 상태

    return 0;
}
