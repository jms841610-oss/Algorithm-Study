#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> &edge,int N,int node){
    vector<bool> is_visited(N+1,false);
    vector<bool> can_go(N+1,false);
    queue<int> q;

    q.push(node);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(int i=0;i<edge[front].size();i++){
            if(!is_visited[edge[front][i]]){
                can_go[edge[front][i]] = true;
                q.push(edge[front][i]);
                is_visited[edge[front][i]] = true;
            }
        }
    }
    for(int n=1;n<=N;n++){
        if(can_go[n]){
            cout << 1 << " ";
        }else{
            cout << 0 << " ";
        }
    }
    cout << "\n";

    return;
}
int main(){
    int N;
    cin >> N;

    vector<vector<int>> edge(N+1);

    for(int u=1;u<=N;u++){
        for(int v=1;v<=N;v++){
            int is_able;
            cin >> is_able;
            if(is_able){
                edge[u].push_back(v);
            }
        }
    }
    for(int node=1;node<=N;node++){
        BFS(edge,N,node);
    }
    return 0;
}