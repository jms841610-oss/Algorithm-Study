#include <iostream>
#include <vector>

using namespace std;

int main(){
    // [최적화] C++ 입출력 속도 향상을 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // list: 입력받은 모든 단어를 순서대로 저장하는 배열
    vector<string> list(N);
    
    // exist: 모든 단어의 '첫 글자'가 무엇인지 기록하는 알파벳 체크 배열 (A~Z, 총 26개)
    // 인덱스 직접 접근을 통해 탐색 시간을 O(1)로 줄이기 위한 핵심 자료구조
    vector<bool> exist(26, false);

    // 1. 데이터 입력 및 조건 설정
    for(int i = 0; i < N; i++){
        string word;
        cin >> word;
        list[i] = word;
        
        // 단어의 첫 글자를 아스키코드 연산을 이용해 0~25 사이의 인덱스로 변환 후 방문 처리
        exist[word[0] - 'A'] = true;
    }

    // 2. 정답 탐색: 각 단어가 'exist'에 기록된 알파벳들로만 이루어져 있는지 확인
    for(int i = 0; i < N; i++){
        string current = list[i];
        int len = current.length();
        bool is_possible = true;

        for(int j = 0; j < len; j++){
            // 현재 검사 중인 단어의 특정 문자가, 전체 단어들의 '첫 글자 모음(exist)'에 없다면
            if(!exist[current[j] - 'A']){
                is_possible = false;
                break; // 더 이상 검사할 필요가 없으므로 내부 반복문 조기 종료 (최적화)
            }
        }
        
        // 단어의 모든 문자가 조건을 만족했다면
        if(is_possible){
            cout << "Y\n";
            return 0; // 조건을 만족하는 단어를 하나라도 찾았다면 즉시 프로그램 종료
        }
    }
    
    // 모든 단어를 다 확인했는데도 조건을 만족하는 단어가 없다면
    cout << "N\n";

    return 0;
}
