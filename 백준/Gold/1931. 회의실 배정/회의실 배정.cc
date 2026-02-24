#include <iostream>
#include <queue>

using namespace std;

// 회의 시간을 담는 구조체 정의
struct Time {
    int start;
    int end;

    // 우선순위 큐(priority_queue) 정렬을 위한 연산자 오버로딩
    // 주의: priority_queue는 기본적으로 최대 힙(Max-Heap)이므로 가장 큰 값이 Top에 위치함.
    // 종료 시간이 가장 빠른 회의를 Top으로 올리기 위해(최소 힙처럼 사용하기 위해) 부등호를 반대(>)로 설정함.
    bool operator<(const Time & other) const {
        if(end == other.end){
            // 2순위: 종료 시간이 같다면, 시작 시간이 '빠른' 순서대로 정렬 (반례 해결)
            return start > other.start; 
        }
        // 1순위: 종료 시간이 '빠른' 순서대로 정렬
        return end > other.end; 
    }
};

int main() {
    // 입출력 속도 향상을 위한 Fast I/O (C++ 표준 입출력 동기화 해제)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
 
    // 정렬 기준(Time 구조체의 operator<)에 따라 회의를 자동 정렬해주는 우선순위 큐
    priority_queue<Time> pq;

    for(int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        pq.push({start, end}); // 삽입과 동시에 $O(\log N)$ 시간으로 힙 트리 재구성
    }
    
    int prev_end = 0; // 직전 회의의 종료 시간 추적
    int cnt = 0;      // 배정된 최대 회의 개수

    // 그리디(Greedy) 알고리즘 핵심 로직
    // "종료 시간이 가장 빠른 회의부터 무조건 선택한다"
    while(!pq.empty()) {
        Time current = pq.top();
        pq.pop();
        
        // 현재 확인하는 회의의 시작 시간이, 이전에 배정된 회의의 종료 시간 이후라면 배정 가능
        if(current.start >= prev_end) {
            cnt++;
            prev_end = current.end; // 다음 회의 판단을 위해 종료 시간 갱신
        }
    }
    
    cout << cnt << "\n";

    return 0;
}
