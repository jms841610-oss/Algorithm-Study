#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int current, int current_total, int &max_total, int &end, vector<vector<pair<int,int>>> &graphs, vector<bool> &is_visited) {
    // 1. 방문하는 모든 노드에서 최대 거리와 가장 먼 노드를 갱신합니다.
    // (조건문 없이 무조건 확인하므로, 중간에 탐색이 끊기지 않습니다.)
    if(current_total > max_total) {
        end = current;
        max_total = current_total;
    }

    // 2. 연결된 인접 노드들을 탐색합니다.
    for(int i = 0; i < graphs[current].size(); i++) {
        int next_node = graphs[current][i].first;
        int next_dist = graphs[current][i].second;

        if(!is_visited[next_node]) {
            // 백트래킹 방식을 유지하셨네요! 좋은 접근입니다.
            is_visited[next_node] = true;
            current_total += next_dist;

            DFS(next_node, current_total, max_total, end, graphs, is_visited);

            // 상태 복구
            is_visited[next_node] = false;
            current_total -= next_dist;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<pair<int,int>>> graphs(N + 1);
    vector<bool> is_visited(N + 1, false);

    for(int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graphs[u].push_back({v, w});
        graphs[v].push_back({u, w});
    }

    int end = 1; // 아무 노드나 상관없지만 안전하게 1로 초기화
    int max_total = 0;

    // [Step 1] 1번 노드에서 가장 먼 노드(end) 찾기
    is_visited[1] = true;
    DFS(1, 0, max_total, end, graphs, is_visited);
    is_visited[1] = false; // 방문 상태 복구

    // [Step 2] 찾은 end 노드에서 가장 먼 노드 찾기 (트리의 지름)
    // 두 번째 탐색을 위해 max_total을 반드시 0으로 초기화해 줍니다.
    max_total = 0; 
    
    is_visited[end] = true;
    DFS(end, 0, max_total, end, graphs, is_visited);

    cout << max_total << "\n";
    
    return 0;
}
