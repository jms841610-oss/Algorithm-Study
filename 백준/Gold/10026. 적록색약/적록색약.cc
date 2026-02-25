#include <iostream>
#include <vector>

using namespace std;

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

void DFS(vector<string> &color,int row,int col,vector<vector<bool>> &is_visited,int N){
    is_visited[row][col] = true;
    char current = color[row][col]; 

    for(int i=0;i<4;i++){
        int next_y = row + dy[i];
        int next_x = col + dx[i];

        if((0<=next_y)&&(next_y<N)&&(0<=next_x)&&(next_x<N)){
            if((!is_visited[next_y][next_x])&&(current==color[next_y][next_x])){
                DFS(color,next_y,next_x,is_visited,N);
            }
        }
    }
    return;
}
void blind_DFS(vector<string> &blind_color,int row,int col,vector<vector<bool>> &blind_is_visited,int N){
    blind_is_visited[row][col] = true;
    char current = blind_color[row][col]; 

    for(int i=0;i<4;i++){
        int next_y = row + dy[i];
        int next_x = col + dx[i];

        if((0<=next_y)&&(next_y<N)&&(0<=next_x)&&(next_x<N)){
            if(!blind_is_visited[next_y][next_x]){

                if(((current=='R')||(current=='G'))&&((blind_color[next_y][next_x]=='R')||(blind_color[next_y][next_x]=='G'))){
                    blind_is_visited[next_y][next_x] = true;
                    blind_DFS(blind_color,next_y,next_x,blind_is_visited,N);

                }else if((current=='B')&&(blind_color[next_y][next_x]=='B')){
                    blind_is_visited[next_y][next_x] = true;
                    blind_DFS(blind_color,next_y,next_x,blind_is_visited,N);
                }
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<string> color(N);
    vector<string> blind_color(N);

    for(int row=0;row<N;row++){
        string line;
        cin >> line;
        color[row] = line;
        blind_color[row] = line;
    }
    vector<vector<bool>> is_visited(N,vector<bool>(N,false));
    vector<vector<bool>> blind_is_visited(N,vector<bool>(N,false));

    int cnt = 0;
    int blind_cnt = 0;

    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            if(!is_visited[row][col]){
                DFS(color,row,col,is_visited,N);
                cnt++;
            }
        }
    }
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            if(!blind_is_visited[row][col]){
                blind_DFS(blind_color,row,col,blind_is_visited,N);
                blind_cnt++;
            }
        }
    }
    cout << cnt << " " << blind_cnt << "\n";

    return 0;
}