#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int current, int current_total, int &max_total, int &end, vector<vector<pair<int,int>>> &graphs, vector<bool> &is_visited){
    is_visited[current] = true;

    if(current_total > max_total){
        max_total = current_total;
        end = current;
    }

    for(int i=0;i<graphs[current].size();i++){

        int next_node = graphs[current][i].first;
        int next_dist = graphs[current][i].second;

        if(!is_visited[next_node]){

            is_visited[next_node] = true;
            current_total += next_dist;

            DFS(next_node, current_total, max_total, end, graphs, is_visited);

            is_visited[next_node] = false;
            current_total -= next_dist;
        }
    }
    is_visited[current] = false;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<pair<int,int>>> graphs(N+1);
    vector<bool> is_visited(N+1,false);

    for(int i=0;i<N-1;i++){
        int u, v, w;
        cin >> u >> v >> w;

        graphs[u].push_back({v,w});
        graphs[v].push_back({u,w});
    }
    int end = 0;
    int max_total = 0;

    DFS(  1, 0, max_total, end, graphs, is_visited);
    DFS(end, 0, max_total, end, graphs, is_visited);

    cout << max_total << "\n";
    return 0;
}