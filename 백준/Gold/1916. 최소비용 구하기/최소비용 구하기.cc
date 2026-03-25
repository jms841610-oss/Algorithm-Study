#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int N, M;

vector<vector<pair<int,int>>> graph(1001);

vector<int> min_cost(1001,INF);
    
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void dijkstra(int depart, int arrive){
    min_cost[depart] = 0;
    pq.push({0,depart});

    while(!pq.empty()){
        int total_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if(min_cost[current_node] < total_cost) continue;

        for(const auto& next : graph[current_node]){
            int next_cost = next.first;
            int next_node = next.second;

            int next_total = next_cost + total_cost;

            if(min_cost[next_node] > next_total){
                min_cost[next_node] = next_total;
                pq.push({next_total,next_node});
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=0;i<M;i++){
        int depart, arrive, cost;
        cin >> depart >> arrive >> cost;
        graph[depart].push_back({cost,arrive});
    }
    int depart, arrive;
    cin >> depart >> arrive;

    dijkstra(depart, arrive);
    
    cout << min_cost[arrive] << "\n";
    return 0;
}