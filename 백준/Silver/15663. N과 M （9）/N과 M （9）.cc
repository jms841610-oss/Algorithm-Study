#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> ans;
vector<bool> visited; // 방문(사용) 여부를 체크할 배열 추가

void solve(int depth) {
    // 목표한 길이(M)만큼 수열을 만들었다면 출력
    if(depth == M) {
        for(int i = 0; i < M; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    int prev = 0; // 같은 깊이(자리)에서 중복된 값을 고르지 않기 위한 변수

    for(int i = 0; i < arr.size(); i++) {
        // 아직 방문하지 않았고, 이전에 고른 값과 다르다면 선택
        if(!visited[i] && (prev != arr[i])) {
            
            visited[i] = true;     // 1. 현재 인덱스 방문 처리 (사용함)
            ans.push_back(arr[i]); // 2. 수열에 추가
            
            solve(depth + 1);      // 3. 다음 숫자를 고르기 위해 재귀 호출
            
            ans.pop_back();        // 4. 수열에서 제거 (백트래킹)
            visited[i] = false;    // 5. 방문 처리 해제 (다른 수열에서 쓸 수 있도록)
            
            prev = arr[i];         // 6. 현재 값을 prev에 저장하여 중복 방지
        }
    }
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    arr.assign(N, 0);
    visited.assign(N, false); // 방문 배열을 N 크기만큼 false로 초기화
    ans.reserve(M); // M만큼 미리 공간을 확보하는 것이 더 효율적입니다.

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    // 사전순 출력을 위한 정렬
    sort(arr.begin(), arr.end());

    // 초기 깊이 0으로 시작
    solve(0);

    return 0;
}
