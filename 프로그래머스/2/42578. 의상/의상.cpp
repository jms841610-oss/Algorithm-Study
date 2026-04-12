#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> counts;
    set<string> types;
    
    for(const vector<string> &cloth : clothes){
        counts[cloth[1]]++;
        types.insert(cloth[1]);
    }
    for(const string &type : types){
        answer *= counts[type]+1;
    }
    return answer-1;
}