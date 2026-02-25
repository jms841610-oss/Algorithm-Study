#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 3차원 6방향 탐색을 위한 방향 배열 (위, 아래, 앞, 뒤, 오른쪽, 왼쪽)
int dz[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {0, 0, 0, 0, 1, -1};

void BFS(vector<vector<vector<int>>> &tomato_status, int height, int length, int width){
    queue<vector<int>> q;
    
    // 방문 여부와 해당 칸까지 도달하는 데 걸린 일수(cost)를 기록하는 3차원 배열
    vector<vector<vector<bool>>> is_visited(height, vector<vector<bool>>(length, vector<bool>(width, false)));
    vector<vector<vector<int>>> cost(height, vector<vector<int>>(length, vector<int>(width, 0)));

    int unriped_tomato = 0; // 안 익은 토마토의 총 개수를 추적

    // 1. 초기 상태 세팅 및 Multi-source BFS 준비
    for(int flr=0; flr<height; flr++){
        for(int row=0; row<length; row++){
            for(int col=0; col<width; col++){
                if(tomato_status[flr][row][col] == 1){
                    // 익은 토마토(1)는 모두 탐색 시작점이 되므로 큐에 한 번에 삽입
                    vector<int> tomato(3);
                    tomato[0] = flr;
                    tomato[1] = row;
                    tomato[2] = col;
                    q.push(tomato);
                } else if(tomato_status[flr][row][col] == 0){
                    // 안 익은 토마토의 초기 개수 카운트
                    unriped_tomato++;
                }
            }
        }
    }
    
    int max_cost = 0; // 토마토가 모두 익는 데 걸린 최대 일수

    // 2. BFS를 통한 동시다발적 탐색 시작
    while(!q.empty()){
        vector<int> current = q.front();
        q.pop();
        
        int current_flr = current[0];
        int current_row = current[1];
        int current_col = current[2];

        // 큐에서 꺼낼 때마다 현재까지의 최대 일수 갱신
        max_cost = max(max_cost, cost[current_flr][current_row][current_col]);

        // 6방향(인접한 위, 아래, 왼쪽, 오른쪽, 앞, 뒤) 확인
        for(int i=0; i<6; i++){
            vector<int> next_tomato(3);
            next_tomato[0] = current_flr + dz[i];
            next_tomato[1] = current_row + dy[i];
            next_tomato[2] = current_col + dx[i];
            
            // 다음 위치가 창고의 범위(경계)를 벗어나지 않는지 확인
            if(0 <= next_tomato[0] && next_tomato[0] < height &&
               0 <= next_tomato[1] && next_tomato[1] < length &&
               0 <= next_tomato[2] && next_tomato[2] < width){

                // 아직 방문하지 않았고, 안 익은 토마토(0)인 경우에만 전파
                if(!is_visited[next_tomato[0]][next_tomato[1]][next_tomato[2]] && 
                   tomato_status[next_tomato[0]][next_tomato[1]][next_tomato[2]] == 0){

                    q.push(next_tomato);
                    // 걸린 일수는 이전 위치의 일수 + 1
                    cost[next_tomato[0]][next_tomato[1]][next_tomato[2]] = cost[current_flr][current_row][current_col] + 1;
                    is_visited[next_tomato[0]][next_tomato[1]][next_tomato[2]] = true;
                    
                    // 토마토가 하나 익었으므로 남은 개수 차감
                    unriped_tomato--;
                }
            }
        }
    }
    
    // 3. 결과 출력
    // 탐색이 끝났는데도 안 익은 토마토가 남아있다면 모두 익지 못하는 상황
    if(unriped_tomato > 0) cout << "-1\n";
    else                   cout << max_cost << "\n";

    return;
}

int main(){
    // 입출력 속도 향상을 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int width, length, height;
    cin >> width >> length >> height;

    // 높이, 세로, 가로 크기에 맞춰 3차원 창고 생성
    vector<vector<vector<int>>> tomato_status(height, vector<vector<int>>(length, vector<int>(width)));

    for(int flr=0; flr<height; flr++){
        for(int row=0; row<length; row++){
            for(int col=0; col<width; col++){
                int status;
                cin >> status;
                tomato_status[flr][row][col] = status;
            }
        }
    }
    
    BFS(tomato_status, height, length, width); 

    return 0;
}
