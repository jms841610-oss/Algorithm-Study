#include <iostream>
#include <vector>

using namespace std;

int N,M;

vector<vector<char>> campus(600,vector<char>(600));
vector<vector<bool>> is_visited(600,vector<bool>(600,false));

int cnt = 0;

void visiting(int row,int col){
    if(campus[row][col]=='X') return;
    if(campus[row][col]=='P') cnt++;

    is_visited[row][col] = true;
    
    if((row+1 < N)&&(!is_visited[row+1][col])) visiting(row+1,col);
    if((col+1 < M)&&(!is_visited[row][col+1])) visiting(row,col+1);
    if((row-1 >=0)&&(!is_visited[row-1][col])) visiting(row-1,col);
    if((col-1 >=0)&&(!is_visited[row][col-1])) visiting(row,col-1);

    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    pair<int,int> me;

    for(int row=0;row<N;row++){
        for(int col=0;col<M;col++){
            char info;
            cin >> info;
            campus[row][col] = info;
            if(info=='I'){
                me.first  = row;
                me.second = col;
            }
        }
    }
    visiting(me.first,me.second);

    if(cnt) cout << cnt  << endl;
    else    cout << "TT" << endl;
    
    return 0;
}