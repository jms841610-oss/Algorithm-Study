#include <iostream>
#include <deque>
#include <string>
#include <sstream> // 문자열 파싱을 위한 stringstream 헤더

using namespace std;

int main() {
    // [최적화] C++ 표준 입출력 동기화 해제로 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // 테스트 케이스 개수

    for (int t = 0; t < T; t++) {
        string func;
        cin >> func; // 수행할 함수 명령어 (예: "RDD")

        int len;
        cin >> len; // 배열에 들어있는 수의 개수

        string arr_str;
        cin >> arr_str; // 배열 형태의 문자열 입력 (예: "[1,2,34,5]")

        deque<int> dq; // 양방향 O(1) 삭제를 위한 덱(Deque) 선언

        // 1. 문자열 전처리 (Pre-processing)
        // 양끝의 대괄호 '[', ']'를 제거하기 위해 인덱스 1부터 길이-2 만큼 잘라냄
        // ex) "[1,2,34,5]" -> "1,2,34,5"
        // 빈 배열 "[]"이 들어올 경우 "[]" -> "" (빈 문자열)이 됨
        arr_str = arr_str.substr(1, arr_str.size() - 2);

        // 2. 문자열 파싱 (Parsing) - stringstream 활용
        if (!arr_str.empty()) {
            stringstream ss(arr_str); // 잘라낸 문자열을 스트림 객체로 변환
            string token;

            // getline()을 사용해 쉼표(',')를 구분자로 삼아 스트림에서 문자열을 읽어옴
            // 읽어온 토큰(숫자 형태의 문자열)을 정수로 변환(stoi)하여 덱에 삽입
            while (getline(ss, token, ',')) {
                dq.push_back(stoi(token));
            }
        }
        
        // 3. 핵심 로직: 상태 변수
        // 배열을 직접 뒤집으면 O(N)이 걸리므로, 읽는 방향만 상태로 기록
        bool is_reversed = false; 
        bool is_error = false;

        // 4. 명령어 수행
        for (char const &command : func) {
            if (command == 'R') {
                // 뒤집기: 방향 상태만 반전 (O(1))
                is_reversed = !is_reversed;
            } else if (command == 'D') {
                if (dq.empty()) {
                    is_error = true; // 비어있는데 지우려 하면 에러
                    break;
                }
                
                // 삭제: 현재 가리키는 방향에 따라 삭제할 위치 결정 (O(1))
                if (!is_reversed) {
                    dq.pop_front(); // 정방향이면 맨 앞 삭제
                } else {
                    dq.pop_back();  // 역방향이면 맨 뒤 삭제
                }
            }
        }

        // 5. 결과 출력
        if (is_error) {
            cout << "error\n";
        } else {
            if (!dq.empty()) {
                cout << "[";
                
                // 최종 방향 상태에 맞추어 덱 순회 및 출력
                if (!is_reversed) {
                    for (int i = 0; i < dq.size() - 1; i++) {
                        cout << dq[i] << ",";
                    }
                    cout << dq[dq.size() - 1] << "]\n";
                } else {
                    for (int i = dq.size() - 1; i > 0; i--) {
                        cout << dq[i] << ",";
                    }
                    cout << dq[0] << "]\n";
                }
            } else {
                cout << "[]\n"; // 모든 요소가 지워졌을 경우 빈 배열 출력
            }
        }
    }
    return 0;
}
