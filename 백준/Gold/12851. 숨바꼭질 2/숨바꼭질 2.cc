#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef struct{
    int cost = INT_MAX;
    int num  = 0;
}END;

void BFS(const int start, const int end, vector<END> &end_list){
    queue<pair<int,int>> q; // 최소비용, 현재 정점
    q.push({0, start});

    end_list[start].cost = 0;
    end_list[start].num  = 1;

    while(!q.empty()){
        int front      = q.front().second;
        int front_cost = q.front().first;
        q.pop();

        int next[] = {front+1, front-1, front*2};

        for(int i=0;i<3;i++){
            if((0<=next[i])&&(next[i]<=100000)){

                if(end_list[next[i]].cost == front_cost + 1){
                    end_list[next[i]].num += end_list[front].num;

                }else if(end_list[next[i]].cost > front_cost + 1){
                    end_list[next[i]].cost =  front_cost + 1;
                    end_list[next[i]].num  = end_list[front].num;
                    q.push({end_list[next[i]].cost, next[i]});
                }
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int start, end;
    cin >> start >> end;

    vector<END> end_list(100001);

    BFS(start, end, end_list);

    cout << end_list[end].cost << "\n";
    cout << end_list[end].num  << "\n";
    return 0;
}