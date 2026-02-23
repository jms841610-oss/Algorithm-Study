#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// pair를 node라는 별칭으로 사용하여 가독성을 높임 (first: y좌표, second: x좌표)
using node = pair<int,int>;

// 상, 우, 하, 좌 4방향 탐색을 위한 방향 벡터 설정
// 하드코딩보다 이렇게 배열을 만들어두면 반복문으로 깔끔하게 상하좌우 탐색이 가능함
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

void BFS(int height, int width, vector<vector<bool>> &is_able, node start){
    queue<node> q;
    
    // 방문 여부와 도달 비용(최단 거리)을 저장할 2차원 벡터 초기화
    vector<vector<bool>> is_visited(height, vector<bool>(width, false));
    vector<vector<int>> taken_cost(height, vector<int>(width, 0));

    // 시작점 세팅
    q.push(start);
    is_visited[start.first][start.second] = true;
    taken_cost[start.first][start.second] = 0; // 시작점의 거리는 0

    while(!q.empty()){
        node front = q.front();
        q.pop();

        // 현재 위치에서 4방향(상하좌우) 탐색
        for(int i = 0; i < 4; i++){
            node next;
            next.first  = front.first  + dy[i]; // 다음 y 좌표
            next.second = front.second + dx[i]; // 다음 x 좌표
            
            // 1. 격자 범위를 벗어나지 않았는지 확인 (Out of Bounds 방지)
            if((0 <= next.first) && (next.first < height) && (0 <= next.second) && (next.second < width)){
                // 2. 갈 수 있는 땅(is_able)이면서, 아직 방문하지 않은 곳(!is_visited)인지 확인
                if((is_able[next.first][next.second]) && (!is_visited[next.first][next.second])){
                    q.push(next);
                    is_visited[next.first][next.second] = true;
                    // 다음 칸의 거리는 현재 칸의 거리 + 1
                    taken_cost[next.first][next.second] = taken_cost[front.first][front.second] + 1;
                }
            }
        }
    }
    
    // 결과 출력부
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            if(is_able[row][col]){
                // 원래 갈 수 있는 땅인데 도달했다면 거리 출력, 방문하지 못했다면(고립된 곳) -1 출력
                if(is_visited[row][col]) cout << taken_cost[row][col] << " ";
                else                     cout << -1 << " ";
            } else {
                // 애초에 갈 수 없는 땅(벽 등)은 0 출력
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
    return;
}

int main(){
    // C++ 표준 스트림의 동기화를 끊어 입출력 속도를 C 언어 수준으로 최적화하는 구문
    // 알고리즘 문제 풀이 시 시간 초과 방지를 위한 필수 테크닉
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int height, width;
    cin >> height >> width;

    // 갈 수 있는 땅인지 확인할 bool 타입의 2차원 배열. false로 초기화.
    vector<vector<bool>> is_able(height, vector<bool>(width, false));
    node start;

    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            int k;
            cin >> k;
            
            if(k == 1){
                // 1은 이동 가능한 땅
                is_able[row][col] = true;
            } else if(k == 2){
                // 2는 시작점, 시작점 위치를 기록해둠 (시작점 자체도 나중에 0으로 처리되거나 
                // 다른 로직을 탈 수 있으나, 위 BFS 내부에서 0으로 초기화 됨)
                start.first  = row;
                start.second = col;
            }
            // k가 0인 경우는 is_able이 false로 남아있으므로 별도 처리 생략 가능 (효율적)
        }
    }
    
    // 함수 호출 시 is_able 벡터를 참조(&)로 넘겨 불필요한 복사 비용을 줄임
    BFS(height, width, is_able, start);

    return 0;
}
