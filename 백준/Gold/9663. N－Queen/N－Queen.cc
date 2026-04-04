#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool possible(int y, int x, int N, vector<int> &is_visited){
    bool result = true;

    for(int i=0;i<y;i++){
        int visited_y = i;
        int visited_x = is_visited[i];

        if((visited_x == x)||(abs(x-visited_x) == abs(y-visited_y))){
            result = false;
            break;
        }
    }
    return result;
}
void DFS(int N, int current_y, int &ans, vector<int> &is_visited){
    if(current_y == N){
        ans++;
        return;
    }
    for(int current_x=0;current_x<N;current_x++){
        if(possible(current_y, current_x, N, is_visited)){
            
            is_visited[current_y] = current_x;

            DFS(N, current_y+1, ans, is_visited);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> is_visited(N,0);

    int ans = 0;

    DFS(N, 0, ans, is_visited);

    cout << ans << "\n";
    return 0;
}