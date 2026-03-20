#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;

vector<int> arr;
vector<int> ans;
vector<bool> is_visited;

void solve(int depth,int current_idx){
    if(depth==M){
        for(int i=0;i<M;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    int prev = 0;

    for(int i=0;i<arr.size();i++){
        if((!is_visited[i])&&(prev!=arr[i])){
            ans.push_back(arr[i]);
            is_visited[i] = true;

            solve(depth+1,i);

            ans.pop_back();
            is_visited[i] = false;

            prev = arr[i];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    arr.assign(N,0);
    ans.reserve(N);
    is_visited.assign(N,false);

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());

    solve(0,-1);

    return 0;
}