#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        int n;
        string line;
        cin >> n >> line;

        vector<int> num(n+1);

        for(int i=0;i<=n ;i++){
            num[i] = line[i] - '0';
        }
        int total = 0;
        int friends = 0;

        for(int need=0;need<=n;need++){
            if(num[need] > 0){
                if(need <= total){
                    total += num[need];
                }else{
                    int diff = need - total;
                    friends += diff;
                    total += (diff + num[need]);
                }
            }
        }
        cout << "Case #"<< i+1 << ": " << friends << "\n";
    }
    return 0;
}