#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q; // 각 작업이 완료되기까지 남은 '일수'를 저장할 큐
    
    int N = progresses.size();
    
    // 1단계: 각 기능이 개발되는데 며칠이 걸리는지 계산하여 큐에 삽입
    for(int i = 0; i < N; i++){
        // 핵심 포인트: 정수 연산만으로 올림(Ceil) 효과 내기
        // (100 - 현재 진도)를 속도로 나누었을 때, 나머지가 있으면 하루가 더 필요함.
        // 분자에 -1을 하고 몫을 구한 뒤 +1을 해주면 깔끔하게 올림 처리가 됨!
        int end = ((100 - progresses[i] - 1) / speeds[i]) + 1;
        q.push(end);
    }
    
    // 2단계: 큐에서 하나씩 꺼내며 함께 배포할 수 있는 기능의 수를 셈
    int prev = q.front(); // 현재 배포 그룹의 기준이 되는 작업의 완료 일수
    q.pop();
    int number = 1; // 이번 배포 때 함께 배포될 기능의 개수 (기준 작업 1개 포함)
    
    while(!q.empty()){
        int front = q.front(); // 다음 작업의 완료 일수
        q.pop();
        
        // 다음 작업이 기준 작업(prev)보다 일찍 또는 동시에 끝난다면?
        if(front <= prev){
            // 기준 작업이 배포될 때까지 기다려야 하므로 함께 배포 (개수 증가)
            number++;
        }
        // 다음 작업이 기준 작업보다 늦게 끝난다면?
        else{
            // 지금까지 모인 작업들을 먼저 배포 (결과 배열에 추가)
            answer.push_back(number);
            
            // 다음 작업이 새로운 배포 그룹의 기준이 됨
            number = 1; 
            prev = front;
        }
    }
    
    // 마지막으로 모여있던 배포 그룹도 잊지 않고 결과 배열에 추가!
    answer.push_back(number);
    
    return answer;
}
