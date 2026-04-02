#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int current, int total, int &ans, vector<vector<pair<int,int>>> &graphs, vector<bool> &is_leaf, vector<bool> &is_visited){
    if(is_leaf[current]){
        ans = max(ans, total);
        return;
    }
    for(int i=0;i<graphs[current].size();i++){
        int next_node = graphs[current][i].first;
        int next_dist = graphs[current][i].second;

        if(!is_visited[next_node]){

            is_visited[next_node] = true;
            total += next_dist;

            DFS(next_node, total, ans, graphs, is_leaf, is_visited);

            is_visited[next_node] = false;
            total -= next_dist;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<pair<int,int>>> graphs(N+1);
    vector<bool> is_leaf(N+1,false);

    for(int i=0;i<N-1;i++){
        int u, v, w;
        cin >> u >> v >> w;

        graphs[u].push_back({v,w});
        graphs[v].push_back({u,w});
    }
    for(int node=1;node<=N;node++){
        if(graphs[node].size()==1){
            is_leaf[node] = true;
        }
    }
    int ans = 0;

    for(int node=1;node<=N;node++){
        if(is_leaf[node]){
            vector<bool> is_visited(N+1,false);
            is_leaf[node] = false;
            is_visited[node] = true;
            DFS(node, 0, ans, graphs, is_leaf, is_visited);
        }
    }
    cout << ans << "\n";
    return 0;
}