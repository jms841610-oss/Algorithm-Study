#include<vector>
#include<queue>

using namespace std;

// 도달할 수 없는 경우를 표시하기 위한 무한대 값 설정 (안전하게 20억으로 설정)
const int INF = 2e9; 

int solution(vector<vector<int> > maps)
{
    // 1. 맵의 크기 구하기
    int n = maps.size();    // 세로 길이 (행의 개수)
    int m = maps[0].size(); // 가로 길이 (열의 개수)
    
    // 2. 상하좌우 이동을 위한 방향 배열 설정
    // 현재 위치에서 {아래, 오른쪽, 위, 왼쪽} 순서로 탐색하도록 매핑됨
    int dy[] = {1, 0, -1, 0}; // y축 (행) 이동량
    int dx[] = {0, 1, 0, -1}; // x축 (열) 이동량
    
    // 3. BFS 탐색을 위한 자료구조 초기화
    queue<pair<int,int>> q; // 방문할 좌표(y, x)를 담을 큐
    // 최단 거리를 저장할 2D 배열 (초기값은 도달 불가 상태인 INF로 세팅)
    vector<vector<int>> cost(n, vector<int>(m, INF)); 
    // 방문 여부를 체크할 2D 배열 (재방문 방지용, 초기값은 false)
    vector<vector<bool>> is_visited(n, vector<bool>(m, false)); 
    
    // 4. 시작점 (0, 0) 설정
    q.push({0,0});             // 큐에 시작점 넣기
    is_visited[0][0] = true;   // 시작점 방문 처리
    cost[0][0] = 1;            // 시작점의 거리는 1 (문제 조건에 따라 시작칸도 포함)
    
    // 5. BFS 탐색 시작
    while(!q.empty()){
        // 큐의 맨 앞에 있는 현재 위치를 꺼냄
        pair<int,int> p = q.front();
        int current_y = p.first;  // 현재 y 좌표
        int current_x = p.second; // 현재 x 좌표
        int current_cost = cost[current_y][current_x]; // 현재까지 이동한 거리
        
        q.pop(); // 큐에서 제거
        
        // 상하좌우 4가지 방향으로 이동 시도
        for(int i = 0; i < 4; i++){
            int next_y = current_y + dy[i]; // 다음 y 좌표
            int next_x = current_x + dx[i]; // 다음 x 좌표
            
            // 조건 1: 다음 이동할 좌표가 맵의 범위(0~n-1, 0~m-1) 안에 있는지 확인 (배열 범위 초과 에러 방지)
            if(((0 <= next_y) && (next_y < n)) && ((0 <= next_x) && (next_x < m))){
                
                // 조건 2: 다음 이동할 좌표가 벽(0)이 아니라 지나갈 수 있는 길(1)인지 확인
                if(maps[next_y][next_x] == 1){
                    
                    // 조건 3: 이전에 방문한 적이 없는 칸인지 확인 (중복 방문 방지)
                    if(!is_visited[next_y][next_x]){
                    
                        // 모든 조건을 만족하면 큐에 넣고 거리와 방문 상태를 갱신!
                        is_visited[next_y][next_x] = true;                 // 방문 완료 처리
                        cost[next_y][next_x] = current_cost + 1;           // 이전 칸까지의 거리 + 1
                        q.push({next_y, next_x});                          // 다음 탐색을 위해 큐에 삽입
                    }
                }
            }
        }
    }
    
    // 6. 도착점의 최단 거리 확인
    int answer = cost[n-1][m-1]; // 우측 하단(도착점)의 누적 거리 값
    
    // 만약 도착점의 거리가 여전히 INF라면, 벽에 가로막혀 도달하지 못했다는 뜻이므로 -1 반환
    if(answer == INF) return -1; 
    // 성공적으로 도달했다면 최단 거리 반환
    else              return answer; 
}
