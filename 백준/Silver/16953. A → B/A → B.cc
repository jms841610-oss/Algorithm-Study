#include <iostream>
#include <queue>

using namespace std;

// 자료형을 long long으로 변경하여 오버플로우 방지
long long a, b;

void BFS() {
    // 큐에 {현재 숫자, 연산 횟수(비용)}을 함께 저장합니다.
    queue<pair<long long, long long>> order;
    
    // 초기 시작점 a와 시작 연산 횟수 1을 큐에 삽입합니다.
    order.push({a, 1});

    while (!order.empty()) {
        long long current_val = order.front().first;
        long long current_cost = order.front().second;
        order.pop();

        // 목표값에 도달한 경우 비용을 출력하고 종료합니다.
        if (current_val == b) {
            cout << current_cost << "\n";
            return;
        }

        // 두 가지 연산 진행
        long long next1 = current_val * 2;
        long long next2 = current_val * 10 + 1;

        // 방문 배열 대신, 계산된 값이 목표값 b보다 작거나 같을 때만 큐에 추가합니다.
        if (next1 <= b) {
            order.push({next1, current_cost + 1});
        }
        if (next2 <= b) {
            order.push({next2, current_cost + 1});
        }
    }
    
    // 큐가 빌 때까지 탐색했으나 b를 만들 수 없는 경우
    cout << -1 << "\n";
}

int main() {
    // 입출력 속도 향상을 위한 구문
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    BFS();

    return 0;
}
