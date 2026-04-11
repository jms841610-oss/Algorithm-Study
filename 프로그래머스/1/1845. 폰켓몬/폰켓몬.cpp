#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums) {
    int N_of_type = 0;
    
    unordered_map<int, int> counts;
    // type, count
    for(const int num : nums){
        counts[num]++;
    }
    for(auto [type, count] : counts){
        N_of_type++;
    }
    int answer = (N_of_type > nums.size()/2) ? nums.size()/2 : N_of_type;
    return answer;
}