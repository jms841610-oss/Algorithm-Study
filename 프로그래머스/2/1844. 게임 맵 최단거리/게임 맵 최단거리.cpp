#include <vector>
#include <queue>

using namespace std;

// 도달할 수 없는 경우를 판별하기 위해 아주 큰 값(무한대)을 설정합니다.
const int INF = 2e9;

int solution(vector<vector<int>> maps)
{
    // 1. 맵의 세로(n)와 가로(m) 크기를 구합니다.
    int n = maps.size();
    int m = maps[0].size();
    
    // 2. 상하좌우 탐색을 위한 방향 배열 (y축, x축)
    // 차례대로 {하, 우, 상, 좌} 방향 이동을 의미합니다.
    int dy[] = {1, 0, -1, 0};
    int dx[] = {0, 1, 0, -1};
    
    // 3. BFS 탐색을 위한 큐 생성 (탐색할 위치의 y, x 좌표 쌍을 담습니다)
    queue<pair<int, int>> q;
    
    // 각 칸까지 도달하는 데 걸리는 최단 거리를 기록하는 배열 (초기값은 INF)
    vector<vector<int>> cost(n, vector<int>(m, INF));
    // 무한 루프를 방지하기 위해 해당 칸의 방문 여부를 기록하는 배열 (초기값은 false)
    vector<vector<bool>> is_visited(n, vector<bool>(m, false));
    
    // 4. 시작점(0, 0) 초기화 세팅
    q.push({0, 0});             // 큐에 시작점을 넣고 탐색 준비를 합니다.
    is_visited[0][0] = true;    // 시작점 방문 처리
    cost[0][0] = 1;             // 문제의 조건에 따라 시작점의 칸 수도 1로 셉니다.
    
    // 5. BFS 탐색 시작 (큐가 빌 때까지, 즉 더 이상 갈 수 있는 길이 없을 때까지 반복)
    while(!q.empty()){
        // 큐의 맨 앞에 있는 현재 위치를 꺼내옵니다.
        pair<int, int> p = q.front();
        q.pop(); 
        
        int current_y = p.first;
        int current_x = p.second;
        int current_cost = cost[current_y][current_x]; // 현재 위치까지 누적된 이동 거리
        
        // 현재 위치에서 상하좌우 4가지 방향으로 모두 이동해 봅니다.
        for(int i = 0; i < 4; i++){
            int next_y = current_y + dy[i];
            int next_x = current_x + dx[i];
            
            // 조건 1: 이동하려는 다음 칸이 맵의 범위(0~n-1, 0~m-1) 안에 있는지 확인
            if(next_y >= 0 && next_y < n && next_x >= 0 && next_x < m){
                // 조건 2: 다음 칸이 벽(0)이 아니라 갈 수 있는 길(1)인지 확인
                if(maps[next_y][next_x] == 1){
                    // 조건 3: 이전에 이미 방문했던 칸인지 확인 (중복 탐색 방지)
                    if(!is_visited[next_y][next_x]){
                        
                        // 위 조건을 모두 만족하면 새로운 길을 찾은 것입니다!
                        is_visited[next_y][next_x] = true;          // 방문 처리
                        cost[next_y][next_x] = current_cost + 1;    // 거리는 현재 거리 + 1로 갱신
                        q.push({next_y, next_x});                   // 다음 탐색을 위해 큐에 새 위치 추가
                    }
                }
            }
        }
    }
    
    // 6. 목적지인 우측 하단(n-1, m-1)의 최단 거리 확인
    int answer = cost[n-1][m-1];
    
    // 목적지의 거리가 여전히 INF라면, 길이 막혀서 도달하지 못했다는 뜻이므로 -1 반환
    if(answer == INF) return -1;
    // 무사히 도달했다면 기록된 최단 거리 반환
    else return answer;
}
