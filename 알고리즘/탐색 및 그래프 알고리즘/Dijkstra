#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 도달할 수 없음을 의미하는 무한대 값 설정 (10억)
const int INF = 1e9;

// 다익스트라 알고리즘 함수
void dijkstra(int startNode, int n, const vector<vector<pair<int, int>>>& graph) {
    // 1. 최단 거리를 저장할 배열을 생성하고 무한대(INF)로 초기화
    vector<int> distance(n + 1, INF);
    
    // 2. 우선순위 큐 설정: (현재까지의 거리, 노드 번호) 쌍을 저장
    // C++의 priority_queue는 기본적으로 값이 큰 것을 먼저 꺼내는 Max-Heap입니다.
    // 거리가 짧은 것을 먼저 꺼내는 Min-Heap으로 만들기 위해 greater를 사용합니다.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 시작 노드로 가기 위한 최단 거리는 0으로 설정하여 큐에 삽입
    distance[startNode] = 0;
    pq.push({0, startNode});

    // 3. 큐가 빌 때까지 반복
    while (!pq.empty()) {
        // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        int dist = pq.top().first;   // 현재 노드까지의 거리
        int now = pq.top().second;   // 현재 노드 번호
        pq.pop();

        // 이미 처리된 적이 있는 노드라면 무시 (더 짧은 경로를 이미 찾은 경우)
        if (distance[now] < dist) continue;

        // 현재 노드와 연결된 다른 인접 노드들을 확인
        for (auto edge : graph[now]) {
            int nextNode = edge.first;     // 연결된 다음 노드
            int edgeCost = edge.second;    // 그 노드로 가는 간선의 비용

            // 현재 노드를 거쳐서 다음 노드로 가는 비용 계산
            int totalCost = dist + edgeCost; 

            // 현재 노드를 거쳐서 가는 것이 기존의 경로보다 더 짧은 경우
            if (totalCost < distance[nextNode]) {
                distance[nextNode] = totalCost;    // 최단 거리 갱신
                pq.push({totalCost, nextNode});    // 큐에 새로운 정보 삽입
            }
        }
    }

    // 4. 모든 노드로 가기 위한 최단 거리 출력
    cout << "\n[" << startNode << "번 노드에서 출발하는 최단 거리]\n";
    for (int i = 1; i <= n; i++) {
        if (distance[i] == INF) {
            cout << i << "번 노드: 도달 불가\n";
        } else {
            cout << i << "번 노드: " << distance[i] << "\n";
        }
    }
}

int main() {
    int n = 6; // 총 노드의 개수

    // 그래프 초기화: graph[노드] = { {연결된 노드, 비용}, ... }
    vector<vector<pair<int, int>>> graph(n + 1);

    // 간선 연결 예시 데이터: graph[출발노드].push_back({도착노드, 비용})
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[1].push_back({4, 1});
    graph[2].push_back({3, 3});
    graph[2].push_back({4, 2});
    graph[3].push_back({2, 3});
    graph[3].push_back({6, 5});
    graph[4].push_back({3, 3});
    graph[4].push_back({5, 1});
    graph[5].push_back({3, 1});
    graph[5].push_back({6, 2});

    // 1번 노드에서 다익스트라 알고리즘 실행
    dijkstra(1, n, graph);

    return 0;
}
