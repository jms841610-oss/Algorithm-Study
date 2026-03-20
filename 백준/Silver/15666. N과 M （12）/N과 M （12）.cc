#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> arr; // 입력받은 원본 숫자들을 저장할 배열
vector<int> ans; // 현재까지 탐색하며 고른 숫자들을 저장할 배열 (하나의 수열을 완성해 나감)

// 백트래킹을 수행하는 함수
// 매개변수 설명:
// - depth: 현재까지 고른 숫자의 개수 (트리의 깊이)
// - current: 직전에 고른 숫자 (비내림차순 조건을 유지하기 위해 기준이 됨)
void solve(int depth, int current) {
    // 1. 종료 조건 (Base Condition)
    // M개의 숫자를 모두 골랐다면 (목표한 길이에 도달했다면)
    if (depth == M) {
        // 완성된 수열(ans)을 출력합니다.
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return; // 현재 가지의 탐색을 마치고 이전 단계로 돌아갑니다.
    }

    // prev: 같은 깊이(위치)에서 동일한 숫자를 중복해서 고르는 것을 방지하기 위한 변수
    // 함수가 호출될 때마다 0으로 초기화되어, 현재 위치(depth)에서의 중복만 걸러냅니다.
    int prev = 0;

    // 2. 탐색 (재귀 호출)
    // 원본 배열(arr)을 처음부터 끝까지 확인합니다.
    for (int i = 0; i < N; i++) {
        // 조건 1 (arr[i] >= current): 고르려는 숫자가 직전에 고른 숫자보다 크거나 같아야 함 (비내림차순 유지)
        // 조건 2 (arr[i] != prev): 고르려는 숫자가 방금 이 자리에서 골랐던 숫자와 달라야 함 (중복 수열 방지)
        if ((arr[i] >= current) && (arr[i] != prev)) {
            
            // 조건에 맞으면 숫자를 고릅니다.
            ans.push_back(arr[i]); 
            
            // 다음 자리의 숫자를 고르기 위해 재귀 호출을 합니다.
            // 고른 개수(depth)를 1 늘리고, 방금 고른 숫자(arr[i])를 새로운 current로 넘겨줍니다.
            solve(depth + 1, arr[i]); 
            
            // 재귀 호출이 끝났다는 것은 해당 숫자를 포함하는 모든 경우의 수를 다 확인했다는 뜻입니다.
            // 다음 숫자를 넣어보기 위해 방금 넣었던 숫자를 다시 뺍니다. (백트래킹의 핵심)
            ans.pop_back(); 

            // 방금까지 확인을 마친 숫자를 prev에 기록해 둡니다.
            // 다음 반복문(i+1)에서 똑같은 숫자가 또 나오면 건너뛰게 됩니다.
            prev = arr[i]; 
        }
    }
}

int main() {
    // C++ 입출력 속도 향상을 위한 필수 코드 (알고리즘 문제 풀이용)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // N: 주어지는 숫자의 개수, M: 고를 숫자의 개수
    cin >> N >> M;

    arr.assign(N, 0); // 크기가 N인 배열을 0으로 초기화
    ans.reserve(N);   // ans 배열의 메모리를 미리 확보 (불필요한 메모리 재할당 방지, 좋은 습관입니다!)

    // N개의 숫자를 입력받음
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 입력받은 배열을 오름차순으로 정렬합니다.
    // 비내림차순으로 출력해야 하고, 동일한 숫자가 연속해서 나오게 하여 prev로 중복을 쉽게 걸러내기 위함입니다.
    sort(arr.begin(), arr.end());

    // 백트래킹 시작: 
    // 고른 개수 0개(depth=0), 직전에 고른 숫자 0(current=0)으로 탐색을 시작합니다.
    solve(0, 0);

    return 0;
}
