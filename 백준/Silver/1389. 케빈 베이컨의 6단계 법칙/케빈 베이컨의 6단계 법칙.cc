#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

// 인접 리스트 배열: 최대 노드 개수가 100개이므로 크기를 101로 고정 할당
vector<vector<int>> graphs(101);

/**
 * 특정 노드(시작점)의 케빈 베이컨의 수를 계산하는 함수
 * @param node 시작 노드 번호
 * @return 시작 노드에서 다른 모든 노드까지의 최단 거리 총합
 */
int get_kaebin(int node){   
    vector<bool> is_visited(N+1, false);
    vector<int> cost(N+1, 0); // 시작점으로부터 각 노드까지의 거리를 저장하는 배열
    queue<int> q;
    
    // 1. 큐 초기화 및 시작 노드 방문 처리
    q.push(node);
    is_visited[node] = true;
    cost[node] = 0;

    // 2. BFS 탐색 진행 (가중치가 없는 그래프의 최단 경로는 BFS로 탐색)
    while(!q.empty()){
        int front = q.front();
        q.pop();

        // 현재 노드와 연결된 모든 인접 노드를 확인
        for(int i = 0; i < graphs[front].size(); i++){
            int next_node = graphs[front][i];
            
            // 아직 방문하지 않은 노드라면
            if(!is_visited[next_node]){
                q.push(next_node);
                is_visited[next_node] = true;
                
                // 다음 노드까지의 거리 = 현재 노드까지의 거리 + 1
                cost[next_node] = cost[front] + 1;
            }
        }
    }
    
    // 3. 탐색 완료 후 케빈 베이컨의 수(모든 최단 거리의 합) 계산
    int total = 0;
    for(int i = 0; i < N + 1; i++){
        total += cost[i];
    }
    return total;
}

int main(){
    // 입출력 속도 향상을 위한 설정 (C와 C++의 버퍼를 분리)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    // 양방향 그래프 연결 설정 (친구 관계는 양방향)
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;

        graphs[u].push_back(v);
        graphs[v].push_back(u);
    }
    
    int min_kaebin = N * N; // 최솟값 갱신을 위해 충분히 큰 값으로 초기화
    int min_node = 0;

    // [핵심 로직] 케빈 베이컨의 수가 가장 작은 사람을 찾되, 
    // 값이 같을 경우 번호가 가장 작은 사람을 출력해야 함.
    // N부터 1까지 역순으로 탐색하고 '>=' 연산자를 사용함으로써,
    // 나중에 탐색되는 더 작은 번호의 노드가 정답으로 덮어씌워지게 구현됨.
    for(int node = N; node > 0; node--){
        int kaebin = get_kaebin(node);
        
        if(min_kaebin >= kaebin){
            min_kaebin = kaebin;
            min_node   = node;
        }
    }
    
    // 최종적으로 조건을 만족하는 노드 번호 출력
    cout << min_node << "\n";

    return 0;
}
