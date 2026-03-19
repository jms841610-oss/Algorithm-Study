#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> result; // 현재까지 선택한 숫자들을 담아두는 배열 (크기가 M이 되면 출력)
vector<int> arr;    // 입력받은 N개의 후보 숫자들을 저장하는 배열

// 중복 선택을 방지하기 위한 방문(사용) 체크 배열
// 숫자의 최대값이 10000이므로 인덱스를 바로 활용하기 위해 10001 크기로 할당
vector<bool> is_used(10001, false);

// 백트래킹 함수
// depth: 현재까지 결과 배열(result)에 담은 숫자의 개수
void solve(int depth) {
    // 1. 종료 조건 (Base Condition)
    // 목표한 개수(M)만큼 숫자를 모두 골랐다면?
    if (depth == M) {
        // 결과 배열에 들어있는 숫자들을 순서대로 출력
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return; // 현재 탐색을 마치고 직전 상태로 돌아감 (Backtrack)
    }

    // 2. 탐색 과정
    // 후보 숫자들(arr)을 처음부터 끝까지 하나씩 확인
    for (int i = 0; i < N; i++) {
        // 현재 숫자 arr[i]가 아직 순열에 포함되지 않았다면?
        if (!is_used[arr[i]]) {
            // [선택] 결과 배열에 넣고, 사용했다고 표시
            result.push_back(arr[i]);
            is_used[arr[i]] = true;

            // [재귀] 다음 숫자를 고르기 위해 깊이(depth)를 1 늘려서 다시 함수 호출
            solve(depth + 1);

            // [복구] 백트래킹의 핵심 ⭐️
            // 위 재귀 함수가 끝났다는 것은 해당 방향으로의 탐색이 끝났다는 뜻.
            // 다른 경우의 수를 구하기 위해 방금 넣었던 숫자를 빼고, 사용 표시도 지움
            result.pop_back();
            is_used[arr[i]] = false;
        }
    }
}

int main() {
    // 입출력 속도 향상 (C++ 표준 스트림의 동기화를 끊음)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    // 벡터의 용량을 미리 할당하여 불필요한 메모리 재할당 방지 (최적화)
    arr.reserve(N);
    result.reserve(M);

    // 후보 숫자 N개 입력받기
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    
    // 사전순(오름차순)으로 결과를 출력하기 위해 입력 배열을 미리 정렬
    sort(arr.begin(), arr.end());
    
    // 백트래킹 시작 (0개 고른 상태에서 출발)
    solve(0);

    return 0;
}
