#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    // 1. 모든 전화번호를 해시 셋(Hash Set)에 저장합니다.
    // unordered_set을 사용하면 어떤 전화번호가 존재하는지 검색할 때 O(1)의 매우 빠른 속도로 찾을 수 있습니다.
    unordered_set<string> us(phone_book.begin(), phone_book.end());
    
    // 2. 전화번호부의 모든 전화번호를 하나씩 꺼내어 검사합니다.
    for(const string &phone_number : phone_book){
        string prefix = ""; // 현재 전화번호의 접두어를 한 글자씩 만들어갈 빈 문자열을 준비합니다.
        
        // 3. 현재 전화번호의 처음부터 '끝에서 두 번째 문자'까지만 반복합니다.
        // length() - 1 까지만 반복하는 이유: 자기 자신과 완전히 동일한 문자열은 접두어로 취급하지 않기 위해서입니다.
        for(int idx = 0; idx < phone_number.length() - 1; idx++){
            // 문자를 하나씩 이어 붙이면서 접두어(prefix)를 조각조각 만듭니다.
            // 예: "119"라면 "1", "11" 순서로 만들어집니다.
            prefix.push_back(phone_number[idx]);
            
            // 4. 방금 만든 접두어가 해시 셋(us)에 독립적인 전화번호로 존재하는지 확인합니다.
            // us.count(prefix)는 셋 안에 해당 문자열이 있으면 1, 없으면 0을 반환합니다.
            if(us.count(prefix) > 0){
                // 만약 존재한다면, 다른 누군가의 전화번호가 현재 번호의 접두어라는 의미이므로 즉시 false를 반환합니다.
                return false;
            }
        }
    }
    // 5. 모든 전화번호의 접두어를 검사했는데도 겹치는 것이 없다면, 접두어 관계가 없다는 뜻이므로 true를 반환합니다.
    return true;
}
