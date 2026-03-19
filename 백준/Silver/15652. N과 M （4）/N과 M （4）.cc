#include <iostream>
#include <vector>

using namespace std;

// N: 선택할 수 있는 최대 자연수 (1부터 N까지)
// M: 선택해야 하는 숫자의 개수 (수열의 길이)
int N, M;

// 선택한 숫자들을 담아둘 벡터 (수열을 저장하는 역할)
vector<int> arr;

/**
 * 백트래킹을 수행하는 재귀 함수
 * @param depth 현재까지 선택한 숫자의 개수
 * @param start 이번 탐색에서 선택할 수 있는 가장 작은 숫자 (비내림차순 유지용)
 */
void solve(int depth, int start){
    // 1. 기저 조건 (Base Condition): M개의 숫자를 모두 골랐을 때
    if(depth == M){
        // 완성된 수열을 출력
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return; // 현재 탐색을 종료하고 이전 단계로 돌아감
    }
    
    // 2. 재귀 탐색 (Backtracking)
    // start부터 N까지 반복하여 비내림차순을 유지함
    // 중복을 허용하므로 다음 재귀 호출 시에도 'i'를 넘겨줌
    for(int i = start; i <= N; i++){
        arr.push_back(i);       // 숫자를 선택하여 배열에 추가
        solve(depth + 1, i);    // 깊이(depth)를 1 늘리고, 다음 탐색 시작
        arr.pop_back();         // 탐색이 끝난 후, 다른 숫자를 선택해보기 위해 방금 넣은 숫자를 뺌 (상태 복구)
    }
}

int main(){
    // C++ 표준 입출력 속도를 높이기 위한 최적화 코드
    // 알고리즘 문제 풀이 시 시간 초과를 방지해 줍니다.
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // N과 M 입력 받기
    cin >> N >> M;

    // 백트래킹 시작: 0개를 선택한 상태에서, 1부터 선택 가능
    solve(0, 1);

    return 0;
}
