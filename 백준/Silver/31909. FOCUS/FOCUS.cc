#include <iostream>
#include <vector>

using namespace std;

// 1. 비트 이동 연산자를 사용하여 교환할 두 인덱스를 찾는 함수
// 입력값 A가 2^B + 2^C 와 같은지 확인합니다.
pair<int,int> interpret(int A){
    // 인덱스는 0부터 7까지이므로 완전 탐색으로 모든 경우의 수를 확인합니다.
    for(int B = 0; B <= 7; B++){
        for(int C = 0; C <= 7; C++){
            // 💡 핵심 포인트: (1 << B)는 2의 B제곱, (1 << C)는 2의 C제곱을 의미합니다.
            // 이전의 반복문 함수 대신 비트 연산자를 사용하여 훨씬 빠르고 간결해졌습니다!
            // 비트 연산자는 덧셈(+)보다 우선순위가 낮으므로 괄호로 묶어준 것은 아주 훌륭한 작성법입니다.
            if(A == ((1 << B) + (1 << C))){
                return {B, C}; // 조건을 만족하는 B와 C 쌍을 반환합니다.
            }
        }
    }
    // 맞는 짝이 없다면 에러를 의미하는 {-1, -1}을 반환합니다.
    return {-1, -1};
}

int main(){
    // 입출력 속도를 높여 알고리즘 성능을 최적화하는 설정입니다.
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N; // 자리 교환을 몇 번 수행할지 입력받습니다.

    // 💡 변수 이름 중복(Shadowing) 알림: 
    // 바깥에 vector<int> order가 선언되어 있지만, 아래 for문 안에서 int order로 다시 선언하고 있습니다.
    // 변수명이 겹치면 혼동이 올 수 있으므로 사용하지 않는 이 벡터 선언을 지워주는 것이 좋습니다.
    vector<int> order(N+1); 
    vector<int> idx(8); // 8개의 자리를 나타내는 배열입니다.

    // 2. 초기 상태 설정
    // 0번 자리부터 7번 자리까지 각자 자기 번호를 갖도록 초기화합니다.
    for(int i = 0; i <= 7; i++){
        idx[i] = i;
    }

    // 3. N번 동안 교환 명령을 수행합니다.
    for(int i = 0; i < N; i++){
        int order_val; // (이해를 돕기 위해 안쪽 변수명을 살짝 변경했습니다)
        cin >> order_val; // 암호화된 교환 명령 숫자를 입력받습니다.
        
        // interpret 함수를 호출하여 어떤 두 자리를 바꿔야 할지 알아냅니다.
        pair<int,int> interpreted = interpret(order_val);

        // 유효한 결과(B와 C)가 나왔다면 두 위치의 값을 서로 바꿉니다.
        if(interpreted.first != -1){
            // 두 변수의 값을 안전하게 서로 바꾸는 Swap 로직입니다.
            int tmp = idx[interpreted.first];
            idx[interpreted.first] = idx[interpreted.second];
            idx[interpreted.second] = tmp;
        }
    }
    
    // 4. 최종 결과 확인
    int target;
    cin >> target; // 최종적으로 번호를 확인하고 싶은 자리를 입력받습니다.

    // 모든 자리 교환이 끝난 후, target 자리에 있는 번호를 출력합니다.
    cout << idx[target] << "\n";
    
    return 0;
}
