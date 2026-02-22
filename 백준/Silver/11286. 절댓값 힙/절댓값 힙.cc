#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

/*
 * 우선순위 큐를 위한 커스텀 비교 구조체 (Comparator)
 * C++의 priority_queue는 기본적으로 최대 힙(Max Heap)으로 동작합니다.
 * 따라서 문제 요구사항에 맞는 최소 힙(Min Heap) 형태로 정렬하려면,
 * 우선순위가 낮아야 하는(아래로 내려가야 하는) 조건일 때 true를 반환하도록 작성해야 합니다.
 */
struct absolute_smaller {
    bool operator()(const int a, const int b) const {
        // 1. 두 수의 절댓값이 같은 경우: 실제 값을 기준으로 비교
        if (abs(a) == abs(b)) {
            // 실제 값이 더 큰 쪽이 우선순위가 낮도록(배열의 뒤쪽으로 가도록) 설정
            // 즉, 값이 작은 것이 먼저 출력되는 오름차순 효과를 냄
            return a > b; 
        }
        // 2. 두 수의 절댓값이 다른 경우: 절댓값을 기준으로 비교
        // 절댓값이 더 큰 쪽이 우선순위가 낮도록 설정 (절댓값 오름차순)
        return abs(a) > abs(b);
    }
};

int main() {
    /* * 팁: 백준 등 알고리즘 플랫폼에서 N이 100,000 이상일 경우,
     * 아래 두 줄의 Fast I/O 코드를 추가하면 시간 초과(TLE)를 방지할 수 있습니다.
     * ios_base::sync_with_stdio(false);
     * cin.tie(NULL);
     */
     
    int N;
    cin >> N;

    // int형 데이터를 담고, 내부적으로 vector<int>를 사용하며,
    // absolute_smaller 비교 기준을 따르는 우선순위 큐 선언
    priority_queue<int, vector<int>, absolute_smaller> pq;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        // x가 0일 때: 배열에서 절댓값이 가장 작은 값을 출력하고 제거
        if (x == 0) {
            if (!pq.empty()) {
                int top_val = pq.top(); // 가장 우선순위가 높은(절댓값이 작은) 값 확인
                pq.pop();               // 큐에서 해당 값 제거 (O(log N))
                cout << top_val << "\n";
            } else {
                // 큐가 비어있는데 0이 입력된 경우 0을 출력
                cout << 0 << "\n";
            }
        } 
        // x가 0이 아닐 때: 우선순위 큐에 값을 추가
        else {
            pq.push(x); // 알맞은 위치를 찾아 트리에 삽입됨 (O(log N))
        }
    }
    
    return 0;
}
