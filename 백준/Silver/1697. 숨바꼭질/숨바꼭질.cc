#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> is_visited(100001,false);
vector<int> dis(100001,0);
queue<int> q;

int get_cnt(int N,int K){
    q.push(N);
    is_visited[N] = true;
    dis[N] = 0;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        if(front==K) return dis[front];

        if((front>0)&&(!is_visited[front-1])){
            q.push(front-1);
            is_visited[front-1] = true;
            dis[front-1] = dis[front] + 1;
        }
        if((front<100000)&&(!is_visited[front+1])){
            q.push(front+1);
            is_visited[front+1] = true;
            dis[front+1] = dis[front] + 1;
        }
        if((front<50001)&&(!is_visited[front*2])){
            q.push(front*2);
            is_visited[front*2] = true;
            dis[front*2] = dis[front] + 1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin >> N >> K;

    int min_cnt = get_cnt(N,K);

    cout << min_cnt << "\n";

    return 0;
}