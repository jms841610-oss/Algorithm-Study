#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// [1] 문자열 뒤집기 함수
// 덧셈과 곱셈을 쉽게 하기 위해 일의 자리 수가 인덱스 0에 오도록 문자열을 뒤집습니다.
void reverse(string &a){
    int len = a.length();

    for(int i = 0; i < len / 2; i++){
        char tmp = a[i];
        a[i] = a[len - 1 - i];
        a[len - 1 - i] = tmp;
    }
    return;
}

// [2] 큰 수 덧셈 함수
// 뒤집힌 두 문자열(숫자)을 더합니다.
string add(string a, string b){
    string result = "";

    int len_a = a.length();
    int len_b = b.length();
    int max_len = max(len_a, len_b);

    int bring = 0; // 올림수 (Carry) 저장용 변수

    for(int i = 0; i < max_len; i++){
        // 자릿수가 부족하면 '0'으로 채워서 계산합니다.
        char ch_a = (len_a - 1 >= i) ? a[i] : '0';
        char ch_b = (len_b - 1 >= i) ? b[i] : '0';

        // 문자를 실제 정수로 변환하여 더하기 위해 '0'을 빼줍니다.
        int sub_sum = (ch_a - '0') + (ch_b - '0') + bring;
        
        // 일의 자리는 결과 문자열에 넣고 ('0'을 더해 다시 문자로 변환)
        result.push_back((sub_sum % 10) + '0');
        // 십의 자리는 다음 자릿수 계산을 위해 올림수에 저장합니다.
        bring = sub_sum / 10;
    }
    // 마지막 자릿수까지 더했는데 올림수가 남았다면 맨 뒤에 추가해 줍니다.
    if(bring != 0) result.push_back(bring + '0');

    return result;
}

// [3] 큰 수 곱셈 함수
string multi(string a, string b){
    // 0을 곱하면 무조건 0이므로 예외 처리
    if((a == "0") || (b == "0")) return "0";

    string result = "0";
    
    // b의 각 자릿수를 돌면서 a와 곱합니다.
    for(int i = 0; i < b.length(); i++){
        string tmp = "";

        // b의 자릿수가 높아질수록 10배, 100배가 되므로, 
        // 뒤집힌 문자열 기준으로는 앞에 '0'을 그만큼 채워줍니다.
        for(int j = 0; j < i; j++) tmp.push_back('0');

        int pass = 0; // 올림수 (Carry)

        for(int j = 0; j < a.length(); j++){
            // 문자를 숫자로 변환('- 0')하여 곱하고, 이전 자릿수에서 넘어온 올림수를 더함
            int current = (a[j] - '0') * (b[i] - '0') + pass;
            tmp.push_back((current % 10) + '0');
            pass = current / 10;
        }
        // 곱셈이 다 끝난 후 남은 올림수 처리
        if(pass != 0) tmp.push_back(pass + '0');
        
        // 각 자릿수별로 곱해진 결과(tmp)를 최종 결과(result)에 누적해서 더합니다.
        result = add(result, tmp);
    }
    return result;
}

// [4] 거듭제곱 연산 함수 (a^b)
string square(int a, int b){
    if(a == 0) return "0"; // 0의 거듭제곱 예외 처리

    string result = "1";
    string string_a = to_string(a); // int를 string으로 변환
    reverse(string_a);              // 연산을 위해 문자열 뒤집기

    // a를 b번 곱해줍니다.
    for(int i = 0; i < b; i++){
        result = multi(result, string_a);
    }
    return result;
}

// [5] 특정 j에 대해 x^j + y^j = z^j 를 만족하는 (x, y, z) 쌍의 개수를 구하는 함수
int get_num(int m, int j){
    int result = 0;

    // [핵심 최적화 포인트!] 메모이제이션(캐싱)
    // 3중 반복문 안에서 매번 제곱을 계산하면 무한 루프처럼 멈춰버리기 때문에,
    // 0부터 m까지의 제곱 값들을 배열에 미리 한 번만 계산해서 저장합니다.
    vector<string> square_j(m + 1);

    for(int i = 0; i <= m; i++){
        square_j[i] = square(i, j);
    }
    
    // 중복 계산을 피해 미리 저장한 배열(square_j)의 값을 가져와서 비교합니다.
    for(int x = 0; x <= m; x++){
        for(int y = x; y <= m; y++){
            string add_x_y = add(square_j[x], square_j[y]); // x^j + y^j

            for(int z = y; z <= m; z++){
                if(add_x_y == square_j[z]){ // x^j + y^j == z^j 조건 확인
                    result++;
                }
            }
        }
    }
    return result;
}

int main(){
    // C++ 표준 입출력 속도를 높여주는 마법의 주문입니다. (알고리즘 문제 풀이 시 필수!)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    int ans = 0;

    // j가 2부터 n까지일 때의 모든 경우의 수를 누적합니다.
    for(int j = 2; j <= n; j++){
        ans += get_num(m, j);
    }
    
    cout << ans << "\n";
    
    return 0;
}
