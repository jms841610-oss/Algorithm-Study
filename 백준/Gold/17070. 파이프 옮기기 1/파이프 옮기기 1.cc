#include <iostream>
#include <vector>

using namespace std;

int N; // 격자의 크기 (N x N)
int ans = 0; // 목표 지점에 도달하는 방법의 수

// 격자의 상태를 저장하는 2차원 배열 (0: 빈 칸, 1: 벽)
vector<vector<int>> area(16,vector<int>(16,0));
// 방문 여부를 체크하는 배열 (파이프의 머리 기준)
vector<vector<bool>> is_visited(16,vector<bool>(16,false));

// DFS 탐색 함수: 파이프의 꼬리(tail)와 머리(head)의 좌표를 받아서 이동합니다.
void DFS(pair<int,int> tail, pair<int,int> head){
    // 현재 꼬리와 머리의 y(행), x(열) 좌표 분리
    int tail_y = tail.first;
    int tail_x = tail.second;

    int head_y = head.first;
    int head_x = head.second;

    // 1. 종료 조건 (Base Case)
    // 파이프의 꼬리나 머리 중 하나라도 목적지(N-1, N-1)에 도달하면 정답 카운트 증가 후 종료
    if(((tail_y == N-1)&&(tail_x == N-1))||((head_y == N-1)&&(head_x == N-1))){
        ans++;
        return;
    }

    // 2. 가로(오른쪽) 이동 확인
    pair<int,int> front_head = {-1, -1};
    pair<int,int> front_tail = {-1, -1};

    // tail_x != head_x 인 경우는 파이프가 '가로' 또는 '대각선' 상태일 때를 의미합니다.
    if(tail_x != head_x){
        // 머리가 오른쪽으로 이동해도 격자(N)를 벗어나지 않는지 확인
        if((head_y < N)&&(head_x+1 < N)){
            // 이동할 칸이 벽(1)이 아니고, 방문하지 않은 곳인지 확인
            if(area[head_y][head_x+1] != 1){
                if(!is_visited[head_y][head_x+1]){
                    
                    is_visited[head_y][head_x+1] = true; // 방문 처리

                    // 꼬리는 이전 머리 위치로, 머리는 오른쪽으로 한 칸 이동
                    front_head = {head_y, head_x + 1};
                    front_tail = {head_y, head_x};

                    DFS(front_tail, front_head); // 다음 단계 탐색

                    is_visited[head_y][head_x+1] = false; // 백트래킹: 탐색 종료 후 방문 기록 원상 복구
                }
            }
        }
    }

    // 3. 세로(아래쪽) 이동 확인
    pair<int,int> down_head = {-1, -1};
    pair<int,int> down_tail = {-1, -1};

    // tail_y != head_y 인 경우는 파이프가 '세로' 또는 '대각선' 상태일 때를 의미합니다.
    if(tail_y != head_y){
        // 머리가 아래쪽으로 이동해도 격자(N)를 벗어나지 않는지 확인
        if((head_y+1 < N)&&(head_x < N)){
            // 이동할 칸이 벽(1)이 아니고, 방문하지 않은 곳인지 확인
            if(area[head_y+1][head_x] != 1){
                if(!is_visited[head_y+1][head_x]){

                    is_visited[head_y+1][head_x] = true; // 방문 처리

                    // 꼬리는 이전 머리 위치로, 머리는 아래쪽으로 한 칸 이동
                    down_head = {head_y+1, head_x};
                    down_tail = {head_y, head_x};

                    DFS(down_tail, down_head);

                    is_visited[head_y+1][head_x] = false; // 백트래킹
                }
            }
        }
    }

    // 4. 대각선(오른쪽 아래) 이동 확인
    pair<int,int> diag_head = {-1, -1};
    pair<int,int> diag_tail = {-1, -1};

    // 대각선 이동은 파이프의 현재 상태(가로, 세로, 대각선)와 무관하게 항상 시도할 수 있습니다.
    // 머리가 대각선으로 이동했을 때 격자 범위를 벗어나지 않는지 확인
    if((head_y+1 < N)&&(head_x+1 < N)){
        // 대각선 이동 시에는 목적지뿐만 아니라 오른쪽, 아래쪽 칸도 모두 벽이 아니어야 합니다! (중요 포인트)
        if((area[head_y+1][head_x] != 1)&&(area[head_y][head_x+1] != 1)&&(area[head_y+1][head_x+1] != 1)){
            if(!is_visited[head_y+1][head_x+1]){

                is_visited[head_y+1][head_x+1] = true; // 방문 처리

                // 꼬리는 이전 머리 위치로, 머리는 대각선(y+1, x+1)으로 이동
                diag_head = {head_y+1, head_x+1};
                diag_tail = {head_y, head_x};

                DFS(diag_tail, diag_head);

                is_visited[head_y+1][head_x+1] = false; // 백트래킹
            }
        }
    }
}

int main(){
    // C++ 입출력 속도 향상을 위한 설정 (시간 초과 방지)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    // 격자 정보 입력 받기
    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            cin >> area[y][x];
        }
    }
    
    // 파이프의 초기 위치 설정: 꼬리는 (0,0), 머리는 (0,1)
    pair<int,int> tail = {0,0};
    pair<int,int> head = {0,1};

    // (0,1) 위치 방문 처리 후 탐색 시작하는 것이 안전할 수 있지만, 
    // 현재 코드 구조상 탐색 내부에서 다음 위치를 방문 처리하므로 그대로 진행
    DFS(tail, head);

    // 가능한 모든 경로의 수 출력
    cout << ans << "\n";
    return 0;
}
