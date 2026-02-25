#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    // [최적화] C++ 입출력 속도 향상을 위한 설정
    // C와 C++의 표준 스트림 동기화를 해제하여 I/O 속도를 높임
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string func;
        cin >> func; // 수행할 함수 (명령어)

        int len;
        cin >> len;  // 배열에 들어있는 수의 개수

        string digit_in_str = "";
        
        // [핵심 자료구조] 양방향 삽입/삭제가 O(1)에 가능한 Deque 사용
        // R 명령에 따라 앞/뒤 어느 쪽에서든 요소를 삭제하기 위함
        deque<int> dq;

        // 1. 입력 문자열 파싱 (Parsing)
        // "[1,2,34,5]" 와 같은 형태에서 숫자만 추출하여 덱에 저장
        while (true) {
            char ele;
            cin >> ele;

            if (('0' <= ele) && (ele <= '9')) {
                digit_in_str += ele; // 숫자가 연속되면 문자열에 이어 붙임 (예: '3' + '4' = "34")
            } else {
                // 숫자가 아닌 문자(',', ']')를 만났을 때, 누적된 숫자 문자열이 있다면 정수로 변환하여 덱에 삽입
                if (!digit_in_str.empty()) {
                    dq.push_back(stoi(digit_in_str));
                    digit_in_str = ""; // 다음 숫자를 위해 초기화
                }
            }
            if (ele == ']') break; // 배열 입력의 끝
        }
        
        // [핵심 로직] 배열의 논리적 방향 상태와 에러 여부를 저장하는 플래그
        bool is_reversed = false; 
        bool is_error = false;

        // 2. 명령어 수행
        for (char const &command : func) {
            if (command == 'R') {
                // 물리적으로 배열을 뒤집지 않고, 읽는 방향만 반전시킴 O(1)
                is_reversed = !is_reversed;
            } else if (command == 'D') {
                if (dq.empty()) {
                    // 비어있는데 삭제하려 하면 에러
                    is_error = true;
                    break;
                }
                
                // 현재 배열의 방향에 따라 삭제할 위치 결정 O(1)
                if (!is_reversed) {
                    dq.pop_front(); // 정방향이면 맨 앞 요소 삭제
                } else {
                    dq.pop_back();  // 역방향이면 맨 뒤 요소 삭제
                }
            }
        }

        // 3. 결과 출력
        if (is_error) {
            cout << "error" << "\n";
        } else {
            if (!dq.empty()) {
                cout << "[";
                // 최종 방향 상태에 따라 출력 방향을 결정
                if (!is_reversed) {
                    // 정방향: 앞에서부터 출력
                    for (int i = 0; i < dq.size() - 1; i++) {
                        cout << dq[i] << ",";
                    }
                    cout << dq[dq.size() - 1] << "]\n";
                } else {
                    // 역방향: 뒤에서부터 출력
                    for (int i = dq.size() - 1; i > 0; i--) {
                        cout << dq[i] << ",";
                    }
                    cout << dq[0] << "]\n";
                }
            } else {
                // 에러는 발생하지 않았으나, 모든 요소를 삭제하여 빈 배열이 된 경우
                cout << "[]" << "\n";
            }
        }
    }
    return 0;
}
