#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 도달할 수 없는 경로를 의미하는 무한대 값.
// 정점 갯수 * 최대 가중치보다 충분히 큰 값으로 설정하는 것이 좋습니다.
const int INF = 2e8;

// 다익스트라 알고리즘 함수
// start: 탐색을 시작할 정점
// min_dist: 각 정점까지의 최단 거리를 저장할 배열 (참조자로 받아 수정 내용을 원본에 반영)
// graphs: 그래프의 간선 정보를 담고 있는 인접 리스트 (참조자로 받아 메모리 절약)
void Dijkstra(int start, vector<int> &min_dist, vector<vector<pair<int,int>>> &graphs){
    
    // [최소 힙(Min-Heap) 우선순위 큐 생성]
    // 기본형은 최대 힙이므로, greater<>를 사용하여 거리가 가장 짧은(작은) 요소가 먼저 나오도록 설정합니다.
    // pair<거리, 정점번호> 형태로 저장합니다.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    // 시작 정점 자신으로 가는 거리는 0이므로 초기화 후 큐에 삽입합니다.
    min_dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int current_dist = pq.top().first;    // 우선순위 큐에서 꺼낸 현재 정점까지의 거리
        int current_vertex = pq.top().second; // 현재 탐색을 진행할 정점
        pq.pop();

        // [핵심 최적화 부분]
        // 큐에서 꺼낸 거리가 이미 기록된 최단 거리보다 크다면, 
        // 이미 더 짧은 경로를 찾아 처리한 적이 있다는 뜻이므로 무시하고 넘어갑니다.
        if(min_dist[current_vertex] < current_dist) continue;

        // 현재 정점과 연결된 모든 인접 정점(간선)들을 확인합니다.
        for(const pair<int,int> &edge : graphs[current_vertex]){
            // next_dist: 현재 정점을 거쳐서 다음 정점까지 가는 누적 거리
            // edge.first는 간선의 가중치, edge.second는 도착 정점
            int next_dist = current_dist + edge.first; 
            int next_vertex = edge.second;             

            // 새로 계산한 거리가 기존에 알고 있던 도착 정점까지의 거리보다 짧은 경우에만 거리를 갱신합니다.
            if(next_dist < min_dist[next_vertex]){
                min_dist[next_vertex] = next_dist; // 최단 거리 배열 업데이트
                pq.push({next_dist, next_vertex}); // 갱신된 정보를 큐에 삽입하여 다음 탐색에 사용
            }
        }
    }
    return;
}

int main(){
    // C++ 표준 입출력 속도 향상을 위한 설정 (알고리즘 문제 풀이 시 필수적인 팁입니다)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E; // V: 정점의 개수, E: 간선의 개수
    cin >> V >> E;

    int S; // S: 시작 정점의 번호
    cin >> S;
    
    // 최단 거리 배열 초기화
    // 1번 인덱스부터 V번 인덱스까지 사용하기 위해 크기를 V+1로 하고, 모든 값을 INF로 채웁니다.
    vector<int> min_dist(V+1, INF);
    
    // 그래프 인접 리스트 초기화
    // graphs[u] 안에는 {가중치(w), 도착정점(v)} 형태의 pair가 저장됩니다.
    vector<vector<pair<int,int>>> graphs(V+1);

    // 간선 정보 입력받기
    for(int i=0; i<E; i++){
        int u, v, w; // u: 출발 정점, v: 도착 정점, w: 가중치
        cin >> u >> v >> w;

        // 우선순위 큐(priority_queue)는 기본적으로 pair의 첫 번째 원소(first)를 기준으로 정렬합니다.
        // 따라서 거리가 짧은 경로를 먼저 탐색하기 위해 가중치(w)를 first 자리에 넣습니다.
        graphs[u].push_back({w, v});
    }
    
    // 알고리즘 실행
    Dijkstra(S, min_dist, graphs);

    // 결과 출력
    for(int i=1; i<=V; i++){
        // 거리가 갱신되지 않고 여전히 INF라면 도달 불가능한 정점입니다.
        if(min_dist[i] == INF) cout << "INF\n"; 
        else                   cout << min_dist[i] << "\n"; // 도달 가능하다면 최단 거리 출력
    }
    
    return 0;
}
