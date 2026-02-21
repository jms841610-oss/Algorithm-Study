#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        vector<int> freq(10);
        vector<int> comulative(10);

        for(int j=1;j<10;j++){
            int num;
            cin >> num;
            freq[j] = num;
        }
        freq[9] += freq[6];
        freq[6] = 0;
        
        int total = 0;

        for(int k=9;k>0;k--){
            total += freq[k];
            comulative[k] = total;
        }
        int card = 9;
        int idx = 0;
        int cnt = 0;
        
        bool is_left = true;

        vector<int> ans(total);

        while(cnt!=total){
            if(is_left){
                idx = 0 + cnt/2;
                is_left = false;
            }else{
                idx = (total-1) - cnt/2;
                is_left = true;
            }
            while(comulative[card]<=cnt){
                card--;
            }
            ans[idx] = card;
            cnt++;
        }
        for(int i=0;i<total;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}