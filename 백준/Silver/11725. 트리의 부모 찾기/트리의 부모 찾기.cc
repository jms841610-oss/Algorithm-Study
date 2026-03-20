#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;

set<int> node;

vector<vector<int>> edge(100001);

vector<int> parent(100001,1);
vector<bool> is_visited(100001,false);

void find(int current){
    for(int i=0;i<edge[current].size();i++){
        if(!is_visited[edge[current][i]]){
            parent[edge[current][i]] = current;
            is_visited[edge[current][i]] = true;
            find(edge[current][i]);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i=0;i<N;i++){
        int u,v;
        cin >> u >> v;

        if(u!=1) node.insert(u);
        if(v!=1) node.insert(v);

        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    is_visited[1] = true;
    find(1);

    for(const int ele : node){
        cout << parent[ele] << "\n";
    }
    return 0;
}