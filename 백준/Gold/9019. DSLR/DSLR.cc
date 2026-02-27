#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// [D 연산] 값을 2배로 바꾸고 10000으로 나눈 나머지 반환
int D(int n){
    return (2 * n) % 10000;
}

// [S 연산] 1을 빼며, 0일 경우 9999로 롤오버(Rollover) 처리
int S(int n){
    if(n == 0) return 9999;
    else       return n - 1;
}

// [L 연산] 4자리 숫자를 왼쪽으로 회전 (수학적 최적화)
// 예: 1234 -> (1234 % 1000) * 10 + (1234 / 1000) -> 2340 + 1 = 2341
int L(int n){
    return (n % 1000) * 10 + (n / 1000);
}

// [R 연산] 4자리 숫자를 오른쪽으로 회전 (수학적 최적화)
// 예: 1234 -> (1234 % 10) * 1000 + (1234 / 10) -> 4000 + 123 = 4123
int R(int n){
    return (n % 10) * 1000 + (n / 10);
}

// 최단 경로(최소 명령어)를 찾기 위한 너비 우선 탐색
string BFS(int A, int B){
    // 경로 역추적을 위한 상태 저장 배열 (공간 복잡도 O(V)로 최적화)
    vector<int> parent(10000);   // 어떤 숫자에서 파생되었는지 '이전 노드' 기록
    vector<char> command(10000); // 이전 노드에서 넘어올 때 사용한 '명령어' 기록
    vector<bool> is_visited(10000, false); // 중복 방문 방지
    queue<int> order;

    // 시작 노드(A) 초기화
    order.push(A);
    is_visited[A] = true;
    parent[A] = A; // 시작점의 부모는 자기 자신으로 설정

    while(!order.empty()){
        int current = order.front();
        order.pop();

        // 목적지(B)에 도달했을 경우 경로 역추적 시작
        if(current == B){
            string result = "";

            // 목적지 B에서부터 시작점 A까지 거슬러 올라가며 명령어 수집
            while(current != A){
                result += command[current];
                current = parent[current];
            }
            
            // 역추적했으므로 명령어의 순서가 반대임. 배열을 뒤집어 올바른 순서로 복구
            int len = result.length();
            for(int i = 0; i < len / 2; i++){
                char temp = result[i];
                result[i] = result[len - 1 - i];
                result[len - 1 - i] = temp;
            }
            return result;
        }

        // 4가지 연산 수행에 따른 다음 상태 계산
        int D_val = D(current);
        int S_val = S(current);
        int L_val = L(current);
        int R_val = R(current);

        // 각 연산의 결과가 아직 방문하지 않은 상태라면 큐에 넣고 역추적 정보 기록
        if(!is_visited[D_val]){
            order.push(D_val);
            is_visited[D_val] = true;
            parent[D_val] = current;
            command[D_val] = 'D';
        }
        if(!is_visited[S_val]){
            order.push(S_val);
            is_visited[S_val] = true;
            parent[S_val] = current;
            command[S_val] = 'S';
        }
        if(!is_visited[L_val]){
            order.push(L_val);
            is_visited[L_val] = true;
            parent[L_val] = current;
            command[L_val] = 'L';
        }
        if(!is_visited[R_val]){
            order.push(R_val);
            is_visited[R_val] = true;
            parent[R_val] = current;
            command[R_val] = 'R';
        }
    }
    return "ERROR";
}

int main(){
    // C++ 표준 입출력 속도 최적화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    // 테스트 케이스만큼 반복
    for(int i = 0; i < T; i++){
        int A, B;
        cin >> A >> B;

        string command = BFS(A, B);
        cout << command << "\n";
    }
    return 0;
}
