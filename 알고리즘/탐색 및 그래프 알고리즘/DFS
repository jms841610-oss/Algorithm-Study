#include <iostream>
#include <vector>

using namespace std;

// DFS 알고리즘 함수 (재귀 방식)
void dfs(int currentNode, const vector<vector<int>>& graph, vector<bool>& visited) {
    // 1. 현재 노드를 방문 처리하고 출력
    visited[currentNode] = true;
    cout << currentNode << " ";

    // 2. 현재 노드와 연결된 모든 인접 노드를 순차적으로 확인
    for (int nextNode : graph[currentNode]) {
        // 아직 방문하지 않은 인접 노드가 있다면
        if (!visited[nextNode]) {
            // 해당 노드를 시작으로 다시 DFS 재귀 호출 (더 깊이 파고듦)
            dfs(nextNode, graph, visited);
        }
    }
}

int main() {
    // 총 노드의 개수 (예: 8개)
    int n = 8;

    // 그래프 초기화 (인덱스 번호와 노드 번호를 일치시키기 위해 n + 1 크기로 할당)
    vector<vector<int>> graph(n + 1);
    
    // 방문 여부를 저장할 배열 초기화 (모두 false로 시작)
    vector<bool> visited(n + 1, false);

    // 그래프 간선 연결 (BFS 때와 동일한 예시 데이터를 사용하여 결과 비교 용이)
    graph[1] = {2, 3, 8};
    graph[2] = {1, 7};
    graph[3] = {1, 4, 5};
    graph[4] = {3, 5};
    graph[5] = {3, 4};
    graph[6] = {7};
    graph[7] = {2, 6, 8};
    graph[8] = {1, 7};

    cout << "DFS 탐색 순서: ";
    // 1번 노드부터 DFS 탐색 시작
    dfs(1, graph, visited);
    cout << endl;

    return 0;
}
