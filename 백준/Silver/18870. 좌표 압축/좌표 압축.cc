#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;

vector<int> sorted_coordinate;
map<int,int> compression;

void compressing(){
    int comulative_sum = 0;

    sort(sorted_coordinate.begin(),sorted_coordinate.end());
    
    compression[sorted_coordinate[0]] = comulative_sum;

    for(int i=1;i<N;i++){
        if(sorted_coordinate[i] > sorted_coordinate[i-1]){
            comulative_sum++;
            compression[sorted_coordinate[i]] = comulative_sum;
        }
    }
    return;
}
int main(){
    cin >> N;
    
    vector<int> origin_coordinate;

    sorted_coordinate.reserve(N);
    origin_coordinate.reserve(N);

    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        sorted_coordinate.push_back(x);
        origin_coordinate.push_back(x);
    }
    compressing();

    for(int j=0;j<N;j++){
        int result = compression[origin_coordinate[j]];
        cout << result << " ";
    }
    cout << endl;

    return 0;
}