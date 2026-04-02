#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2e8;

void Dijkstra(int start, vector<int> &min_dist, vector<vector<pair<int,int>>> &graphs){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    min_dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int current_dist = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if(min_dist[current_vertex] < current_dist) continue;

        for(const pair<int,int> &edge : graphs[current_vertex]){
            int next_dist = current_dist + edge.first;
            int next_vertex = edge.second;

            if(next_dist < min_dist[next_vertex]){
                min_dist[next_vertex] = next_dist;
                pq.push({next_dist,next_vertex});
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    int S;
    cin >> S;
    
    vector<int> min_dist(V+1,INF);
    vector<vector<pair<int,int>>> graphs(V+1);

    for(int i=0;i<E;i++){
        int u, v, w;
        cin >> u >> v >> w;

        graphs[u].push_back({w,v});
    }
    Dijkstra(S, min_dist, graphs);

    for(int i=1;i<=V;i++){
        if(min_dist[i] == INF) cout << "INF\n";
        else                   cout << min_dist[i] << "\n";
    }
    return 0;
}