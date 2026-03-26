#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 무한대를 의미하는 값으로, 아직 방문하지 않은 위치의 초기 비용으로 사용해요.
const int INF = 1e9; 

int Dijkstra(int N, int K){
    // cost 배열: 각 위치(0 ~ 100,000)까지 도달하는 데 걸리는 최소 시간을 저장해요.
    // 처음에는 아무 곳도 방문하지 않았으므로 모두 무한대(INF)로 초기화합니다.
    vector<int> cost(100001, INF);
    
    // 우선순위 큐(Min-Heap): {현재까지의 비용, 현재 위치}를 묶어서 저장해요.
    // greater<>를 사용해서 비용이 가장 '적은(빠른)' 경로가 큐의 맨 위에 오도록 설정했어요! (다익스트라의 핵심)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    // 1. 시작 위치(N) 초기화
    cost[N] = 0;      // 시작 위치에서 시작 위치까지의 비용은 0초예요.
    pq.push({0, N});  // 큐에 시작 상태를 넣고 탐색을 시작합니다.

    // 2. 다익스트라 탐색 시작
    while(!pq.empty()){
        int current_cost = pq.top().first;  // 큐에서 꺼낸 현재 위치까지의 누적 시간
        int current_node = pq.top().second; // 큐에서 꺼낸 현재 위치
        pq.pop(); 
        
        // 목표 위치(K)에 도달했다면, 가장 비용이 적은 경로로 온 것이므로 즉시 반환하고 끝내요.
        if(current_node == K){
            return current_cost;
        }

        // 최적화: 큐에서 꺼낸 비용이 이미 기록된 최소 비용보다 크다면?
        // => 이미 다른 더 빠른 길을 통해 방문했던 곳이므로 굳이 탐색할 필요가 없어요. (시간 초과 방지)
        if(cost[current_node] < current_cost){
            continue;
        }

        // 다음에 이동할 수 있는 3가지 위치를 배열에 담아둡니다.
        int next[3];
        next[0] = current_node + 1; // 앞으로 1칸 걷기
        next[1] = current_node - 1; // 뒤로 1칸 걷기
        next[2] = current_node * 2; // 순간이동

        // 3. 인접한 다음 위치 탐색 및 업데이트
        for(int i = 0; i < 3; i++){
            // 조건: 이동할 다음 위치가 맵의 유효한 범위(0 ~ 100,000) 안에 있어야 해요.
            if((0 <= next[i]) && (next[i] <= 100000)){
            
                int next_cost;
                // 비용 계산: 순간이동(i==2)일 때는 시간이 0초 들고, 걷기일 때는 1초가 들어요.
                if(i != 2) next_cost = current_cost + 1;
                else       next_cost = current_cost;

                // 새로 계산한 이동 비용이, 기존에 알고 있던 해당 위치의 최소 비용보다 더 작다면?
                // => 더 빠른 길을 찾아냈다는 뜻이에요!
                if(next_cost < cost[next[i]]){
                    cost[next[i]] = next_cost;         // 최소 비용을 새로운 값으로 업데이트하고,
                    pq.push({next_cost, next[i]});     // 큐에 넣어서 이 위치부터 다시 탐색을 이어나가게 해요.
                }
            }
        }
    }
    // K에 도달할 수 없는 경우 (보통 이 문제에서는 발생하지 않지만, 기본적으로 -1을 반환하게 두는 것이 안전해요)
    return -1; 
}

int main(){
    // C++의 입출력 속도를 대폭 높여주는 코드예요! 코딩 테스트에서 습관처럼 적어주시면 좋아요.
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K; // N: 시작 위치, K: 목표 위치
    
    int ans = Dijkstra(N, K); // 다익스트라 함수 호출
    
    cout << ans << "\n"; // 최소 시간 출력
    return 0;
}
