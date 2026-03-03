#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
    // [최적화] 입출력 속도 향상 (Fast I/O)
    // C와 C++의 표준 스트림 동기화를 해제하여 내부 실행 속도를 높임 (알고리즘 문제 풀이 필수 설정)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // 테스트 케이스의 수 입력

    for(int i = 0; i < T; i++){
        vector<string> list; // 파싱된 단어들을 순서대로 저장할 동적 배열

        string line;
        string word;

        // [중요 Point] 버퍼 비우기
        // 이전 단계의 cin >> T 또는 이전 루프의 cin >> num 직후 입력 버퍼에는 개행문자('\n')가 남아있음.
        // 이를 무시하지 않으면 아래의 getline()이 빈 문자열을 읽고 바로 넘어가 버리는 논리적 오류 발생.
        cin.ignore(); 
        
        // 공백을 포함하여 한 줄 전체를 문자열로 입력받음
        getline(cin, line);
        
        // [중요 Point] 문자열 파싱
        // 공백을 기준으로 문자열을 쉽게 자르기 위해 stringstream 사용
        stringstream ss(line);

        // 스트림에서 단어를 하나씩 추출하여 벡터에 추가 (단어가 끝날 때까지 반복)
        while(ss >> word){
            list.push_back(word);
        }
        
        string start;
        cin >> start; // 시작할 기준 단어 입력

        int num;
        cin >> num; // 이동할 칸 수 (번째 수) 입력

        int size = list.size();
        int start_idx = -1;

        // 1. 기준 단어의 인덱스 찾기 (선형 탐색)
        for(int j = 0; j < size; j++){
            if(list[j] == start){
                start_idx = j;
                break;
            }
        }
        
        // 2. [핵심 알고리즘] 최종 도달할 인덱스 계산
        // (현재 인덱스 + 이동할 횟수 - 1) % 배열의 크기
        // 모듈로(%) 연산을 사용하여, 배열의 끝을 넘어가면 다시 0번 인덱스로 돌아오도록 원형 큐(Circular Queue) 논리를 구현함.
        // num에서 1을 빼는 이유는 1번째가 자기 자신(제자리)을 의미하는 1-based 카운팅이기 때문.
        int end_idx = (start_idx + (num - 1)) % size;

        // 결과 출력
        cout << list[end_idx] << "\n";
    }
    return 0;
}
