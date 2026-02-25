#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tomato{
    int flr,row,col;
};

int dz[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dx[] = {0,0,0,0,1,-1};

void BFS(vector<vector<vector<int>>> &tomato_status,int height,int length,int width){
    queue<Tomato> q;
    vector<vector<vector<bool>>> is_visited(height,vector<vector<bool>>(length,vector<bool>(width,false)));
    vector<vector<vector<int>>> cost(height,vector<vector<int>>(length,vector<int>(width,0)));

    int unriped_tomato = 0;

    for(int flr=0;flr<height;flr++){
        for(int row=0;row<length;row++){
            for(int col=0;col<width;col++){
                if(tomato_status[flr][row][col]==1){
                    q.push({flr,row,col});
                }else if(tomato_status[flr][row][col]==0){
                    unriped_tomato++;
                }
            }
        }
    }
    int max_cost = 0;

    while(!q.empty()){
        Tomato current = q.front();
        q.pop();
        
        int current_flr = current.flr;
        int current_row = current.row;
        int current_col = current.col;

        max_cost = max(max_cost,cost[current_flr][current_row][current_col]);

        for(int i=0;i<6;i++){
            Tomato next_tomato;

            next_tomato.flr = current_flr + dz[i];
            next_tomato.row = current_row + dy[i];
            next_tomato.col = current_col + dx[i];
            
            if(((0<=next_tomato.flr)&&(next_tomato.flr<height))&&((0<=next_tomato.row)&&(next_tomato.row<length))&&((0<=next_tomato.col)&&(next_tomato.col<width))){

                if((!is_visited[next_tomato.flr][next_tomato.row][next_tomato.col])&&(tomato_status[next_tomato.flr][next_tomato.row][next_tomato.col]==0)){

                    q.push(next_tomato);
                    cost[next_tomato.flr][next_tomato.row][next_tomato.col] = cost[current_flr][current_row][current_col] + 1;
                    is_visited[next_tomato.flr][next_tomato.row][next_tomato.col] = true;
                    unriped_tomato--;
                }
            }
        }
    }
    if(unriped_tomato > 0) cout << "-1\n";
    else                   cout << max_cost << "\n";

    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int width,length,height;
    cin >> width >> length >> height;

    vector<vector<vector<int>>> tomato_status(height,vector<vector<int>>(length,vector<int>(width)));

    for(int flr=0;flr<height;flr++){
        for(int row=0;row<length;row++){
            for(int col=0;col<width;col++){
                int status;
                cin >> status;
                tomato_status[flr][row][col] = status;
            }
        }
    }
    BFS(tomato_status,height,length,width); 

    return 0;
}