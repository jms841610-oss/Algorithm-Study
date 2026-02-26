#include <iostream>
#include <queue>

using namespace std;

int BFS(int move[]){
    bool is_visited[101] = {false};
    int cost [101] = {0};
    queue<int> order;

    order.push(1);
    is_visited[1] = true;
    cost[1] = 0;

    while(!order.empty()){
        int current = order.front();
        order.pop();

        if(current==100){
            return cost[current];
        }
        for(int dice=1;dice<=6;dice++){
            int next = current + dice;
            int final_val = move[next];
            if((final_val <= 100)&&(!is_visited[final_val])){
                order.push(final_val);
                is_visited[final_val] = true;
                cost[final_val] = cost[current] + 1;
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    int move[101];

    for(int i=1;i<=100;i++){
        move[i] = i;
    }
    for(int i=0;i<N+M;i++){
        int start,goal;
        cin >> start >> goal;
        move[start] = goal;
    }
    int min_cnt = BFS(move);

    cout << min_cnt << "\n";

    return 0;
}