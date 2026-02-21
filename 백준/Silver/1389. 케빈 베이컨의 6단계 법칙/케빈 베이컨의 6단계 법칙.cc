#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;

vector<vector<int>> graphs(101);

int get_kaebin(int node){   
    vector<bool> is_visited(N+1,false);
    vector<int> cost(N+1,0);
    queue<int> q;
    
    q.push(node);
    is_visited[node] = true;
    cost[node] = 0;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(int i=0;i<graphs[front].size();i++){
            if(!is_visited[graphs[front][i]]){
                q.push(graphs[front][i]);
                is_visited[graphs[front][i]] = true;
                cost[graphs[front][i]] = cost[front] + 1;
            }
        }
    }
    int total = 0;

    for(int i=0;i<N+1;i++){
        total += cost[i];
    }
    return total;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=0;i<M;i++){
        int u,v;
        cin >> u >> v;

        graphs[u].push_back(v);
        graphs[v].push_back(u);
    }
    int min_kaebin = N*N;
    int min_node = 0;

    for(int node=N;node>0;node--){
        int kaebin = get_kaebin(node);
        
        if(min_kaebin>=kaebin){
            min_kaebin = kaebin;
            min_node   = node;
        }
    }
    cout << min_node << "\n";

    return 0;
}