#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// [최적화 포인트 1] 고정 크기 구조체 사용
// vector<int> 대신 구조체를 사용하여 큐 삽입/삭제 시 발생하는 힙(Heap) 영역의 동적 할당 오버헤드를 제거
// 스택(Stack) 메모리에서 값 복사만 일어나므로 실행 속도가 크게 향상됨
struct Tomato {
    int flr, row, col;
};

// 3차원 6방향(위, 아래, 앞, 뒤, 오른쪽, 왼쪽) 탐색을 위한 방향 배열
int dz[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {0, 0, 0, 0, 1, -1};

void BFS(vector<vector<vector<int>>> &tomato_status, int height, int length, int width){
    queue<Tomato> q;
    
    // 방문 여부 및 걸린 일수(Cost)를 기록하는 3차원 배열
    vector<vector<vector<bool>>> is_visited(height, vector<vector<bool>>(length, vector<bool>(width, false)));
    vector<vector<vector<int>>> cost(height, vector<vector<int>>(length, vector<int>(width, 0)));

    // [최적화 포인트 2] 안 익은 토마토 개수 추적기
    // 이 변수 덕분에 BFS 종료 후 맵 전체를 다시 O(V)로 순회하며 안 익은 토마토를 찾을 필요가 없음
    int unriped_tomato = 0;

    // 1. 초기 상태 세팅 (Multi-source BFS)
    for(int flr=0; flr<height; flr++){
        for(int row=0; row<length; row++){
            for(int col=0; col<width; col++){
                if(tomato_status[flr][row][col] == 1){
                    // 익은 토마토(1)는 모두 탐색 시작점이 되므로 큐에 한 번에 삽입 (C++11 Uniform Initialization 활용)
                    q.push({flr, row, col});
                } else if(tomato_status[flr][row][col] == 0){
                    unriped_tomato++;
                }
            }
        }
    }
    
    int max_cost = 0;

    // 2. BFS 탐색 진행
    while(!q.empty()){
        Tomato current = q.front();
        q.pop();
        
        int current_flr = current.flr;
        int current_row = current.row;
        int current_col = current.col;

        // 큐에서 꺼낸 토마토의 도달 일수로 최대 일수 갱신
        max_cost = max(max_cost, cost[current_flr][current_row][current_col]);

        // 6방향 인접 칸 확인
        for(int i=0; i<6; i++){
            Tomato next_tomato;
            next_tomato.flr = current_flr + dz[i];
            next_tomato.row = current_row + dy[i];
            next_tomato.col = current_col + dx[i];
            
            // 창고 경계(범위) 내에 있는지 확인
            if(0 <= next_tomato.flr && next_tomato.flr < height &&
               0 <= next_tomato.row && next_tomato.row < length &&
               0 <= next_tomato.col && next_tomato.col < width){

                // 미방문 상태이며, 안 익은 토마토(0)인 경우에만 큐에 추가
                if(!is_visited[next_tomato.flr][next_tomato.row][next_tomato.col] && 
                   tomato_status[next_tomato.flr][next_tomato.row][next_tomato.col] == 0){

                    q.push(next_tomato);
                    cost[next_tomato.flr][next_tomato.row][next_tomato.col] = cost[current_flr][current_row][current_col] + 1;
                    is_visited[next_tomato.flr][next_tomato.row][next_tomato.col] = true;
                    
                    // 토마토가 새로 익었으므로 카운트 감소
                    unriped_tomato--;
                }
            }
        }
    }
    
    // 3. 결과 출력
    // 안 익은 토마토가 남아 있다면 모두 익히는 것이 불가능한 상황
    if(unriped_tomato > 0) cout << "-1\n";
    else                   cout << max_cost << "\n";

    return;
}

int main(){
    // C++ 표준 입출력 동기화 해제로 실행 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int width, length, height;
    cin >> width >> length >> height;

    // 입력 크기에 맞게 3차원 상태 배열 메모리 할당
    vector<vector<vector<int>>> tomato_status(height, vector<vector<int>>(length, vector<int>(width)));

    // 토마토 창고 상태 입력
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
