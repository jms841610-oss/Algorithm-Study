#include <iostream>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<double> arr(N);

    for(int i=0;i<N;i++){
        double input;
        cin >> input;
        arr[i] = input;
    }
    double current_max = arr[0];
    double total_max   = arr[0];

    for(int i=1;i<N;i++){
        current_max = max(current_max*arr[i],arr[i]);
        total_max   = max(total_max,current_max);
    }
    cout << fixed << setprecision(3);

    cout << total_max << "\n";

    return 0;
}