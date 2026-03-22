#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<long long> x(N);
    vector<long long> y(N);

    for(int i=0;i<N;i++){
        cin >> x[i] >> y[i];
    }
    
    // slope 배열의 크기는 N-1 입니다.
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

        // query보다 엄격하게 큰 첫 번째 원소의 반복자를 찾습니다.
        auto it = upper_bound(x.begin(), x.end(), query);
        
        // it가 x.begin()이거나 x.end()이면 유효한 구간을 벗어난 것입니다.
        if(it != x.begin() && it != x.end()){
            // 올바른 구간의 인덱스를 얻기 위해 1을 빼줍니다.
            int idx = (it - x.begin()) - 1; 
            
            // 이제 안전하게 slope 배열에 접근할 수 있습니다.
            cout << slope[idx] << "\n";
        }
    }
    return 0;
}
