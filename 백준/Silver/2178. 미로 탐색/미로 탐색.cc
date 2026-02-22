#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using node = pair<int,int>;

int get_len(vector<vector<int>> &is_movable,int N,int M){
    vector<vector<bool>> is_visited(N,vector<bool>(M,false));
    vector<vector<int>> len(N,vector<int>(M,0));
    queue<node> q;
    
    node start;
    start.first = 0;
    start.second = 0;
    q.push(start);
    is_visited[0][0] = true;
    len[0][0] = 1;

    while(!q.empty()){
        node front = q.front();
        q.pop();

        int front_y = front.first;
        int front_x = front.second;

        if((front_y==N-1)&&(front_x==M-1)) return len[front_y][front_x];

        if((front_y < N-1)&&(is_movable[front_y+1][front_x])&&(!is_visited[front_y+1][front_x])){
            node next;
            next.first = front_y + 1;
            next.second = front_x;
            q.push(next);
            is_visited[front_y+1][front_x] = true;
            len[front_y+1][front_x] = len[front_y][front_x] + 1;
        }
        if((front_x < M-1)&&(is_movable[front_y][front_x+1])&&(!is_visited[front_y][front_x+1])){
            node next;
            next.first = front_y;
            next.second = front_x + 1;
            q.push(next);
            is_visited[front_y][front_x+1] = true;
            len[front_y][front_x+1] = len[front_y][front_x] + 1;
        }
        if((front_y > 0)&&(is_movable[front_y-1][front_x])&&(!is_visited[front_y-1][front_x])){
            node next;
            next.first = front_y - 1;
            next.second = front_x;
            q.push(next);
            is_visited[front_y-1][front_x] = true;
            len[front_y-1][front_x] = len[front_y][front_x] + 1;
        }
        if((front_x > 0)&&(is_movable[front_y][front_x-1])&&(!is_visited[front_y][front_x-1])){
            node next;
            next.first = front_y;
            next.second = front_x - 1;
            q.push(next);
            is_visited[front_y][front_x-1] = true;
            len[front_y][front_x-1] = len[front_y][front_x] + 1;
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    vector<vector<int>> is_movable(N,vector<int>(M));

    for(int row=0;row<N;row++){
        string line;
        cin >> line;
        for(int col=0;col<M;col++){
            is_movable[row][col] = line[col] - '0';
        }
    }
    int min_len = get_len(is_movable,N,M);

    cout << min_len << "\n";

    return 0;
}