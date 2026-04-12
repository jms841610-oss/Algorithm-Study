#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1; // 곱셈을 위해 1로 초기화합니다.
    
    // 1단계: 해시맵을 이용해 종류별 옷의 개수를 셉니다.
    unordered_map<string, int> counts;
    for(const vector<string>& cloth : clothes){
        // cloth[1]은 옷의 종류(type)를 의미합니다.
        counts[cloth[1]]++; 
    }
    
    // 2단계: 각 옷의 종류별로 (옷의 개수 + 안 입는 경우 1)을 곱해줍니다.
    for(auto const& [type, count] : counts){
        answer *= (count + 1);
    }
    
    // 3단계: 모든 종류의 옷을 하나도 입지 않은 경우(1가지)를 빼줍니다.
    return answer - 1;
}
