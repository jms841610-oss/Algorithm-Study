#include <iostream>
#include <vector>

using namespace std;

int max_sum = 0;
int height,width;

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

vector<vector<int>> score(500,vector<int>(500));
vector<vector<bool>> is_visited(500,vector<bool>(500,false));

void DFS(int row,int col,int depth,int current_sum){
    if(depth==4){
        max_sum = max(max_sum,current_sum);
        return;
    }
    for(int i=0;i<4;i++){
        int next_row = row + dy[i];
        int next_col = col + dx[i];

        if((0<=next_row)&&(next_row<height)&&(0<=next_col)&&(next_col<width)){

            if(!is_visited[next_row][next_col]){

                if(depth==2){
                    is_visited[next_row][next_col] = true;
                    DFS(row,col,depth+1,current_sum+score[next_row][next_col]);
                    is_visited[next_row][next_col] = false;
                }
                is_visited[next_row][next_col] = true;
                DFS(next_row,next_col,depth+1,current_sum+score[next_row][next_col]);
                is_visited[next_row][next_col] = false;               
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> height >> width;

    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            int input;
            cin >> input;
            score[row][col] = input;
        }
    }
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            is_visited[row][col] = true;
            
            int depth = 1;
            int current_sum = score[row][col];
            
            DFS(row,col,depth,current_sum);
            is_visited[row][col] = false;
        }
    }    
    cout << max_sum << "\n";

    return 0;
}