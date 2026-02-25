#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

struct Tomato{
    int y;
    int x;
};
void BFS(vector<vector<int>> &tomato_status,int length,int width){
    queue<Tomato> q;

    int unriped_tomato = 0;

    for(int row=0;row<length;row++){
        for(int col=0;col<width;col++){
            if(tomato_status[row][col]==1){
                q.push({row,col});
            }
            if(tomato_status[row][col]==0){
                unriped_tomato++;
            }
        }
    }
    int max_cost = 1;

    while(!q.empty()){
        Tomato current = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int next_row = current.y + dy[i];
            int next_col = current.x + dx[i];

            if((0<=next_row)&&(next_row<length)&&(0<=next_col)&&(next_col<width)){

                if(tomato_status[next_row][next_col]==0){
                    unriped_tomato--;
                    tomato_status[next_row][next_col] = tomato_status[current.y][current.x] + 1;
                    max_cost = max(max_cost,tomato_status[next_row][next_col]);
                    q.push({next_row,next_col});
                }
            }
        }
    }
    if(unriped_tomato>0) cout << "-1\n";
    else                 cout << max_cost-1 << "\n";

    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int width,length;
    cin >> width >> length;

    vector<vector<int>> tomato_status(length,vector<int>(width));

    for(int row=0;row<length;row++){
        for(int col=0;col<width;col++){
            int status;
            cin >> status;
            tomato_status[row][col] = status;
        }
    }
    BFS(tomato_status,length,width);

    return 0;
}