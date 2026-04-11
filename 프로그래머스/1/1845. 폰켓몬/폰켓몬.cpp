#include <vector>
#include <unordered_set> // 중복을 허용하지 않는 자료구조를 사용하기 위해 추가

using namespace std;

int solution(vector<int> nums) {
    // 1. 고유한 폰켓몬 종류만 담기 위한 집합(Set) 생성
    // - Set은 맵(Map)과 달리 '값(Value)' 없이 '키(Key)'만 저장합니다.
    // - 중복된 값을 넣으려고 하면 알아서 무시하므로, 종류를 파악할 때 아주 유용합니다.
    unordered_set<int> type;
    
    // 2. 폰켓몬 배열을 처음부터 끝까지 순회합니다.
    for(const int num : nums){
        // Set에 폰켓몬 번호를 넣습니다.
        // 이미 들어있는 번호라면 추가되지 않고, 처음 보는 번호만 추가됩니다.
        type.insert(num);
    }
    
    // 3. 정답 계산 및 반환 (삼항 연산자)
    // - type.size() : 중복이 제거된 '고유한 폰켓몬 종류의 수'
    // - nums.size() / 2 : 내가 '최대로 가져갈 수 있는 마리 수' (전체의 절반)
    //
    // [해석]
    // 폰켓몬 종류(type.size())가 내가 고를 수 있는 마리 수(nums.size()/2)보다 많다면?
    // -> 아무리 다양하게 골라도 최대 마리 수까지만 가져갈 수 있으므로 nums.size()/2가 정답!
    // 그 반대라면?
    // -> 있는 종류를 모두 하나씩 가져갈 수 있으므로 type.size()가 정답!
    int answer = ( type.size() > nums.size()/2 ) ? nums.size()/2 : type.size();
    
    return answer;
}
