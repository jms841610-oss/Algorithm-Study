#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// [함수] 현재 위치(y행, x열)에 퀸을 놓아도 안전한지 검사하는 함수
// y: 현재 퀸을 놓으려는 행, x: 현재 퀸을 놓으려는 열
bool possible(int y, int x, int N, vector<int> &is_visited){
    bool result = true;

    // 0번째 행부터 현재 행(y) 바로 이전(y-1)까지 놓인 퀸들과 비교
    for(int i = 0; i < y; i++){
        int visited_y = i;              // 이전에 놓인 퀸의 행
        int visited_x = is_visited[i];  // 이전에 놓인 퀸의 열

        // 1. 같은 열에 퀸이 있는지 검사: (visited_x == x)
        // 2. 대각선에 퀸이 있는지 검사: abs(x - visited_x) == abs(y - visited_y)
        //    (행의 차이와 열의 차이가 같으면 같은 대각선상에 위치함을 의미)
        if((visited_x == x) || (abs(x - visited_x) == abs(y - visited_y))){
            result = false; // 충돌 발생! 놓을 수 없음
            break;          // 더 이상 검사할 필요가 없으므로 반복문 종료
        }
    }
    return result; // 충돌이 없었다면 true 반환
}

// [함수] 깊이 우선 탐색(DFS)을 이용한 백트래킹(Backtracking) 수행
// current_y: 현재 탐색 중인 행
void DFS(int N, int current_y, int &ans, vector<int> &is_visited){
    // [종료 조건] 모든 행(0 ~ N-1)에 퀸을 성공적으로 배치하여 N번째 행에 도달한 경우
    if(current_y == N){
        ans++; // 가능한 경우의 수 1 증가
        return;
    }
    
    // 현재 행(current_y)의 0열부터 N-1열까지 순차적으로 퀸 배치를 시도
    for(int current_x = 0; current_x < N; current_x++){
        
        // 현재 위치(current_y, current_x)가 안전한 자리인지 검증
        if(possible(current_y, current_x, N, is_visited)){
            
            // 안전하다면 퀸을 배치 (current_y 행의 열 위치를 current_x로 기록)
            is_visited[current_y] = current_x;

            // 다음 행(current_y + 1)에 퀸을 놓기 위해 재귀 호출
            DFS(N, current_y + 1, ans, is_visited);
            
            // [참고] 백트래킹에서 원래 상태로 되돌리는 작업(예: pop_back)이 없는 이유:
            // 1차원 배열을 사용하므로, 다음 반복(current_x가 바뀔 때)에서
            // is_visited[current_y]의 값이 자연스럽게 새로운 값으로 덮어씌워지기 때문입니다.
        }
    }
    return;
}

int main(){
    // [최적화] C++ 표준 스트림의 동기화를 끊어 입출력 속도를 높임
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 1차원 벡터 생성: 크기 N, 모든 값을 0으로 초기화
    // 인덱스 = 행(y), 값 = 열(x)을 의미합니다.
    vector<int> is_visited(N, 0);

    int ans = 0; // 정답(경우의 수)을 저장할 변수

    // 0번째 행부터 퀸 배치를 시작
    DFS(N, 0, ans, is_visited);

    // 최종 계산된 경우의 수 출력
    cout << ans << "\n";
    
    return 0;
}
