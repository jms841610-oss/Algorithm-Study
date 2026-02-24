#include <iostream>
#include <queue>

using namespace std;

struct Time{
    int start;
    int end;

    bool operator<(const Time & other)const{
        if(end==other.end){
            return start > other.start;
        }
        return end > other.end;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
 
    priority_queue<Time> pq;

    for(int i=0;i<N;i++){
        int start,end;
        cin >> start >> end;

        pq.push({start,end});
    }
    int prev_end = 0;
    int cnt = 0;

    while(!pq.empty()){
        Time current = pq.top();
        pq.pop();
        if(current.start >= prev_end){
            cnt++;
            prev_end = current.end;
        }
    }
    cout << cnt << "\n";

    return 0;
}