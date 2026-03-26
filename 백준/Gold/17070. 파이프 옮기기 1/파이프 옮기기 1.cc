#include <iostream>
#include <vector>

using namespace std;

int N;
int ans = 0;

vector<vector<int>> area(16,vector<int>(16,0));
vector<vector<bool>> is_visited(16,vector<bool>(16,false));

void DFS(pair<int,int> tail, pair<int,int> head){
    int tail_y = tail.first;
    int tail_x = tail.second;

    int head_y = head.first;
    int head_x = head.second;

    if(((tail_y == N-1)&&(tail_x == N-1))||((head_y == N-1)&&(head_x == N-1))){
        ans++;
        return;
    }
    pair<int,int> front_head = {-1, -1};
    pair<int,int> front_tail = {-1, -1};

    if(tail_x != head_x){
        if((head_y < N)&&(head_x+1 < N)){
            if(area[head_y][head_x+1] != 1){
                if(!is_visited[head_y][head_x+1]){

                is_visited[head_y][head_x+1] = true;

                front_head = {head_y, head_x + 1};
                front_tail = {head_y, head_x};

                DFS(front_tail, front_head);

                is_visited[head_y][head_x+1] = false;
                }
            }
        }
    }
    pair<int,int> down_head = {-1, -1};
    pair<int,int> down_tail = {-1, -1};

    if(tail_y != head_y){
        if((head_y+1 < N)&&(head_x < N)){
            if(area[head_y+1][head_x] != 1){
                if(!is_visited[head_y+1][head_x]){

                is_visited[head_y+1][head_x] = true;

                down_head = {head_y+1, head_x};
                down_tail = {head_y, head_x};

                DFS(down_tail, down_head);

                is_visited[head_y+1][head_x] = false;
                }
            }
        }
    }
    pair<int,int> diag_head = {-1, -1};
    pair<int,int> diag_tail = {-1, -1};

    if((head_y+1 < N)&&(head_x+1 < N)){
        if((area[head_y+1][head_x] != 1)&&(area[head_y][head_x+1] != 1)&&(area[head_y+1][head_x+1] != 1)){
            if(!is_visited[head_y+1][head_x+1]){

                is_visited[head_y+1][head_x+1] = true;

                diag_head = {head_y+1, head_x+1};
                diag_tail = {head_y, head_x};

                DFS(diag_tail, diag_head);

                is_visited[head_y+1][head_x+1] = false;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            cin >> area[y][x];
        }
    }
    pair<int,int> tail = {0,0};
    pair<int,int> head = {0,1};

    DFS(tail, head);

    cout << ans << "\n";
    return 0;
}