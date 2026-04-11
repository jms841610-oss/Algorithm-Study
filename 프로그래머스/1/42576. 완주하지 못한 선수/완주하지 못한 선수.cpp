#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_multimap<string, bool> is_completion;
    
    for(const string &p : participant){
        is_completion.insert({p, false});
    }
    for(const string &c : completion){
       auto range = is_completion.equal_range(c);
        
        for(auto it=range.first;it!=range.second;it++){
            if(!(it->second)){
                (it->second) = true;
                break;
            }
        }
    }
    for(const string &p : participant){
        auto range = is_completion.equal_range(p);
        
        for(auto it=range.first;it!=range.second;it++){
            if(!(it->second)){
                return (it->first);
            }
        }
    }
}