#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    string winner;
    cin >> winner;

    string mine;
    cin >> mine;

    int cost_sum = 0;
    int cost = 0;

    for(int i=0;i<n;i++){
        if(winner[i] > mine[i]) cost = (winner[i] - mine[i]) < (26 - (winner[i] - mine[i])) ? (winner[i] - mine[i]) : (26 - (winner[i] - mine[i]));
        else                    cost = (mine[i] - winner[i]) < (26 - (mine[i] - winner[i])) ? (mine[i] - winner[i]) : (26 - (mine[i] - winner[i]));
        cost_sum += cost;
    }
    cout << cost_sum << "\n";

    return 0;
}