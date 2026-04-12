#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> us(phone_book.begin(), phone_book.end());
    
    for(const string &phone_number : phone_book){
        string prefix = "";
        
        for(int idx=0;idx<phone_number.length()-1;idx++){
            prefix.push_back(phone_number[idx]);
            
            if(us.count(prefix)){
                return false;
            }
        }
    }
    return true;
}