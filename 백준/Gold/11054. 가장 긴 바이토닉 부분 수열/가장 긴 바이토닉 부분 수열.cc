#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> seq(N);
    for(int i=0;i<N;i++){
        cin >> seq[i];
    }
    vector<int> increase(N,1);

    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            int current  = seq[i];
            int possbile = seq[j];

            if(possbile < current){
                int possbile_len = increase[j] + 1;
                int current_len = increase[i];

                increase[i] = max(current_len, possbile_len);
            }
        }
    }
    vector<int> decrease(N,1);

    for(int i=N-2;i>=0;i--){
        for(int j=N-1;j>i;j--){
            int current  = seq[i];
            int possbile = seq[j];

            if(current > possbile){
                int possbile_len = decrease[j] + 1;
                int current_len = decrease[i];

                decrease[i] = max(current_len, possbile_len);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        int now = increase[i] + decrease[i] - 1;
        ans = max(ans, now);
    }
    cout << ans << "\n";
    return 0;
}