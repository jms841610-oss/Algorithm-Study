#include <iostream>
#include <vector>

using namespace std;

// [1] 가장 작은 기본 단위의 별(높이 3)을 그리는 함수
// 기준이 되는 최상단 꼭짓점 좌표(pos)를 받아서 별을 찍어줍니다.
void star(pair<int,int> &pos, vector<vector<bool>> &is_star){
    int y = pos.first;  // 기준점의 y 좌표
    int x = pos.second; // 기준점의 x 좌표

    // 첫 번째 줄: 꼭짓점 별 1개
    is_star[y][x] = true;

    // 두 번째 줄: 양 옆으로 벌어진 별 2개
    is_star[y+1][x-1] = true; 
    is_star[y+1][x+1] = true;

    // 세 번째 줄: 밑변을 이루는 별 5개 연속
    is_star[y+2][x-2] = true;
    is_star[y+2][x-1] = true;
    is_star[y+2][x  ] = true;
    is_star[y+2][x+1] = true;
    is_star[y+2][x+2] = true;

    return;
}

// [2] 재귀를 통해 큰 삼각형을 작은 삼각형 3개로 분할하는 함수
// height: 현재 그리고자 하는 삼각형의 높이
// pos: 현재 삼각형의 맨 위 꼭짓점 좌표 (y, x)
void solve(int height, pair<int,int> pos, vector<vector<bool>> &is_star){
    // 기저 조건 (Base Case): 
    // 높이가 3이 되면 더 이상 쪼갤 수 없으므로 실제 별을 그리는 함수 호출
    if(height==3){
        star(pos, is_star);
        return;
    }
    
    int y = pos.first;
    int x = pos.second;

    // 재귀 단계 (Recursive Step): 
    // 현재 높이의 절반(height/2)을 가진 3개의 작은 삼각형으로 쪼갭니다.
    
    // 1. 위쪽 삼각형: 꼭짓점의 위치는 전체 삼각형의 꼭짓점과 동일함
    pair<int,int> top = {y, x};
    solve(height/2, top, is_star);

    // 2. 왼쪽 아래 삼각형: 
    // y좌표는 높이의 절반만큼 아래로(+), x좌표는 높이의 절반만큼 왼쪽으로(-) 이동
    pair<int,int> left = {y + height/2, x - height/2};
    solve(height/2, left, is_star);

    // 3. 오른쪽 아래 삼각형: 
    // y좌표는 높이의 절반만큼 아래로(+), x좌표는 높이의 절반만큼 오른쪽으로(+) 이동
    pair<int,int> right = {y + height/2, x + height/2};
    solve(height/2, right, is_star);

    return;
}

int main(){
    // C++ 표준 스트림 동기화 해제 (입출력 속도 향상을 위한 필수 테크닉)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N; // 전체 삼각형의 높이 입력 (3 * 2^k 형태)

    // 도화지 역할을 할 2차원 벡터 생성 및 false(공백)로 초기화
    // 높이는 N, 너비는 삼각형이 퍼지는 공간을 고려해 N*2로 넉넉하게 잡습니다.
    vector<vector<bool>> is_star(N, vector<bool>(N*2, false));
    
    // 전체 패턴을 그리기 위한 최초의 꼭짓점 좌표 설정
    // 최상단 꼭짓점은 첫 번째 줄(y=0)의 정중앙(x=N-1)에 위치합니다.
    pair<int,int> top = {0, N-1};

    // 재귀 함수 호출을 통해 배열 갱신 시작
    solve(N, top, is_star);

    // 배열에 기록된 정보(true/false)를 바탕으로 실제 콘솔에 출력
    for(int row=0; row<N; row++){
        for(int col=0; col<N*2; col++){
            if(is_star[row][col]){
                cout << "*";
            }else{
                cout << " "; // 별이 없는 공간은 공백으로 채움
            }
        }
        cout << "\n"; // 한 줄 출력이 끝나면 줄바꿈
    }

    return 0;
}
