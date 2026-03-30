#include<vector>
#include<queue>

using namespace std;

const int INF = 2e9;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    int dy[] = {1,0,-1,0};
    int dx[] = {0,1,0,-1};
    
    queue<pair<int,int>> q;
    vector<vector<int>> cost(n,vector<int>(m,INF));
    vector<vector<bool>> is_visited(n,vector<bool>(m,false));
    
    q.push({0,0});
    is_visited[0][0] = true;
    cost[0][0] = 1;
    
    while(!q.empty()){
        pair<int,int> p = q.front();
        
        int current_y = p.first;
        int current_x = p.second;
        int current_cost = cost[current_y][current_x];
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int next_y = current_y + dy[i];
            int next_x = current_x + dx[i];
            
            if(((0<=next_y)&&(next_y<n))&&((0<=next_x)&&(next_x<m))){
                if(maps[next_y][next_x]==1){
                    if(!is_visited[next_y][next_x]){
                    
                        is_visited[next_y][next_x] = true;
                        cost[next_y][next_x] = current_cost + 1;
                        q.push({next_y,next_x});
                    }
                }
                
            }
        }
    }
    int answer = cost[n-1][m-1];
    if(answer == INF) return -1;
    else              return answer;
}