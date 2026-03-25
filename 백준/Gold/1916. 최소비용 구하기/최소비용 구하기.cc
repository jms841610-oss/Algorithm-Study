#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int N, M;

// 그래프: 인접 리스트 방식 (비용, 도착 노드)
vector<vector<pair<int,int>>> graph(1001);
// 최소 비용 배열
vector<int> min_cost(1001, INF);
// 우선순위 큐: 오름차순 정렬 (비용, 노드 번호)
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void dijkstra(int depart, int arrive){
    min_cost[depart] = 0;
    pq.push({0, depart});

    while(!pq.empty()){
        int total_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // 🌟 최적화 포인트: 조기 종료 (Early Exit)
        // 현재 큐에서 꺼낸 노드가 목적지라면, 목적지까지의 최소 비용이 확정된 것이므로 탐색을 즉시 종료합니다.
        if(current_node == arrive) {
            return; 
        }

        // 이미 처리된 적이 있는 노드라면 무시 (최적화)
        if(min_cost[current_node] < total_cost) continue;

        // 인접한 노드들 탐색
        for(const auto& next : graph[current_node]){
            int next_cost = next.first;
            int next_node = next.second;

            int next_total = next_cost + total_cost;

            // 더 적은 비용으로 갈 수 있는 경로를 발견한 경우
            if(min_cost[next_node] > next_total){
                min_cost[next_node] = next_total;
                pq.push({next_total, next_node});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int depart, arrive, cost;
        cin >> depart >> arrive >> cost;
        graph[depart].push_back({cost, arrive});
    }
    
    int depart, arrive;
    cin >> depart >> arrive;

    // 출발지와 목적지를 파라미터로 전달
    dijkstra(depart, arrive);
    
    // 결과 출력
    cout << min_cost[arrive] << "\n";
    
    return 0;
}
