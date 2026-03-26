#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int Dijkstra(int N, int K){
    vector<int> cost(100001, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    cost[N] = 0;
    pq.push({0,N});

    while(!pq.empty()){
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        
        if(current_node == K){
            return current_cost;
        }
        if(cost[current_node] < current_cost){
            continue;
        }
        int next[3];
        next[0] = current_node + 1;
        next[1] = current_node -1;
        next[2] = current_node * 2;

        for(int i=0;i<3;i++){
            if((0 <= next[i])&&(next[i] <= 100000)){
            
                int next_cost;
                if(i!=2) next_cost = current_cost + 1;
                else     next_cost = current_cost;

                if(next_cost < cost[next[i]]){
                    cost[next[i]] = next_cost;
                    pq.push({next_cost,next[i]});
                }
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin >> N >> K;
    
    int ans = Dijkstra(N, K);
    
    cout << ans << "\n";
    return 0;
}