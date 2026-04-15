#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {  
    vector<int> q; 
    for(int i=0;i<priorities.size();i++){
        q.push_back(i);
    }
    int front_idx = 0;
    int end_idx = priorities.size()-1;
    int cnt = 0;
    
    while(front_idx <= end_idx){
        int front          = q[front_idx];
        int front_priority = priorities[front];
        
        bool is_possible = true;
        for(int i=front_idx+1; i<=end_idx;i++){
            if(priorities[q[i]] > front_priority){
                is_possible = false;
                break;
            }
        }
        if(is_possible){
            front_idx++;
            cnt++;
            
            if(front == location){
                return cnt;
            }
        }else{
            front_idx++;
            q.push_back(front);
            end_idx++;
        }
    }
    return 0;
}