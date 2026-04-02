#include <iostream>
#include <vector>

using namespace std;

void star(pair<int,int> &pos, vector<vector<bool>> &is_star){
    int y = pos.first;
    int x = pos.second;

    is_star[y][x] = true;

    is_star[y+1][x-1] = true; 
    is_star[y+1][x+1] = true;

    is_star[y+2][x-2] = true;
    is_star[y+2][x-1] = true;
    is_star[y+2][x  ] = true;
    is_star[y+2][x+1] = true;
    is_star[y+2][x+2] = true;

    return;
}
void solve(int height, pair<int,int> pos, vector<vector<bool>> &is_star){
    if(height==3){
        star(pos, is_star);
        return;
    }
    int y = pos.first;
    int x = pos.second;

    pair<int,int> top = {y,x};
    solve(height/2, top, is_star);

    pair<int,int> left = {y + height/2, x - height/2};
    solve(height/2, left, is_star);

    pair<int,int> right = {y + height/2, x + height/2};
    solve(height/2, right, is_star);

    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<bool>> is_star(N,vector<bool>(N*2,false));
    pair<int,int> top = {0,N-1};

    solve(N, top, is_star);

    for(int row=0;row<N;row++){
        for(int col=0;col<N*2;col++){
            if(is_star[row][col]){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}