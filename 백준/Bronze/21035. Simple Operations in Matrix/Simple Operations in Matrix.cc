#include <iostream>
#include <vector>

using namespace std;

int row,col;
int matrix_sum = 0;
int matrix_min = 100000;
int matrix_max =-100000;

vector<vector<int>> matrix(50,vector<int>(50,0));
vector<int> row_add(50,0);
vector<int> col_add(50,0);

void solving(){
    for(int y=0;y<row;y++){
        for(int x=0;x<col;x++){
            int val = matrix[y][x] + row_add[y] + col_add[x];
            matrix_sum += val;
            matrix_min = min(matrix_min,val);
            matrix_max = max(matrix_max,val);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> row >> col;

    for(int y=0;y<row;y++){
        for(int x=0;x<col;x++){
            int val;
            cin >> val;
            matrix[y][x] = val;
        }
    }
    int Q;
    cin >> Q;

    for(int i=0;i<Q;i++){
        string order;
        int k,val;
        cin >> order >> k >> val;
        if     (order == "row") row_add[k-1] += val;
        else if(order == "col") col_add[k-1] += val;
    }
    solving();

    cout << matrix_sum << " " << matrix_min << " " << matrix_max << endl;

    return 0;
}