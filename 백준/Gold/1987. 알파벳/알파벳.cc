#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 상하좌우 이동을 위한 배열
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void DFS(int current_y, int current_x, int total, int height, int width, int &ans, vector<vector<int>> &area, vector<bool> &is_visited) {
    int current = area[current_y][current_x];

    // 최댓값 갱신
    ans = max(ans, total);
    
    // 상하좌우 4방향 탐색
    for(int i = 0; i < 4; i++){
        int next_y = current_y + dy[i];
        int next_x = current_x + dx[i];

        // 맵의 범위를 벗어나지 않는지 확인
        if((0 <= next_y && next_y < height) && (0 <= next_x && next_x < width)){
            int next = area[next_y][next_x];

            // 아직 방문하지 않은 알파벳인지 확인
            if(!is_visited[next]){
                
                is_visited[next] = true; // 방문 처리
                
                // 다음 칸으로 이동 (재귀 호출)
                DFS(next_y, next_x, total + 1, height, width, ans, area, is_visited);

                is_visited[next] = false; // 백트래킹 (방문 처리 해제)
            }
        }
    }
    return;
}

int main(){
    // 입출력 속도 향상을 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int height, width;
    
    // [수정된 부분] 쉼표 대신 >> 연산자를 사용합니다!
    cin >> height >> width;

    // height x width 크기의 2차원 벡터 생성
    vector<vector<int>> area(height, vector<int>(width));
    
    // 맵 정보 입력받기
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            char ch;
            cin >> ch;

            // 'A'를 빼주어 0~25 사이의 숫자로 변환
            int digit = ch - 'A';
            area[row][col] = digit;
        }
    }
    
    int ans = 0;
    // 알파벳 A~Z를 나타내는 26칸짜리 방문 체크 배열
    vector<bool> is_visited(26, false);
    
    // 시작점 설정 및 방문 처리
    int start = area[0][0];
    is_visited[start] = true;
    
    // (0, 0)에서 시작하며 초기 이동 칸 수는 1
    DFS(0, 0, 1, height, width, ans, area, is_visited);

    // 정답 출력
    cout << ans << "\n";
    
    return 0;
}
