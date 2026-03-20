#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;

vector<int> arr;
vector<int> ans;

void solve(int depth,int current){
    if(depth==M){
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    int prev = 0;

    for(int i=0;i<N;i++){
        if((arr[i]>=current)&&(arr[i]!=prev)){
            ans.push_back(arr[i]);
            solve(depth+1,arr[i]);
            ans.pop_back();

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

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());

    solve(0,0);

    return 0;
}