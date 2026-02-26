#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    // 입출력 속도 향상을 위한 C++ 표준 스트림 동기화 해제
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 후보자별 득표수를 저장하는 Hash Table 기반의 컨테이너
    // Key: 후보자 이름(string), Value: 득표수(int)
    // Red-Black Tree 기반의 map과 달리 정렬을 수행하지 않아 탐색/삽입이 평균 O(1)로 매우 빠름
    unordered_map<string,int> votes;

    // 최다 득표수를 실시간으로 추적하기 위한 변수
    int max_votes = 0;

    // 투표 입력 처리 루프
    while(true){
        string name;

        // 공백이 포함된 이름도 온전히 입력받기 위해 getline 사용
        getline(cin,name);

        // 종료 조건: "***" 입력 시 루프 탈출
        if(name == "***") break;

        // 해시 함수를 거쳐 메모리 주소(버킷)로 바로 접근하여 득표수 1 증가
        // 존재하지 않는 키인 경우 자동으로 0으로 초기화된 후 ++ 연산이 적용됨
        votes[name]++;

        // 현재 후보자의 득표수와 기존 최대 득표수를 비교하여 최댓값 갱신
        max_votes = max(max_votes,votes[name]);
    }
    
    string candidate = ""; // 당선자 이름을 임시로 저장할 변수
    int cnt = 0;           // 최다 득표자의 '수'를 카운트할 변수

    // 해시 테이블에 저장된 모든 후보자를 순회
    // 데이터가 정렬되어 있지 않고, 해시 버킷에 저장된 순서대로 순회함
    for(const auto &pair : votes){
        if(pair.second==max_votes){
            candidate = pair.first; // 최다 득표자 이름 저장
            cnt++;                  // 최다 득표자 수 증가
        }
    }

    // 최다 득표자가 단 1명인 경우 당선자 출력
    if(cnt==1){
        cout << candidate << "\n";
    }else{
        // 최다 득표자가 2명 이상인 경우 동점이므로 재투표(Runoff) 출력
        cout << "Runoff!\n";
    }
    
    return 0;
}
