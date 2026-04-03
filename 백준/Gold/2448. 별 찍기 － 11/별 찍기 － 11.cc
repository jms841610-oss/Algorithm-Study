#include <iostream>
#include <vector>

using namespace std;

// [1] 가장 작은 단위의 삼각형(높이 3)을 그리는 함수
void star(pair<int,int> &pos, vector<vector<bool>> &is_star){
    int y = pos.first;  // 현재 삼각형 꼭짓점의 y 좌표 (행)
    int x = pos.second; // 현재 삼각형 꼭짓점의 x 좌표 (열)

    // 첫 번째 줄: 맨 위 꼭짓점 별 1개
    is_star[y][x] = true;

    // 두 번째 줄: 양쪽 대각선 별 2개
    is_star[y+1][x-1] = true; 
    is_star[y+1][x+1] = true;

    // 세 번째 줄: 밑변 별 5개 (가운데 빈 공간 없이 모두 채움)
    is_star[y+2][x-2] = true;
    is_star[y+2][x-1] = true;
    is_star[y+2][x  ] = true;
    is_star[y+2][x+1] = true;
    is_star[y+2][x+2] = true;

    return;
}

// [2] 재귀를 통해 큰 삼각형을 3개의 작은 삼각형으로 쪼개는 함수
void solve(int height, pair<int,int> pos, vector<vector<bool>> &is_star){
    // 기저 조건 (Base Condition): 삼각형의 높이가 3이 되면 더 이상 쪼개지 않고 별을 그립니다.
    if(height == 3){
        star(pos, is_star);
        return;
    }
    
    int y = pos.first;
    int x = pos.second;

    // 분할 정복 (Divide and Conquer):
    // 높이가 3보다 크다면, 현재 높이를 절반(height/2)으로 줄여서 3개의 작은 삼각형으로 나눕니다.

    // 1. 위쪽 작은 삼각형: 꼭짓점의 위치가 변하지 않습니다.
    pair<int,int> top = {y, x};
    solve(height/2, top, is_star);

    // 2. 왼쪽 아래 작은 삼각형: y좌표는 절반만큼 아래로 내려가고, x좌표는 절반만큼 왼쪽으로 이동합니다.
    pair<int,int> left = {y + height/2, x - height/2};
    solve(height/2, left, is_star);

    // 3. 오른쪽 아래 작은 삼각형: y좌표는 절반만큼 아래로 내려가고, x좌표는 절반만큼 오른쪽으로 이동합니다.
    pair<int,int> right = {y + height/2, x + height/2};
    solve(height/2, right, is_star);

    return;
}

int main(){
    // C++ 입출력 속도 향상을 위한 필수 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N; // 전체 높이 N 입력 (N은 3 * 2^k 형태)

    // 별의 유무를 저장할 2차원 배열 생성 (모든 값을 공백 처리를 위해 false로 초기화)
    // - 행의 수: 높이 N
    // - 열의 수: 가장 밑변의 길이가 대략 N*2 이므로 넉넉하게 N*2로 설정
    vector<vector<bool>> is_star(N, vector<bool>(N*2, false));
    
    // 가장 처음 시작하는 전체 삼각형 꼭짓점의 위치
    // - 첫 번째 행(0)의 한가운데(N-1)에서 시작합니다.
    pair<int,int> top = {0, N-1};

    // 재귀 함수 시작
    solve(N, top, is_star);

    // 배열을 순회하며 true인 곳에는 별(*)을, false인 곳에는 공백( )을 출력합니다.
    for(int row = 0; row < N; row++){
        for(int col = 0; col < N*2; col++){
            if(is_star[row][col]){
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n"; // 한 행을 다 출력하면 줄바꿈
    }

    return 0;
}
