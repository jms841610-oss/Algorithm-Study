/**
 * [문제 유형] 2차원 격자(미로) 최단 경로 탐색
 * [핵심 알고리즘] BFS (너비 우선 탐색)
 * * [Key Point 복습]
 * 1. 가중치가 없는 2차원 맵의 최단 거리는 무조건 BFS를 사용한다. (DFS는 최단 거리를 보장하지 않음)
 * 2. 공백 없이 연속된 숫자가 입력으로 들어올 때는 정수형(int)으로 받으면 오버플로우나 앞자리 0 소실 문제가 발생한다.
 * 반드시 문자열(string)로 입력받아 각 문자를 '0'으로 빼주어 정수로 변환(파싱)해야 안전하다.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// (y좌표, x좌표) 쌍을 쉽게 다루기 위해 별칭 지정
using node = pair<int,int>;

int get_len(vector<vector<int>> &is_movable, int N, int M){
    vector<vector<bool>> is_visited(N, vector<bool>(M, false));
    vector<vector<int>> len(N, vector<int>(M, 0));
    queue<node> q;
    
    // 상하좌우 이동을 위한 방향 배열 (y축 이동량, x축 이동량)
    // 순서대로 하(Down), 우(Right), 상(Up), 좌(Left)
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
    
    node start;
    start.first = 0;
    start.second = 0;
    q.push(start);
    is_visited[0][0] = true;
    len[0][0] = 1;

    while(!q.empty()){
        node front = q.front();
        q.pop();

        int front_y = front.first;
        int front_x = front.second;

        // 도착점 도달 시 거리 반환
        if((front_y == N-1) && (front_x == M-1)) return len[front_y][front_x];

        // 4방향 탐색을 for문 하나로 처리
        for(int i = 0; i < 4; i++) {
            int next_y = front_y + dy[i];
            int next_x = front_x + dx[i];

            // 1. 맵의 경계(Bound)를 벗어나지 않는지 가장 먼저 체크
            if(next_y >= 0 && next_y < N && next_x >= 0 && next_x < M) {
                // 2. 이동할 수 있는 칸이고, 방문하지 않은 칸인지 체크
                if(is_movable[next_y][next_x] && !is_visited[next_y][next_x]) {
                    q.push({next_y, next_x});
                    is_visited[next_y][next_x] = true;
                    len[next_y][next_x] = len[front_y][front_x] + 1;
                }
            }
        }
    }
    return -1;
}

int main(){
    // C++ 표준 입출력 속도 향상을 위한 필수 구문 (알고리즘 문제 풀이용)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> is_movable(N, vector<int>(M));

    for(int row = 0; row < N; row++){
        string line;
        cin >> line; // 연속된 숫자를 하나의 문자열로 통째로 입력받음
        for(int col = 0; col < M; col++){
            // 문자를 숫자로 파싱 (아스키코드 원리: '0'은 48, '1'은 49이므로 '1'-'0' = 1)
            is_movable[row][col] = line[col] - '0';
        }
    }
    
    int min_len = get_len(is_movable, N, M);

    cout << min_len << "\n";

    return 0;
}
