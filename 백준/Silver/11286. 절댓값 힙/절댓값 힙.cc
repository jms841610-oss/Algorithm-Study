#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct absolute_smaller{
    bool operator()(const int a,const int b) const{
        if(abs(a)==abs(b)){
            return a>b;
        }
        return abs(a) > abs(b);
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    priority_queue<int,vector<int>,absolute_smaller> pq;

    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        if(x==0){
            if(!pq.empty()){
                int top_val = pq.top();
                pq.pop();
                cout << top_val << "\n";
            }else{
                cout << 0 << "\n";
            }
        }else{
            pq.push(x);
        }
    }
    return 0;
}