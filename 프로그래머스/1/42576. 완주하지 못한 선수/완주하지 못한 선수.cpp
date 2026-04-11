#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    // 1. 참가자 이름과 해당 이름의 등장 횟수를 저장할 해시맵 생성
    // - Key(string): 참가자 이름
    // - Value(int): 해당 이름을 가진 참가자의 수 (동명이인 처리용)
    unordered_map<string, int> counts;
    
    // 2. participant 배열을 순회하며 모든 참가자를 맵에 기록
    // - 이름이 맵에 없으면 1로 초기화되고, 동명이인이면 값이 증가(+1)합니다.
    for(const string &p : participant){
        counts[p]++;
    }
    
    // 3. completion 배열을 순회하며 완주한 사람을 맵에서 제외
    // - 완주자의 이름이 나올 때마다 해당 이름의 카운트를 감소(-1)시킵니다.
    for(const string &c : completion){
        counts[c]--;
    }
    
    // 4. counts 맵을 순회하며 완주하지 못한 단 한 사람을 탐색
    // - 완주한 사람은 카운트가 0이 되었을 것이고, 
    //   완주하지 못한 1명만 카운트가 1(또는 그 이상)로 남아있게 됩니다.
    for(const auto &[name, count] : counts){
        if(count > 0){
            return name; // 카운트가 남아있는 사람이 바로 미완주자!
        }
    }
    
    // 5. 예외 처리
    // - 문제 조건상 무조건 미완주자가 1명 존재하므로 여기까지 올 일은 없지만,
    //   모든 제어 경로에서 반환값을 가지도록 기본값을 리턴합니다.
    return "0"; 
}
