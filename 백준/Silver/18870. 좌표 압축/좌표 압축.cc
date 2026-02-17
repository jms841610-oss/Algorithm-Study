#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> sorted_coordinate;
    vector<int> origin_coordinate;

    sorted_coordinate.reserve(N);
    origin_coordinate.reserve(N);

    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        sorted_coordinate.push_back(x);
        origin_coordinate.push_back(x);
    }
    sort(sorted_coordinate.begin(),sorted_coordinate.end());

    auto last = unique(sorted_coordinate.begin(),sorted_coordinate.end());

    sorted_coordinate.erase(last,sorted_coordinate.end());
    
    for(int j=0;j<N;j++){
        int idx = lower_bound(sorted_coordinate.begin(),sorted_coordinate.end(),origin_coordinate[j]) - sorted_coordinate.begin();
        cout << idx << " ";
    }
    return 0;
}