#include <iostream>

using namespace std;
using pos = pair<int,int>;

// target: 찾고자 하는 목표 좌표
// current: 현재 탐색 중인 영역의 좌상단(시작) 좌표
// len: 현재 탐색 중인 영역의 한 변의 길이
// idx: 방문 순서 (참조자 '&'를 사용하여 계속 누적시킴)
void visiting(pos target, pos current, int len, int &idx){
    // Base Case: 영역이 1x1 크기로 쪼개졌을 때, 목표 위치에 도달함
    if(len == 1){
        cout << idx << "\n";
    } else {
        // Divide: 영역을 4등분 하기 위해 한 변의 길이를 절반으로 줄임
        len /= 2;

        // 사분면 판별을 위한 플래그 (기본값을 좌상단인 1사분면으로 가정)
        bool is_up = true;
        bool is_left = true;

        // 목표 행이 현재 영역의 절반(가로 분할선)보다 같거나 크면 아래쪽(Down)
        if(target.first >= current.first + len){
            is_up = false;
        }
        // 목표 열이 현재 영역의 절반(세로 분할선)보다 같거나 크면 오른쪽(Right)
        if(target.second >= current.second + len){
            is_left = false;
        }

        // Conquer: 타겟이 위치한 사분면으로 재귀 진입 & 건너뛴 사분면만큼 idx 누적
        if((is_up) && (is_left)){
            // 1사분면 (좌상단): 건너뛸 영역이 없으므로 idx 그대로 유지
            visiting(target, current, len, idx);
        } else if((is_up) && (!is_left)){
            // 2사분면 (우상단): 1사분면을 건너뜀 (len * len 크기 1개)
            current.second += len;      // 시작점 열 이동
            idx += len * len;           // 1사분면 크기만큼 방문 횟수 추가
            visiting(target, current, len, idx);
        } else if((!is_up) && (is_left)){
            // 3사분면 (좌하단): 1, 2사분면을 건너뜀 (len * len 크기 2개)
            current.first += len;       // 시작점 행 이동
            idx += len * len * 2;       // 1, 2사분면 크기 합산
            visiting(target, current, len, idx);
        } else if((!is_up) && (!is_left)){
            // 4사분면 (우하단): 1, 2, 3사분면을 건너뜀 (len * len 크기 3개)
            current.first += len;       // 시작점 행 이동
            current.second += len;      // 시작점 열 이동
            idx += len * len * 3;       // 1, 2, 3사분면 크기 합산
            visiting(target, current, len, idx);
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, row, col;
    cin >> N >> row >> col;

    // 비트 시프트 연산을 통해 2^N 길이 계산 (탐색 공간의 초기 한 변의 길이)
    int len = 1 << N;
    
    pos start;
    start.first = 0;
    start.second = 0;
    
    pos target;
    target.first = row;
    target.second = col;

    int idx = 0;

    visiting(target, start, len, idx);

    return 0;
}
