#include <iostream>
#include <vector>

using namespace std;

int row,col;
int matrix_sum = 0;
int matrix_min = 100000;
int matrix_max = -100000;

vector<vector<int>> matrix(50,vector<int>(50,0));

void row_adding(){
    int k,val;
    cin >> k >> val;
    for(int x=0;x<col;x++){
        matrix[k-1][x] += val;
    }
    return;
}
void col_adding(){
    int k,val;
    cin >> k >> val;
    for(int y=0;y<row;y++){
        matrix[y][k-1] += val;
    }
    return;
}
void solving(){
    for(int y=0;y<row;y++){
        for(int x=0;x<col;x++){
            int val = matrix[y][x];
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
        cin >> order;
        if     (order == "row") row_adding();
        else if(order == "col") col_adding();
    }
    solving();

    cout << matrix_sum << " " << matrix_min << " " << matrix_max << endl;

    return 0;
}