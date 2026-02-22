#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<vector<bool>> is_house(25,vector<bool>(25,false));
vector<vector<bool>> is_visited(25,vector<bool>(25,false));
vector<int> house_num;

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

void visiting(int row,int col,int* num){
    is_visited[row][col] = true;
    (*num)++;

    for(int i=0;i<4;i++){
        int next_y = row + dy[i];
        int next_x = col + dx[i];

        if((0 <= next_y)&&(next_y < N)&&(0 <= next_x)&&(next_x < N)){
            if((!is_visited[next_y][next_x])&&(is_house[next_y][next_x])){
                visiting(next_y,next_x,num);
            }
        }
    }
    return;
}
void get_num(){
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            if((is_house[row][col])&&(!is_visited[row][col])){
                int num = 0;
                visiting(row,col,&num);
                house_num.push_back(num);
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int row=0;row<N;row++){
        string line;
        cin >> line;

        for(int col=0;col<N;col++){
            if(line[col] == '1') is_house[row][col] = true;
        }
    }
    get_num();

    sort(house_num.begin(),house_num.end());

    cout << house_num.size() << "\n";

    for(int i=0;i<house_num.size();i++){
        cout << house_num[i] << "\n";
    }
    return 0;
}