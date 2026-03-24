#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    vector<vector<int>> stable(N+1,vector<int>(N+1,0));
    vector<vector<int>> cum_sum(N+1,vector<int>(N+1,0));

    for(int y=1;y<=N;y++){
        for(int x=1;x<=N;x++){
            cin >> stable[y][x];
        }
    }
    for(int y=1;y<=N;y++){
        for(int x=1;x<=N;x++){
            cum_sum[y][x] = stable[y][x] + cum_sum[y][x-1] + cum_sum[y-1][x] - cum_sum[y-1][x-1];
        }
    }
    for(int i=0;i<M;i++){
        int x1,y1,x2,y2;
        cin >> y1 >> x1 >> y2 >> x2;

        int ans = cum_sum[y2][x2] - (cum_sum[y2][x1-1] + cum_sum[y1-1][x2]) + cum_sum[y1-1][x1-1];

        cout << ans << "\n";
    }
    return 0;
}