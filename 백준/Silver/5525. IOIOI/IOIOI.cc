#include <iostream>
#include <string>

using namespace std;

int main(){
    // 입출력 속도 향상을 위한 최적화 (C++ 표준 스트림 동기화 해제)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    string line;
    cin >> line;

    int idx = 0; // 문자열 탐색 인덱스
    int num = 0; // 최종적으로 찾은 PN("IOI" 패턴)의 개수
    int cnt = 0; // 현재 연속으로 발견된 "OI" 패턴의 개수

    // 슬라이딩 윈도우 방식으로 문자열을 한 번만 스캔 (시간 복잡도 O(M))
    // idx부터 3글자(idx, idx+1, idx+2)를 확인해야 하므로 범위는 idx+2 < M
    while(idx + 2 < M){
        // "IOI" 패턴을 발견한 경우
        if((line[idx] == 'I') && (line[idx+1] == 'O') && (line[idx+2] == 'I')){
            cnt++; // "OI" 패턴이 하나 추가됨을 의미
            
            // 연속된 "OI"의 개수가 문제에서 요구하는 N과 같아졌을 때
            if(cnt == N){
                cnt--; // 다음 이어지는 패턴과 겹치는 부분("I")을 고려하여 1 감소
                num++; // 정답 개수 증가
            }
            // "IOI"를 확인했으므로, 다음 검사는 'I'로 끝난 부분부터 시작하도록 2칸 점프
            idx += 2; 
        }
        // "IOI" 패턴이 끊겼거나 아닌 경우
        else{
            cnt = 0; // 연속 카운트 초기화
            idx++;   // 다음 문자로 1칸만 이동하여 처음부터 다시 탐색
        }
    }
    
    cout << num << "\n";

    return 0;
}
