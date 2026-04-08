#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

void Dijkstra(const int start, const int N, const int M, const vector<vector<pair<int,int>>> &graphs, vector<int> &min_cost){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    // [수정됨 3] 시작 노드의 최소 비용을 0으로 초기화합니다.
    min_cost[start] = 0; 
    pq.push({0, start});
    
    while(!pq.empty()){
        int current_cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        // 현재 꺼낸 비용이 기록된 최소 비용보다 크면 무시 (가지치기)
        if(min_cost[current] < current_cost) continue;

        for(const pair<int,int> &edge : graphs[current]){
            int next_cost = current_cost + edge.first; // edge.first는 비용
            int next = edge.second;                    // edge.second는 다음 노드

            // [수정됨 1] current가 아니라 'next' 노드의 최소 비용과 비교하고 갱신합니다.
            if(next_cost < min_cost[next]){
                min_cost[next] = next_cost;
                pq.push({next_cost, next});
            }
        }
    }
}

int main(){
    // 입출력 속도 향상을 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    // [수정됨 2] N과 M을 올바르게 입력받습니다.
    cin >> N >> M;

    vector<vector<pair<int,int>>> graphs(N);

    for(int i = 0; i < M; i++){
        int v, u, c;
        cin >> v >> u >> c;

        // 양방향인지 단방향인지에 따라 다르지만, 작성하신 대로 단방향으로 설정합니다.
        graphs[v-1].push_back({c, u-1});
    }

    for(int start = 0; start < N; start++){
        // 매 시작점마다 min_cost 배열을 무한대(INT_MAX)로 초기화합니다.
        vector<int> min_cost(N, INT_MAX);

        Dijkstra(start, N, M, graphs, min_cost);

        for(int end = 0; end < N; end++){
            // 도달할 수 없는 경우 0을 출력하도록 하셨네요! (문제 요구사항에 맞춤)
            if(min_cost[end] != INT_MAX) cout << min_cost[end] << " ";
            else                         cout << 0 << " ";
        }
        cout << "\n";
    }
    return 0;
}
