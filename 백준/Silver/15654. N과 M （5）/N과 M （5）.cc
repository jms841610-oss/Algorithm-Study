#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N,M;

vector<int> result;
vector<int> arr;
vector<bool> is_used(10001,false);

void solve(int depth,int current){
    if(depth==M){
        for(int i=0;i<result.size();i++){
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }for(int i=0;i<N;i++){
        if(!is_used[arr[i]]){
            result.push_back(arr[i]);
            is_used[arr[i]] = true;

            solve(depth+1,arr[i]);

            result.pop_back();
            is_used[arr[i]] = false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    arr.reserve(N);
    result.reserve(M);

    for(int i=0;i<N;i++){
        int num;
        cin >> num;;

        arr.push_back(num);
    }
    sort(arr.begin(),arr.end());
    
    solve(0,0);

    return 0;
}