#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    
    int prev = -1;
    
    for(const int ele : arr){
        if(ele != prev){
            q.push(ele);
        }
        prev = ele;
    }
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        answer.push_back(front);
    }
    return answer;
}