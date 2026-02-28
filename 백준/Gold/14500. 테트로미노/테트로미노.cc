#include <iostream>
#include <vector>
// TIP: <iostream>이나 <vector>가 환경에 따라 max()를 포함하기도 하지만,
// 엄격한 컴파일러 환경에서는 에러가 날 수 있으므로 <algorithm>을 명시해 주는 것이 안전합니다.
// #include <algorithm> 

using namespace std;

int max_sum = 0;
int height, width;

// 4방향 탐색을 위한 방향 벡터 (상, 우, 하, 좌)
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

// 전역 변수 선언: 재귀 호출 시마다 배열이 복사되는 오버헤드를 막고 메모리를 최적화
vector<vector<int>> score(500, vector<int>(500));
vector<vector<bool>> is_visited(500, vector<bool>(500, false));

// DFS를 활용한 백트래킹 탐색
void DFS(int row, int col, int depth, int current_sum){
    // Base Case: 테트로미노는 4개의 칸으로 이루어지므로, 깊이가 4가 되면 탐색 종료
    if(depth == 4){
        max_sum = max(max_sum, current_sum);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int next_row = row + dy[i];
        int next_col = col + dx[i];

        // 경계 조건: 맵의 범위를 벗어나지 않는지 확인
        if((0 <= next_row) && (next_row < height) && (0 <= next_col) && (next_col < width)){
            
            // 아직 방문하지 않은 칸일 경우만 진행
            if(!is_visited[next_row][next_col]){

                // [핵심 로직] 'ㅜ', 'ㅗ', 'ㅏ', 'ㅓ' 모양 예외 처리
                // 현재까지 2칸을 선택했을 때(depth==2), 다음 칸을 방문 처리하여 점수만 더하고
                // 탐색의 기준점은 다음 칸(next_row, next_col)이 아닌 현재 칸(row, col)으로 유지!
                // 이렇게 하면 현재 칸을 중심으로 나머지 한 칸을 마저 찾게 되어 'ㅜ' 모양이 완성됨.
                if(depth == 2){
                    is_visited[next_row][next_col] = true;
                    DFS(row, col, depth + 1, current_sum + score[next_row][next_col]);
                    is_visited[next_row][next_col] = false; // 탐색 후 방문 기록 해제 (백트래킹)
                }
                
                // 일반적인 테트로미노 탐색 (깊이를 +1 하며 꼬리를 물고 이어감)
                is_visited[next_row][next_col] = true;
                DFS(next_row, next_col, depth + 1, current_sum + score[next_row][next_col]);
                is_visited[next_row][next_col] = false; // 탐색 후 방문 기록 해제 (백트래킹)
            }
        }
    }
    return;
}

int main(){
    // C++ 입출력 속도 최적화 (알고리즘 문제 풀이 필수 설정)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> height >> width;

    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            int input;
            cin >> input;
            score[row][col] = input;
        }
    }
    
    // 맵의 모든 좌표를 시작점으로 하여 완전 탐색 진행
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            // 시작점 방문 처리
            is_visited[row][col] = true;
            
            // [버그 수정 완료] 시작점 자체를 1번째 칸으로 센다.
            int depth = 1;
            int current_sum = score[row][col];

            DFS(row, col, depth, current_sum);
            
            // 다른 경로에서 이 칸을 다시 밟을 수 있도록 원상복구
            is_visited[row][col] = false;
        }
    }    
    
    cout << max_sum << "\n";

    return 0;
}
