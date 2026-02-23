#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using node = pair<int,int>;

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

void BFS(int height,int width,vector<vector<bool>> &is_able,node start){
    queue<node> q;
    vector<vector<bool>> is_visited(height,vector<bool>(width,false));
    vector<vector<int>> taken_cost(height,vector<int>(width,0));

    q.push(start);
    is_visited[start.first][start.second] = true;
    taken_cost[start.first][start.second] = 0;

    while(!q.empty()){
        node front = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            node next;
            next.first  = front.first  + dy[i];
            next.second = front.second + dx[i];
            
            if((0<=next.first)&&(next.first<height)&&(0<=next.second)&&(next.second<width)){
                if((is_able[next.first][next.second])&&(!is_visited[next.first][next.second])){
                    q.push(next);
                    is_visited[next.first][next.second] = true;
                    taken_cost[next.first][next.second] = taken_cost[front.first][front.second] + 1;
                }
            }
        }
    }
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            if(is_able[row][col]){
                if(is_visited[row][col]) cout << taken_cost[row][col] << " ";
                else                     cout << -1 << " ";
            }else{
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int height,width;
    cin >> height >> width;

    vector<vector<bool>> is_able(height,vector<bool>(width,false));
    node start;

    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            int k;
            cin >> k;
            if(k==1){
                is_able[row][col] = true;
            } else if(k==2){
                start.first  = row;
                start.second = col;
            }
        }
    }
    BFS(height,width,is_able,start);

    return 0;
}