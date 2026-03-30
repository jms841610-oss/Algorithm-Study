#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;

    for(int i=0;i<K;i++){
        int P;
        cin >> P;

        int target_start, target_end;
        cin >> target_start >> target_end;       

        int ans = 0;

        for(int j=0;j<P;j++){
            int start, end, speed;
            cin >> start >> end >> speed;

            if((target_start <= end+1)&&(end+1 <= target_end)){
                if(target_start <= start){
                    ans += (end+1 - start) * speed;
                }else{
                    ans += (end+1 - target_start) * speed;
                }
            }else if(target_end < end+1){
                if((target_start <= start)&&(start <= target_end)){
                    ans += (target_end+1 - start) * speed;
                }else if(start < target_start){
                    ans += (target_end+1 - target_start) * speed;
                }
            }
        }
        cout << "Data Set " << i+1 << ":" << "\n" << ans << "\n" << "\n";
    }
    return 0;
}