#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

void Dijkstra(const int start, const int N, const int M, const vector<vector<pair<int,int>>> &graphs, vector<int> &min_cost){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    min_cost[start] = 0;
    pq.push({0,start});
    
    while(!pq.empty()){
        int current = pq.top().second;
        int current_cost = pq.top().first;
        pq.pop();

        if(min_cost[current] < current_cost) continue;

        for(const pair<int,int> &edge : graphs[current]){
            int next = edge.second;
            int next_cost = current_cost + edge.first;

            if(next_cost < min_cost[next]){
                min_cost[next] = next_cost;
                pq.push({next_cost, next});
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,int>>> graphs(N);

    for(int i=0;i<M;i++){
        int v, u, c;
        cin >> v >> u >> c;

        graphs[v-1].push_back({c,u-1});
    }
    for(int start=0;start<N;start++){
        vector<int> min_cost(N, INT_MAX);

        Dijkstra(start, N, M, graphs, min_cost);

        for(int end=0;end<N;end++){
            if(min_cost[end] != INT_MAX) cout << min_cost[end] << " ";
            else                         cout << 0 << " ";
        }
        cout << "\n";
    }
    return 0;
}