#include <iostream>
#include <vector>

using namespace std;

void DFS(int current, vector<vector<int>> &graph, vector<bool> &is_visited){
    is_visited[current] = true;

    for(int i=0;i<graph[current].size();i++){
        if(!is_visited[graph[current][i]]){
            DFS(graph[current][i], graph, is_visited);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N+1);
    vector<vector<int>> party(M);
    vector<bool> is_visited(N+1,false);

    int n;
    cin >> n;

    vector<int> start(n);

    for(int i=0;i<n;i++){
        cin >> start[i];
    }
    for(int i=0;i<M;i++){
        int m;
        cin >> m;

        for(int j=0;j<m;j++){
            int node;
            cin >> node;
            party[i].push_back(node);
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<party[i].size();j++){
            for(int k=0;k<party[i].size();k++){
                if(j!=k) graph[party[i][j]].push_back(party[i][k]);
            }
        }
    }
    for(int i=0;i<n;i++){
        DFS(start[i], graph, is_visited);
    }
    int ans = 0;

    for(int i=0;i<M;i++){
        bool possible = true;
        
        for(int j=0;j<party[i].size();j++){
            if(is_visited[party[i][j]]){
                possible = false;
                break;
            }
        }
        if(possible){
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}