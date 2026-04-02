#include <iostream>
#include <vector>

using namespace std;

// 1. 밀기(Push) 연산
// 중요 포인트: 매개변수로 vector<int> my_answer를 '값(Value)'으로 받습니다. (& 참조자 없음)
// 이렇게 하면 함수가 호출될 때마다 원본 배열이 아닌 '복사본'이 만들어지므로,
// 여러 갈래로 뻗어나가는 DFS 탐색에서 다른 탐색 경로에 영향을 주지 않습니다.
vector<int> push(int p, vector<int> my_answer){
    int size = my_answer.size();

    // 배열의 끝에서부터 p 위치 직전까지 요소를 한 칸씩 뒤로 밉니다.
    for(int i = size - 1; i > p; i--){
        my_answer[i] = my_answer[i - 1];
    }
    // p 위치는 밀어낸 후 빈자리가 되므로 0으로 채웁니다.
    my_answer[p] = 0;

    return my_answer; // 수정된 복사본을 반환합니다.
}

// 2. 당기기(Pull) 연산
// 밀기 연산과 동일하게 원본 보호를 위해 '값 복사' 방식을 사용합니다.
vector<int> pull(int p, vector<int> my_answer){
    int size = my_answer.size();

    // p 위치부터 배열의 끝 직전까지 요소를 한 칸씩 앞으로 당깁니다.
    for(int i = p; i < size - 1; i++){
        my_answer[i] = my_answer[i + 1];
    }
    // 맨 마지막 위치는 당겨진 후 빈자리가 되므로 0으로 채웁니다.
    my_answer[size - 1] = 0;

    return my_answer; // 수정된 복사본을 반환합니다.
}

// 3. 정답 비교 연산
// 여기서는 배열을 수정하지 않고 '읽기'만 하므로, 
// 불필요한 메모리 복사를 막기 위해 참조자(&)를 사용해 속도를 높입니다.
int compare(vector<int> &correct_answer, vector<int> &my_answer){
    int size = correct_answer.size();
    int result = 0;

    for(int i = 0; i < size; i++){
        if(correct_answer[i] == my_answer[i]){
            result++; // 같은 위치에 같은 값이 있으면 정답 개수 증가
        }
    }
    return result;
}

// 4. DFS (깊이 우선 탐색 / 백트래킹)
// depth: 현재까지 수행한 연산 횟수
// max_num: 최댓값을 계속 갱신해야 하므로 참조자(&)로 받습니다.
// my_answer: 현재 상태의 배열 (값 복사로 받아 원본 훼손 방지)
void DFS(int depth, int N, int K, int &max_num, vector<int> &correct_answer, vector<int> my_answer){
    
    // [핵심] K번을 꽉 채워서 연산하지 않아도 (0번, 1번... 수행했을 때) 
    // 중간 결과가 더 좋을 수 있으므로, 매번 탐색마다 최댓값을 갱신해 줍니다.
    max_num = max(max_num, compare(correct_answer, my_answer));

    // 종료 조건: 목표 연산 횟수(K)에 도달하면 더 깊이 들어가지 않고 돌아갑니다.
    if(depth == K) return;

    // 현재 상태에서 가능한 모든 행동(밀기/당기기)을 모든 위치(i)에 대해 시도합니다.
    for(int i = 0; i < N; i++){
        // depth를 1 늘리고, 현재 상태에서 i번째 위치를 '밀기'한 새로운 결과를 다음 탐색에 넘깁니다.
        DFS(depth + 1, N, K, max_num, correct_answer, push(i, my_answer));

        // depth를 1 늘리고, 현재 상태에서 i번째 위치를 '당기기'한 새로운 결과를 다음 탐색에 넘깁니다.
        DFS(depth + 1, N, K, max_num, correct_answer, pull(i, my_answer));
    }
}

int main(){
    // 입출력 속도 향상을 위한 최적화 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> correct_answer(N);
    vector<int> my_answer(N);

    for(int i = 0; i < N; i++){
        cin >> correct_answer[i];
    }
    for(int i = 0; i < N; i++){
        cin >> my_answer[i];
    }
    
    int max_num = 0;
    
    // DFS 탐색 시작: 연산 횟수 0번, 초기 입력받은 내 답안 배열로 출발합니다.
    DFS(0, N, K, max_num, correct_answer, my_answer);
    
    cout << max_num << "\n";
    return 0;
}
