#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> product(int N, const vector<vector<long long>> &A, const vector<vector<long long>> &B){
    vector<vector<long long>> result(N, vector<long long>(N,0));

    for(int col=0;col<N;col++){
        for(int row=0;row<N;row++){

            for(int x=0;x<N;x++){
                result[col][row] += (A[col][x] * B[x][row]) % 1000;
            }
            result[col][row] %= 1000;
        }
    }
    return result;
}
vector<vector<long long>> solve(int N, long long B, const vector<vector<long long>> &matrix){
    if(B == 1){
        return matrix;
    }
    if(B % 2 == 1){
        return product(N,  solve(N, B-1, matrix), matrix);
    }else{
        vector<vector<long long>> half = solve(N, B/2, matrix);
        return product(N, half, half);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long B;
    cin >> N >> B;

    vector<vector<long long>> matrix(N, vector<long long>(N,0));

    for(int col=0;col<N;col++){
        for(int row=0;row<N;row++){
            long long val;
            cin >> val;
            matrix[col][row] = val % 1000;
        }
    }
    vector<vector<long long>> answer = solve(N, B, matrix);

    for(int col=0;col<N;col++){
        for(int row=0;row<N;row++){
            cout << answer[col][row] << " ";
        }
        cout << "\n";
    }
    return 0;
}