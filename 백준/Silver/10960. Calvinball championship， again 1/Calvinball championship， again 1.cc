#include <iostream>
#include <vector>

using namespace std;

bool is_possible(int target, vector<int> &v, vector<vector<bool>> &hate){
    bool possible = true;

    for(int i=0;i<v.size();i++){
        if(hate[v[i]][target]){
            possible = false;
            break;
        }
    }
    return possible;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<bool>> hate(N+1,vector<bool>(N+1,false));
    vector<bool> is_visited(N+1,false);
    vector<vector<int>> team;

    for(int i=0;i<M;i++){
        int A, B;
        cin >> A >> B;

        hate[A][B] = true;
        hate[B][A] = true;
    }
    for(int i=1;i<=N;i++){
        if(!is_visited[i]){
            vector<int> v;
            v.push_back(i);
            is_visited[i] = true;

            for(int j=1;j<=N;j++){
                if(!is_visited[j]){
                    if(is_possible(j, v, hate)){
                        v.push_back(j);
                        is_visited[j] = true;
                    }
                }
            }
            team.push_back(v);
        }
    }
    cout << team.size() << "\n";

    for(int i=0;i<team.size();i++){
        for(const int& ele : team[i]){
            cout << ele << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}