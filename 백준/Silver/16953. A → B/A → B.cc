#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using node = pair<long long,long long>;

int A,B;

queue<node> order;

void BFS(){
    node start;
    start.first = A;
    start.second = 1;

    order.push(start);

    while(!order.empty()){
        node front = order.front();
        order.pop();

        if(front.first==B){
            cout <<  front.second << "\n";
            return;
        }
        vector<long long> cal(2);

        cal[0] = front.first * 2;
        cal[1] = front.first * 10 + 1;

        for(int i=0;i<2;i++){
            if(cal[i]<=B){
                node next;
                next.first = cal[i];
                next.second = front.second + 1;

                order.push(next);
            }
        }
    }
    cout << -1 << "\n";
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B;

    BFS();

    return 0;
}