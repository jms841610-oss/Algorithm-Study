#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    int N = progresses.size();
    
    for(int i=0;i<N;i++){
        int end = ((100 - progresses[i] - 1) / speeds[i]) + 1 ;
        q.push(end);
    }
    int prev = q.front();
    q.pop();
    int number = 1;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        if(front <= prev){
            number++;
        }else{
            answer.push_back(number);
            number = 1;
            prev = front;
        }
    }
    answer.push_back(number);
    return answer;
}