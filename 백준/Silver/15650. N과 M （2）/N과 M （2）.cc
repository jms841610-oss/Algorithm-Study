#include <iostream>
#include <vector> 

using namespace std;

int N, M;
vector<int> arr; // 선택한 숫자를 담을 배열

// depth: 현재까지 고른 숫자의 개수 (반복문이 몇 번 중첩되었는지)
// start: 이번에 고를 숫자의 시작점 (오름차순을 유지하기 위해 필요)
void solve(int depth, int start) {
    // 1. 종료 조건
    // M개의 숫자를 모두 골랐다면 배열의 내용을 출력하고 함수를 종료합니다.
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 2. 탐색 및 재귀 호출
    // start부터 N까지 순회하면서 숫자를 하나씩 고릅니다.
    for (int i = start; i <= N; i++) {
        arr.push_back(i);           // 1) 숫자를 배열에 넣습니다. (for문 안으로 들어가는 효과)
        solve(depth + 1, i + 1);    // 2) 다음 숫자를 고르기 위해 재귀 호출합니다. (i+1보다 큰 수부터 고름)
        arr.pop_back();             // 3) 재귀 호출이 끝나면, 다음 반복을 위해 방금 넣은 숫자를 뺍니다.
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    // 맨 처음에는 고른 숫자가 0개이고(depth=0), 1부터 탐색을 시작(start=1)합니다.
    solve(0, 1);

    return 0;
}
