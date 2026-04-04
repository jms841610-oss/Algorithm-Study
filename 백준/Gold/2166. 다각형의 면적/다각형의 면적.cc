#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<long long,long long>> poly(N+1);
    // first : x 좌표, second : y 좌표 

    for(int i=0;i<N;i++){
        cin >> poly[i].first >> poly[i].second;
    }
    poly[N].first = poly[0].first;
    poly[N].second = poly[0].second;

    long long sub = 0;

    for(int i=0;i<N;i++){
        sub += (poly[i].first * poly[i+1].second) - (poly[i+1].first * poly[i].second);
    }
    double ans = abs(sub) * 0.5;

    cout << fixed << setprecision(1);
    cout << ans << "\n";

    return 0;
}