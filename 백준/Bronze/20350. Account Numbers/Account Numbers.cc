#include <iostream>
#include <string>

using namespace std;

int main(){
    // 입출력 속도 향상을 위한 코드입니다. (C와 C++의 표준 스트림 동기화를 끊어 속도를 높임)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    cin >> line; // 검사할 문자열을 입력받습니다.
    
    // 1. 첫 4글자를 문자열의 맨 뒤로 이동시킵니다.
    for(int i = 0; i < 4; i++){
        line.push_back(line[i]); // 첫 4글자를 차례대로 복사해서 맨 뒤에 붙임
    }
    // 이미 뒤로 복사했으므로, 원본의 앞 4글자는 지워줍니다.
    line.erase(line.begin(), line.begin() + 4); 

    string result = ""; // 알파벳까지 모두 숫자로 변환된 긴 문자열을 저장할 변수

    // 2. 문자열을 순회하며 알파벳을 숫자로 변환합니다.
    for(int i = 0; i < line.size(); i++){
        if(('0' <= line[i]) && (line[i] <= '9')){
            // 숫자 문자인 경우, 그대로 result 문자열에 추가합니다.
            result.push_back(line[i]);
        } else {
            // 알파벳 대문자인 경우, 규칙에 따라 숫자로 변환합니다. ('A'=10, 'B'=11, 'C'=12 ...)
            // ASCII 코드의 성질을 이용해 현재 알파벳에서 'A'를 빼고 10을 더해 값을 구합니다.
            int num = 10 + line[i] - 'A'; 
            string str = to_string(num); // 계산된 숫자를 다시 문자열로 변환합니다.
            result += str; // result 문자열의 끝에 이어 붙입니다.
        }
    }
    
    // 3. 매우 큰 수의 나머지 연산(Modulo) 처리
    // result에 저장된 숫자는 길이가 너무 길어서 int나 long long 타입으로 한 번에 담을 수 없습니다.
    // 따라서 문자열의 맨 앞자리부터 차례대로 읽어가며 97로 나눈 나머지를 누적해서 구합니다.
    long long remainder = 0;

    for(int i = 0; i < result.size(); i++){
        // 이전까지의 나머지 값에 10을 곱해 자릿수를 한 칸 올리고, 
        // 이번에 읽은 문자를 숫자(result[i] - '0')로 변환하여 더한 뒤 97로 나눕니다.
        remainder = (remainder * 10 + (result[i] - '0')) % 97;
    }
    
    // 4. 최종 결과 판별
    // 전체 숫자를 97로 나눈 최종 나머지가 1이면 올바른 입력으로 판별합니다.
    if(remainder == 1){
        cout << "correct\n";
    } else {
        cout << "incorrect\n";
    }
    
    return 0;
}
