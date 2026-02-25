#include <iostream>
#include <vector>

using namespace std;

// 상하좌우 탐색을 위한 방향 벡터
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

// [1] 일반인 기준 DFS 탐색
void DFS(vector<string> &color, int row, int col, vector<vector<bool>> &is_visited, int N) {
    is_visited[row][col] = true;
    char current = color[row][col]; 

    for(int i=0; i<4; i++){
        int next_y = row + dy[i];
        int next_x = col + dx[i];

        // 맵의 범위를 벗어나지 않으면서
        if((0<=next_y) && (next_y<N) && (0<=next_x) && (next_x<N)){
            // 아직 방문하지 않았고, '완전히 같은 색상'일 때만 탐색 진행
            if((!is_visited[next_y][next_x]) && (current == color[next_y][next_x])){
                DFS(color, next_y, next_x, is_visited, N);
            }
        }
    }
    return;
}

// [2] 적록색약 기준 DFS 탐색 (이 문제의 핵심 로직)
void blind_DFS(vector<string> &blind_color, int row, int col, vector<vector<bool>> &blind_is_visited, int N) {
    blind_is_visited[row][col] = true;
    char current = blind_color[row][col]; 

    for(int i=0; i<4; i++){
        int next_y = row + dy[i];
        int next_x = col + dx[i];

        if((0<=next_y) && (next_y<N) && (0<=next_x) && (next_x<N)){
            if(!blind_is_visited[next_y][next_x]){
                
                // 조건 1: 현재 색상이 R이나 G이면서, 다음 탐색할 칸도 R이나 G인 경우 (같은 구역으로 취급)
                if(((current == 'R') || (current == 'G')) && ((blind_color[next_y][next_x] == 'R') || (blind_color[next_y][next_x] == 'G'))){
                    blind_is_visited[next_y][next_x] = true;
                    blind_DFS(blind_color, next_y, next_x, blind_is_visited, N);

                // 조건 2: 현재 색상이 B이면서, 다음 탐색할 칸도 B인 경우
                } else if((current == 'B') && (blind_color[next_y][next_x] == 'B')){
                    blind_is_visited[next_y][next_x] = true;
                    blind_DFS(blind_color, next_y, next_x, blind_is_visited, N);
                }
            }
        }
    }
    return;
}

int main() {
    // 입출력 속도 향상을 위한 최적화 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 원본 데이터를 훼손하지 않기 위해 색상 배열을 할당
    vector<string> color(N);
    vector<string> blind_color(N);

    for(int row=0; row<N; row++){
        string line;
        cin >> line;
        color[row] = line;
        blind_color[row] = line; // 초기 데이터는 일반인 배열과 동일하게 세팅
    }

    // 각각의 방문 여부를 독립적으로 체크하기 위한 배열 분리
    vector<vector<bool>> is_visited(N, vector<bool>(N, false));
    vector<vector<bool>> blind_is_visited(N, vector<bool>(N, false));

    int cnt = 0;       // 일반인 구역 개수
    int blind_cnt = 0; // 적록색약 구역 개수

    // 일반인 기준 탐색 실행
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            // 방문하지 않은 새로운 구역을 발견할 때마다 카운트 증가 및 탐색 시작
            if(!is_visited[row][col]){
                DFS(color, row, col, is_visited, N);
                cnt++;
            }
        }
    }

    // 적록색약 기준 탐색 실행
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            if(!blind_is_visited[row][col]){
                blind_DFS(blind_color, row, col, blind_is_visited, N);
                blind_cnt++;
            }
        }
    }

    cout << cnt << " " << blind_cnt << "\n";

    return 0;
}
