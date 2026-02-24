#include <iostream>

using namespace std;
// 좌표를 나타내기 위해 pair를 사용하여 가독성 향상 (first: 행/y, second: 열/x)
using pos = pair<int,int>;

/**
 * @brief Z 모양으로 배열을 탐색하며 목표 좌표의 방문 순서를 찾는 분할 정복 함수
 * * @param target 찾고자 하는 목표 좌표
 * @param current 현재 탐색 중인 사분면의 좌상단(시작) 좌표
 * @param len 현재 탐색 중인 영역의 한 변의 길이
 * @param idx 누적된 방문 횟수 (참조자로 전달하여 계속 누적됨)
 */
void visiting(pos target, pos current, int len, int &idx){
    // 1. 기저 조건: 한 변의 길이가 1이 되면 탐색 공간을 완전히 좁힌 것이므로 결과 출력
    if(len == 1){
        cout << idx << "\n";
        return;
    } else {
        // 2. 분할: 탐색 영역을 4개의 사분면으로 쪼개기 위해 길이를 절반으로 줄임
        len /= 2;

        // 목표 좌표가 현재 영역의 위쪽(상)인지 왼쪽(좌)인지 판별하는 플래그
        bool is_up = true;
        bool is_left = true;

        // 경계선(current + len)을 기준으로 위치 판별
        if(target.first >= current.first + len){
            is_up = false; // 아래쪽(하)에 위치
        }
        if(target.second >= current.second + len){
            is_left = false; // 오른쪽(우)에 위치
        }

        // 3. 정복: 목표가 위치한 사분면만 재귀적으로 파고들고, 스킵한 영역만큼 idx 증가
        // Z 모양 탐색 순서: 좌상(1) -> 우상(2) -> 좌하(3) -> 우하(4)
        
        if((is_up) && (is_left)){
            // 제 1사분면 (좌상단): 스킵하는 영역 없음
            visiting(target, current, len, idx);
            
        } else if((is_up) && (!is_left)){
            // 제 2사분면 (우상단): 1사분면 1개 스킵
            current.second += len;      // 시작 x좌표를 오른쪽으로 이동
            idx += len * len;           // 1사분면 면적(len * len)만큼 인덱스 추가
            visiting(target, current, len, idx);
            
        } else if((!is_up) && (is_left)){
            // 제 3사분면 (좌하단): 1, 2사분면 2개 스킵
            current.first += len;       // 시작 y좌표를 아래쪽으로 이동
            idx += len * len * 2;       // 사분면 면적 * 2 만큼 인덱스 추가
            visiting(target, current, len, idx);
            
        } else if((!is_up) && (!is_left)){
            // 제 4사분면 (우하단): 1, 2, 3사분면 3개 스킵
            current.first += len;       // 시작 y좌표를 아래쪽으로 이동
            current.second += len;      // 시작 x좌표를 오른쪽으로 이동
            idx += len * len * 3;       // 사분면 면적 * 3 만큼 인덱스 추가
            visiting(target, current, len, idx);
        }
    }
}

int main(){
    // 입출력 속도 향상을 위한 최적화 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, row, col;
    cin >> N >> row >> col;

    // 초기 한 변의 길이는 2^N
    int len = 1;
    for(int i = 0; i < N; i++){
        len *= 2;
    }
    
    // 시작 좌표 (0, 0) 설정
    pos start;
    start.first = 0;
    start.second = 0;
    
    // 목표 좌표 설정
    pos target;
    target.first = row;
    target.second = col;

    int idx = 0;

    // 탐색 시작
    visiting(target, start, len, idx);

    return 0;
}
