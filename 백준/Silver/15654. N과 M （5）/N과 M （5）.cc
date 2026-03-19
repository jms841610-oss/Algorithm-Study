#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> result; // 현재 탐색 중인 순열을 저장하는 배열
vector<int> arr;    // 입력받은 N개의 숫자를 저장하는 배열
// 특정 숫자가 현재 순열에 포함되어 있는지 확인하는 방문 처리 배열 
// (입력되는 숫자의 최대값이 10000이라고 가정하여 크기를 10001로 설정)
vector<bool> is_used(10001, false); 

// 백트래킹을 수행하는 재귀 함수
// depth: 현재까지 선택한 숫자의 개수 (깊이)
// current: 이 코드에서는 사용되지 않지만, 조합(Combination)을 구할 때 오름차순 조건을 위해 자주 쓰이는 매개변수입니다.
void solve(int depth, int current) {
    // 1. 종료 조건 (Base Condition)
    // M개의 숫자를 모두 골랐다면 (원하는 길이에 도달했다면)
    if (depth == M) {
        // 결과 배열에 담긴 숫자들을 출력
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return; // 현재 가지(branch)의 탐색을 마치고 이전 단계로 돌아감
    }
    
    // 2. 탐색 과정
    // 입력받은 N개의 숫자를 처음부터 끝까지 확인
    for (int i = 0; i < N; i++) {
        // 현재 숫자 arr[i]가 아직 사용되지 않았다면
        if (!is_used[arr[i]]) {
            // [선택] 현재 숫자를 결과 배열에 넣고 방문 처리
            result.push_back(arr[i]);
            is_used[arr[i]] = true;

            // [재귀 호출] 다음 숫자를 고르기 위해 깊이를 1 증가시켜 재귀 호출
            solve(depth + 1, arr[i]);

            // [상태 복구] 백트래킹의 핵심!
            // 탐색을 마치고 돌아왔으므로, 다른 경우의 수를 찾기 위해 방금 넣은 숫자를 빼고 방문 처리 해제
            result.pop_back();
            is_used[arr[i]] = false;
        }
    }
}

int main() {
    // C++ 표준 입출력 속도 향상을 위한 설정 (시간 초과 방지)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // N과 M 입력
    cin >> N >> M;

    // 벡터 메모리 미리 할당 (성능 최적화)
    arr.reserve(N);
    result.reserve(M);

    // N개의 숫자 입력받기
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    
    // 사전순(오름차순) 출력을 위해 입력받은 배열을 정렬
    sort(arr.begin(), arr.end());
    
    // 백트래킹 시작 (0개 선택한 상태에서 시작)
    solve(0, 0);

    return 0;
}
