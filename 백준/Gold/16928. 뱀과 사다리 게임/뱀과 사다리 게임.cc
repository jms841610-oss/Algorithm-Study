#include <iostream>
#include <queue>

using namespace std;

// 뱀과 사다리 게임의 최소 이동 횟수를 구하는 BFS 함수
int BFS(int move[]){
    bool is_visited[101] = {false}; // 각 보드 칸의 방문 여부 체크
    int cost[101] = {0};            // 각 칸에 도달하기 위해 주사위를 굴린 횟수
    queue<int> order;

    // 시작점(1번 칸) 초기화
    order.push(1);
    is_visited[1] = true;
    cost[1] = 0;

    while(!order.empty()){
        int current = order.front();
        order.pop();

        // 목표 지점(100번 칸)에 도달하면 즉시 굴린 횟수 반환 (BFS이므로 항상 최단 거리 보장)
        if(current == 100){
            return cost[current];
        }

        // 주사위의 눈금 1~6에 대한 모든 경우의 수 탐색
        for(int dice = 1; dice <= 6; dice++){
            int next = current + dice; // 주사위를 굴려 도착할 임시 위치
            
            // [중요] 배열 범위를 벗어나는 접근 방지
            if (next > 100) continue; 
            
            // 뱀이나 사다리가 있다면 해당 위치로, 없다면 자기 자신(next)으로 최종 위치 결정
            int final_val = move[next]; 
            
            // 최종 도달할 위치를 이전에 방문한 적이 없다면 큐에 삽입
            if(!is_visited[final_val]){
                order.push(final_val);
                is_visited[final_val] = true;
                // 이전 위치까지의 굴린 횟수 + 1턴 소모
                cost[final_val] = cost[current] + 1; 
            }
        }
    }
    return -1; // 100번 칸에 도달할 수 없는 경우 (문제 조건상 발생하지 않음)
}

int main(){
    // C++ 표준 입출력 속도 향상을 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; // N: 사다리의 수, M: 뱀의 수
    cin >> N >> M;

    // move[i] : i번 칸에 도착했을 때 최종적으로 이동하게 될 칸의 번호
    int move[101];

    // 초기 상태: 모든 칸은 자기 자신으로 이동하도록 설정 (뱀/사다리가 없는 일반 칸)
    for(int i = 1; i <= 100; i++){
        move[i] = i;
    }

    // 뱀과 사다리 정보 입력 (자동 이동 목적지 업데이트)
    for(int i = 0; i < N + M; i++){
        int start, goal;
        cin >> start >> goal;
        move[start] = goal; // start 칸에 도착하면 무조건 goal 칸으로 순간이동
    }
    
    int min_cnt = BFS(move);

    cout << min_cnt << "\n";

    return 0;
}
