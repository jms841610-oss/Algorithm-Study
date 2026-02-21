#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        unordered_map<int,int> freq;
        vector<int> comulative(11);

        for(int i=1;i<10;i++){
            int num;
            cin >> num;
            freq[i] = num;
        }
        freq[9] += freq[6];
        freq[6] = 0;
        
        int total = 0;

        for(int i=9;i>0;i--){
            total += freq[i];
            comulative[i] = total;
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

                while(comulative[card]<=cnt){
                    card--;
                }
                ans[idx] = card;
            }else{
                idx = (total-1) - cnt/2;
                is_left = true;

                while(comulative[card]<=cnt){
                    card--;
                }
                ans[idx] = card;
            }
            cnt++;
        }
        for(int i=0;i<total;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}