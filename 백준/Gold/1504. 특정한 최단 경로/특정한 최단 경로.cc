#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// [포인트 1] 안전한 무한대 값 설정
// 2e9를 쓰면 경로 3개를 더할 때 int 최댓값(약 21억)을 넘어 오버플로우가 발생할 수 있어.
// 그래서 3개를 더해도 안전한 2억(2e8)을 무한대 값으로 설정했어!
const int INF = 2e8;

// 다익스트라 알고리즘: 시작 노드에서 모든 노드까지의 최단 거리를 구하는 함수
void Dijkstra(int start, vector<int> &cost, vector<vector<pair<int,int>>> &graph){
    // [포인트 2] 최소 힙(Min-Heap) 우선순위 큐
    // 큐에 {누적 거리, 노드 번호} 형태로 저장해. 
    // greater를 써서 '거리가 가장 짧은 노드'가 항상 큐의 맨 위에 오도록 만들어 줘.
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    // 시작점 초기화 (자기 자신까지의 거리는 0)
    cost[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int current_total = pq.top().first;  // 현재 노드까지의 누적 거리
        int current_node = pq.top().second;  // 현재 노드 번호
        pq.pop();
        
        // [포인트 3] 시간 단축을 위한 스킵 (최적화)
        // 꺼낸 거리가 이미 기록된 최단 거리보다 길다면, 볼 필요도 없이 무시해!
        if(cost[current_node] < current_total) continue;

        // 현재 노드와 연결된 이웃 노드들을 하나씩 탐색
        for(auto edge : graph[current_node]){
            int next_total = current_total + edge.first; // 시작점 -> 현재 노드 -> 이웃 노드로 가는 총 거리
            int next_node = edge.second;                 // 이웃 노드 번호

            // [포인트 4] 최단 거리 갱신
            // 방금 계산한 '거쳐 가는 거리'가 기존에 알려진 '이웃 노드까지의 거리'보다 짧다면 업데이트!
            if(next_total < cost[next_node]){
                cost[next_node] = next_total;
                pq.push({next_total, next_node}); // 더 짧은 경로를 찾았으니 큐에 넣어 다음 탐색에 활용
            }
        }
    }
}

int main(){
    // 입출력 속도를 높여주는 마법의 주문 (C++ 특)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E; // N: 노드 개수, E: 간선 개수
    cin >> N >> E;

    // 그래프 초기화 (1번부터 N번까지 사용하므로 N+1 크기로 할당)
    vector<vector<pair<int,int>>> graph(N+1);

    for(int i=0;i<E;i++){
        int u, v, cost;
        cin >> u >> v >> cost;

        // [포인트 5] 양방향(무방향) 그래프
        // 길은 양방향으로 통행 가능하므로 양쪽 모두 연결 정보를 넣어줘.
        // pair에는 다익스트라 큐 구조에 맞춰 {비용, 도착점} 순서로 저장해.
        graph[u].push_back({cost, v});
        graph[v].push_back({cost, u});
    }
    
    // 반드시 거쳐야 하는 두 개의 필수 정점 u, v
    int u, v;
    cin >> u >> v;

    // 각 시작점(1번, u번, v번)으로부터의 최단 거리를 저장할 배열을 INF로 초기화
    vector<int> one_to(N+1, INF);
    vector<int> u_to(N+1, INF);
    vector<int> v_to(N+1, INF);

    // [포인트 6] 다익스트라 3번 호출
    // 각각 1번, u번, v번 노드에서 출발하는 모든 최단 경로 지도를 완성해.
    Dijkstra(1, one_to, graph);
    Dijkstra(u, u_to, graph);
    Dijkstra(v, v_to, graph);

    // [포인트 7] 두 가지 가능한 경로 비교
    // 루트 1: 출발(1) -> u -> v -> 도착(N)
    int tmp_one = one_to[u] + u_to[v] + v_to[N];
    // 루트 2: 출발(1) -> v -> u -> 도착(N)
    int tmp_two = one_to[v] + v_to[u] + u_to[N];
    
    // 두 경로 중 더 짧은 쪽을 선택
    int ans = min(tmp_one, tmp_two);

    // [포인트 8] 예외 처리: 길이 끊겨있는 경우
    // 중간에 하나라도 갈 수 없는 길이 있었다면 INF 값이 더해져서 ans가 INF 이상이 돼.
    // 이 경우 문제 조건에 따라 -1을 출력해.
    if(ans >= INF) cout << -1 << "\n";
    else cout << ans << "\n";
    
    return 0;
}
