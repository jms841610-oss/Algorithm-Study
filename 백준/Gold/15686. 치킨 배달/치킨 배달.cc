#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int ans = 2e9;

void DFS(int depth, int start, int M, vector<pair<int,int>> depart, vector<pair<int,int>> &arr, vector<pair<int,int>> &arrive){
    if(depth == M){
        int tmp_sum = 0;
        for(const auto& d : depart){
            int tmp = 2e9;
            for(const auto& c : arr){
                int total = abs(c.first - d.first) + abs(c.second - d.second);
                tmp = min(tmp, total);
            }
            tmp_sum += tmp;
        }
        ans = min(ans, tmp_sum);
        return;
    }
    for(int i=start;i<arrive.size();i++){
        arr.push_back(arrive[i]);

        DFS(depth+1, i+1, M, depart, arr, arrive);
 
        arr.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<pair<int,int>> depart;
    vector<pair<int,int>> arrive;

    vector<pair<int,int>> arr;
    vector<vector<pair<int,int>>> candidate;

    depart.reserve(N*N);
    arrive.reserve(N*N);

    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            int input;
            cin >> input;

            if(input == 1){
                depart.push_back({y,x});
            }else if(input == 2){
                arrive.push_back({y,x});
            }
        }
    }
    DFS(0, 0, M, depart, arr, arrive);

    cout << ans << "\n";
    return 0;
}