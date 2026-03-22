#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> x(N);
    vector<long long> y(N);

    for(int i=0;i<N;i++){
        cin >> x[i] >> y[i];
    }
    vector<int> slope(N-1);

    for(int i=0;i<N-1;i++){
        if(y[i] < y[i+1]){
            slope[i] = 1;
        }else if(y[i] > y[i+1]){
            slope[i] = -1;
        }else{
            slope[i] = 0;
        }
    }
    int Q;
    cin >> Q;

    for(int i=0;i<Q;i++){
        double query;
        cin >> query;

        auto it = lower_bound(x.begin(),x.end(),query);
        int idx = it - x.begin() - 1;
        
        cout << slope[idx] << "\n";
    }
    return 0;
}