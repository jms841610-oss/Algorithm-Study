#include <iostream>
#include <algorithm>

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

            int real_start = max(start,target_start);
            int real_end = min(end, target_end);

            if(real_end >= real_start) ans += (real_end+1 - real_start) * speed;
        }
        cout << "Data Set " << i+1 << ":" << "\n" << ans << "\n" << "\n";
    }
    return 0;
}