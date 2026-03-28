#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 2e8;

void Dijkstra(int start, vector<int> &cost, vector<vector<pair<int,int>>> &graph){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    cost[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int current_total = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        
        if(cost[current_node] < current_total) continue;

        for(auto edge : graph[current_node]){
            int next_total = current_total + edge.first;
            int next_node = edge.second;

            if(next_total < cost[next_node]){
                cost[next_node] = next_total;
                pq.push({next_total,next_node});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E;
    cin >> N >> E;

    vector<vector<pair<int,int>>> graph(N+1);

    for(int i=0;i<E;i++){
        int u, v, cost;
        cin >> u >> v >> cost;

        graph[u].push_back({cost,v});
        graph[v].push_back({cost,u});
    }
    int u, v;
    cin >> u >> v;

    vector<int> one_to(N+1,INF);
    vector<int> u_to(N+1,INF);
    vector<int> v_to(N+1,INF);

    Dijkstra(1, one_to, graph);
    Dijkstra(u, u_to, graph);
    Dijkstra(v, v_to, graph);

    int tmp_one = one_to[u] + u_to[v] + v_to[N];
    int tmp_two = one_to[v] + v_to[u] + u_to[N];
    int ans = min(tmp_one,tmp_two);

    if(ans >= INF) cout << -1 << "\n";
    else cout << ans << "\n";
    
    return 0;
} 