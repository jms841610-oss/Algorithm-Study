#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

void DFS(int current_y, int current_x, int total, int height, int width, int &ans, vector<vector<int>> &area, vector<bool> &is_visited){
    int current = area[current_y][current_x];

    ans = max(ans, total);
    
    for(int i=0;i<4;i++){
        int next_y = current_y + dy[i];
        int next_x = current_x + dx[i];

        if(((0<=next_y)&&(next_y<height))&&((0<=next_x)&&(next_x<width))){
            int next = area[next_y][next_x];

            if(!is_visited[next]){

                is_visited[next] = true;

                DFS(next_y, next_x, total+1, height, width, ans, area, is_visited);

                is_visited[next] = false;
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int height, width;
    cin >> height >> width;

    vector<vector<int>> area(height, vector<int>(width));
    
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            char ch;
            cin >> ch;

            int digit = ch - 'A';
            area[row][col] = digit;
        }
    }
    int ans = 0;
    vector<bool> is_visited(26,false);
    
    int start = area[0][0];
    is_visited[start] = true;

    DFS(0, 0, 1, height, width, ans, area, is_visited);

    cout << ans << "\n";
    return 0;
}