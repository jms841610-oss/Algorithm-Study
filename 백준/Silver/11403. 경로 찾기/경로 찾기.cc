#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 특정 정점(node)에서 출발하여 도달할 수 있는 모든 정점을 탐색하는 BFS 함수
void BFS(vector<vector<int>> &edge, int N, int node){
    // is_visited: 탐색 중 무한 루프(사이클)를 방지하기 위한 방문 체크 배열
    vector<bool> is_visited(N+1, false);
    // can_go: 시작 노드에서 해당 노드로 도달 가능한지 여부를 기록 (출력용)
    vector<bool> can_go(N+1, false);
    queue<int> q;

    q.push(node);
    // [핵심 포인트] 
    // 여기서 is_visited[node] = true를 하지 않음!
    // 자기 자신으로 돌아오는 간선(사이클)이 존재할 때만 1을 출력해야 하므로,
    // 처음 출발할 때는 방문 처리를 생략하여 다시 돌아올 수 있는 길을 열어둔다.

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(int i = 0; i < edge[front].size(); i++){
            int next_node = edge[front][i];
            
            if(!is_visited[next_node]){
                can_go[next_node] = true; // 도달 가능함을 기록
                is_visited[next_node] = true; // 재방문 방지
                q.push(next_node);
            }
        }
    }
    
    // BFS 탐색이 끝난 후, 해당 시작점(node)에 대한 한 줄(행)의 결과를 바로 출력
    for(int n = 1; n <= N; n++){
        if(can_go[n]){
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
    cout << "\n";

    return;
}

int main(){
    // 입출력 속도 향상 (C와 C++ 버퍼 분리)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 그래프를 인접 행렬로 입력받지만, 탐색 효율을 위해 인접 리스트로 변환하여 저장
    // 1번 인덱스부터 사용하기 위해 N+1 크기 할당
    vector<vector<int>> edge(N+1);

    for(int u = 1; u <= N; u++){
        for(int v = 1; v <= N; v++){
            int is_able;
            cin >> is_able;
            if(is_able){
                edge[u].push_back(v); // u에서 v로 가는 단방향 간선 추가
            }
        }
    }
    
    // 각 정점을 시작점으로 하여 경로 탐색 수행
    for(int node = 1; node <= N; node++){
        BFS(edge, N, node);
    }
    
    return 0;
}
