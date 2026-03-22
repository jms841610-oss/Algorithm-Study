#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS 알고리즘 함수
void bfs(int startNode, const vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;

    // 1. 시작 노드를 큐에 넣고 방문 처리
    q.push(startNode);
    visited[startNode] = true;

    // 2. 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 큐에서 가장 앞에 있는 노드를 꺼냄
        int currentNode = q.front();
        q.pop();
        
        cout << currentNode << " ";

        // 해당 노드와 연결된 모든 인접 노드를 확인
        for (int nextNode : graph[currentNode]) {
            // 아직 방문하지 않은 노드라면
            if (!visited[nextNode]) {
                q.push(nextNode);         // 큐에 삽입
                visited[nextNode] = true; // 방문 처리
            }
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

    // 그래프 간선 연결 (예시 데이터)
    graph[1] = {2, 3, 8};
    graph[2] = {1, 7};
    graph[3] = {1, 4, 5};
    graph[4] = {3, 5};
    graph[5] = {3, 4};
    graph[6] = {7};
    graph[7] = {2, 6, 8};
    graph[8] = {1, 7};

    cout << "BFS 탐색 순서: ";
    // 1번 노드부터 BFS 탐색 시작
    bfs(1, graph, visited);
    cout << endl;

    return 0;
}
