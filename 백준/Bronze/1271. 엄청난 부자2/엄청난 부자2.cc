#include <iostream>
#include <string>

using namespace std;

// 전역 변수로 선언하여 메모리 영역(Data Segment) 활용
string N, M, Q, R; 

// 문자열을 뒤집는 함수
// 큰 수 연산 시 일의 자리부터 계산하기 위해 자주 사용됨
string reversing(string a){
    int len = a.size();
    for(int i = 0; i < len / 2; i++){
        char tmp = a[i];
        a[i] = a[len - i - 1];
        a[len - i - 1] = tmp;
    }
    return a;
}

// 큰 수 뺄셈 함수 (a - b)
// 전제 조건: 항상 a >= b 여야 함 (음수 결과 처리 미구현)
string subtracting(string a, string b){
    if(a == b) return "0"; // 같으면 0 반환
    
    string result = "";

    // 일의 자리를 맞추기 위해 뒤집음
    a = reversing(a);
    b = reversing(b);

    int len_a = a.size();
    int len_b = b.size();
    int bring = 0; // 빌림수(borrow)

    for(int i = 0; i < len_a; i++){
        int a_ele = a[i] - '0';
        // b의 길이가 더 짧을 경우 0으로 처리 (Padding 효과)
        int b_ele = (len_b > i) ? (b[i] - '0') : 0; 
        
        int ele_sum = a_ele - b_ele - bring;

        if(ele_sum < 0){
            ele_sum += 10; // 앞 자리에서 빌려옴
            bring = 1;
        } else {
            bring = 0;
        }
        result.push_back(ele_sum + '0');
    }
    
    // 계산이 끝난 후 다시 원래 순서로 뒤집음
    result = reversing(result);

    // 앞쪽의 불필요한 '0' 제거 (Leading Zeros Removal)
    // 예: "007" -> "7". 단, 결과가 "0"인 경우 비우지 않도록 size check 주의
    while((result[0] == '0') && (result.size() > 0)) result.erase(0, 1);

    return result;
}

// 큰 수 크기 비교 함수
// a가 b보다 크거나 같으면 true, 아니면 false
bool is_bigger(string a, string b){
    // 1. 길이가 길면 더 큰 수
    if (a.size() > b.size()) return true;
    // 2. 길이가 짧으면 더 작은 수
    else if(a.size() < b.size()) return false;
    // 3. 길이가 같으면 사전 순(Lexicographical) 비교
    else return (a >= b);
}

// 나눗셈 수행 함수 (핵심 로직)
// 손으로 하는 장제법(Long Division)을 시뮬레이션
void dividing(){
    Q = ""; // 몫
    R = ""; // 나머지

    // 피제수(N)의 가장 높은 자릿수부터 하나씩 내려받음
    for(char digit : N){
        R.push_back(digit); // 나머지에 다음 자릿수 추가

        // 나머지 앞에 붙은 불필요한 '0' 제거 (예: "05" -> "5")
        while((R[0] == '0') && (R.size() > 0)) R.erase(0, 1);

        int cnt = 0; // 몫의 해당 자릿수 (0~9)

        // 나머지가 제수(M)보다 크거나 같은 동안 계속 뺌
        // 나눗셈을 '반복 뺄셈'으로 구현한 부분
        while(is_bigger(R, M)){
            R = subtracting(R, M);
            cnt++;
        }
        Q.push_back(cnt + '0'); // 구한 몫의 자릿수 추가
    }
    
    // 몫의 앞쪽 불필요한 '0' 제거
    while((Q[0] == '0') && (Q.size() > 0)) Q.erase(0, 1);

    // 결과가 비어있다면(완전 나누어 떨어지거나 몫이 0일 때) "0" 처리
    if(Q.empty()) Q = "0";
    if(R.empty()) R = "0";

    return;
}

int main(){
    // 입출력 속도 향상 (C++ 스타일)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    dividing();

    cout << Q << endl << R << endl;

    return 0;
}
