#include <iostream>
#include <vector>

using namespace std;

int N, M;

// [공간 복잡도 O(N*M)] 캠퍼스의 맵 정보와 방문 상태를 저장할 2차원 벡터 
// 최대 크기인 600x600으로 초기화
vector<vector<char>> campus(600, vector<char>(600));
vector<vector<bool>> is_visited(600, vector<bool>(600, false));

// 만난 사람의 수를 저장할 전역 변수
int cnt = 0;

/**
 * @brief 깊이 우선 탐색(DFS)을 이용해 상하좌우로 이동하며 사람을 찾는 함수
 * @param row 현재 방문 중인 행 좌표
 * @param col 현재 방문 중인 열 좌표
 */
void visiting(int row, int col) {
    // 1. [핵심 최적화] 가장 먼저 현재 위치 방문 처리
    // 이 처리를 벽('X') 검사보다 먼저 함으로써, 벽에 대해서도 방문 처리가 되어
    // 다른 칸에서 이 벽을 향해 불필요하게 다시 탐색하는 중복 연산을 방지함.
    is_visited[row][col] = true;
    
    // 2. Base Condition: 벽을 만나면 더 나아가지 않고 탐색 종료
    if (campus[row][col] == 'X') return;
    
    // 3. 사람을 만난 경우 카운트 증가
    if (campus[row][col] == 'P') cnt++;
    
    // 4. 인접한 4방향(하, 우, 상, 좌) 탐색
    // 조건: 캠퍼스 맵의 경계(N, M)를 벗어나지 않고, 아직 방문하지 않은 칸일 때만 재귀 호출
    if ((row + 1 < N) && (!is_visited[row + 1][col])) visiting(row + 1, col);
    if ((col + 1 < M) && (!is_visited[row][col + 1])) visiting(row, col + 1);
    if ((row - 1 >= 0) && (!is_visited[row - 1][col])) visiting(row - 1, col);
    if ((col - 1 >= 0) && (!is_visited[row][col - 1])) visiting(row, col - 1);

    return;
}

int main() {
    // C++ 알고리즘 풀이용 입출력 속도 향상 구문
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 캠퍼스 크기 입력
    cin >> N >> M;

    pair<int, int> me; // 시작점('I')의 좌표를 저장할 변수

    // 맵 정보 입력 및 시작점 탐색
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            char info;
            cin >> info;
            campus[row][col] = info;
            
            // 입력받은 정보가 도연이('I')라면 좌표 저장
            if (info == 'I') {
                me.first  = row;
                me.second = col;
            }
        }
    }
    
    // 도연이의 위치에서 탐색 시작
    visiting(me.first, me.second);

    // 출력 시 endl 대신 '\n'을 사용하여 버퍼 플러시로 인한 속도 저하 방지
    if (cnt) cout << cnt  << '\n';
    else     cout << "TT" << '\n';
    
    return 0;
}
