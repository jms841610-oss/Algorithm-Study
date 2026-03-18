#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> arr;

void solve(int depth,int start){
    if(depth==M){
        for(int i=0;i<M;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=start;i<=N;i++){
        arr.push_back(i);
        solve(depth+1,i+1);
        arr.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    solve(0,1);

    return 0;
}