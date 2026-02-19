#include <iostream>

using namespace std;

int main(){
    // 1. 입출력 속도 향상을 위한 설정 (Fast I/O)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    cin >> line;

    // 2. 괄호의 인덱스를 저장할 변수를 -1로 안전하게 초기화
    int start = -1;
    int end   = -1;

    // 3. 문자열을 처음부터 끝까지 탐색
    // 주의: break가 없으므로 가장 '마지막'에 등장하는 '(', ')'의 인덱스가 덮어씌워짐
    for(int i=0; i<line.size(); i++){
        if(line[i] == '(') start = i;
        if(line[i] == ')') end   = i;
    }
    
    // 4. 예외 처리: '(' 또는 ')'가 아예 존재하지 않는 경우
    if((start == -1) || (end == -1)){
        cout << "fix" << endl;
        return 0; // 프로그램 조기 종료
    }
    
    // 5. 좌우 문자열 길이 계산
    int left = start; // 첫 문자부터 '(' 전까지의 길이
    int right = line.size() - (end + 1); // ')' 이후부터 끝까지의 길이

    // 6. 대칭 여부 판단 및 출력
    if(left == right) cout << "correct" << endl;
    else              cout << "fix"     << endl;

    return 0;
}
