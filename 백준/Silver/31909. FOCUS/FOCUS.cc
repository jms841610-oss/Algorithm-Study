#include <iostream>
#include <vector>

using namespace std;

pair<int,int> interpret(int A){
    for(int B=0;B<=7;B++){
        for(int C=0;C<=7;C++){
            if(A == ((1 << B) + (1 << C))){
                return {B,C};
            }
        }
    }
    return {-1,-1};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> order(N+1);
    vector<int> idx(8);

    for(int i=0;i<=7;i++){
        idx[i] = i;
    }
    for(int i=0;i<N;i++){
        int order;
        cin >> order;
        pair<int,int> interpreted = interpret(order);

        if(interpreted.first != -1){
            int tmp = idx[interpreted.first];
            idx[interpreted.first] = idx[interpreted.second];
            idx[interpreted.second] = tmp;
        }
    }
    int target;
    cin >> target;

    cout << idx[target] << "\n";
    return 0;
}