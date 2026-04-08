#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// 위치별 최소 시간(cost)과 그 시간에 도달하는 방법의 수(num)를 저장하는 구조체입니다.
typedef struct{
    int cost = INT_MAX; // 최소 비용을 찾기 위해 초기값은 무한대(INT_MAX)로 설정합니다.
    int num  = 0;       // 해당 위치에 도달하는 방법의 수는 0으로 시작합니다.
} END;

void BFS(const int start, const int end, vector<END> &end_list){
    queue<pair<int,int>> q; // {현재까지의 걸린 시간(비용), 현재 위치}를 저장하는 큐
    q.push({0, start});

    // 시작 위치 초기화: 걸린 시간은 0, 경우의 수는 1 (자기 자신에 있는 상태)
    end_list[start].cost = 0;
    end_list[start].num  = 1;

    while(!q.empty()){
        int front_cost = q.front().first;  // 현재 정점까지 걸린 시간
        int front      = q.front().second; // 현재 위치 (정점)
        q.pop();

        // 수빈이가 이동할 수 있는 3가지 경우 (앞으로 걷기, 뒤로 걷기, 순간이동)
        int next[] = {front + 1, front - 1, front * 2};

        for(int i = 0; i < 3; i++){
            // 1. 이동할 위치가 맵의 제한 범위를 벗어나지 않는지 안전하게 확인합니다.
            if((0 <= next[i]) && (next[i] <= 100000)){

                // 2. 이미 방문한 적이 있지만, '같은 최소 시간'으로 다른 경로를 통해 도달한 경우
                // 이 부분이 경우의 수를 누적하는 핵심 로직입니다!
                if(end_list[next[i]].cost == front_cost + 1){
                    // 큐에 다시 넣지 않고(이미 최소 시간으로 탐색 중이므로), 도달하는 방법의 수만 더해줍니다.
                    end_list[next[i]].num += end_list[front].num;

                // 3. 처음 방문하거나, 기존에 기록된 시간보다 '더 짧은 시간'으로 도달한 경우
                }else if(end_list[next[i]].cost > front_cost + 1){
                    // 최소 시간을 새롭게 갱신하고, 방법의 수를 현재 위치의 방법의 수로 덮어씁니다.
                    end_list[next[i]].cost = front_cost + 1;
                    end_list[next[i]].num  = end_list[front].num;
                    
                    // 새로운 최단 경로를 찾았으므로 큐에 넣어 다음 탐색을 이어갑니다.
                    q.push({end_list[next[i]].cost, next[i]});
                }
            }
        }
    }
    return;
}

int main(){
    // 입출력 속도를 높여주는 코드입니다. (C++ 알고리즘 풀이의 필수 팁!)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int start, end;
    cin >> start >> end; // 시작 위치(start)와 목표 위치(end) 입력

    // 0부터 100,000까지의 위치 정보를 저장할 수 있는 벡터 생성
    vector<END> end_list(100001);

    // BFS 탐색 시작!
    BFS(start, end, end_list);

    // 목표 위치에 도달하는 최소 시간(cost)과 그 경우의 수(num)를 출력합니다.
    cout << end_list[end].cost << "\n";
    cout << end_list[end].num  << "\n";
    
    return 0;
}
