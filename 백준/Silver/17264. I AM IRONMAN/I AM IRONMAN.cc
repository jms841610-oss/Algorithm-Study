#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    // [최적화] C++ 입출력 속도 향상을 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, P; // N: 플레이 횟수, P: 전적을 아는 플레이어 수
    int W, L, G; // W: 승리 시 획득 점수, L: 패배 시 차감 점수, G: 목표 점수
    
    cin >> N >> P;
    cin >> W >> L >> G;

    // [핵심 자료구조] 플레이어 이름을 key, 승패 여부를 value로 가지는 해시 테이블
    // 탐색 시간 복잡도를 O(1)로 줄이기 위해 unordered_map 사용
    unordered_map<string, bool> is_winner;

    // 1. 플레이어 전적 정보 입력 및 해시 테이블 구성
    for(int i = 0; i < P; i++){
        string player;
        char result;
        cin >> player >> result;

        // 'W'이면 true(승리), 'L'이면 false(패배)로 매핑
        if     (result == 'W') is_winner[player] = true;
        else if(result == 'L') is_winner[player] = false;
    }
    
    int total_scr = 0; // 현재 점수

    // 2. N번의 게임 플레이 기록 처리
    for(int i = 0; i < N; i++){
        string player;
        cin >> player;

        // [Edge Case 처리] 전적 정보가 없는 플레이어(해시 테이블에 없는 경우)를 판별
        bool is_exist = true;
        if(is_winner.find(player) == is_winner.end()) is_exist = false;

        if(is_exist){
            if(is_winner[player]){
                // 같이 게임을 해서 이기는 플레이어인 경우
                total_scr += W;
                
                // 목표 점수(G)에 도달했는지 확인 (조기 종료 조건)
                if(total_scr >= G){
                    cout << "I AM NOT IRONMAN!!" << "\n";
                    return 0; // 목표를 달성했으므로 프로그램 즉시 종료
                }
            }else{
                // 같이 게임을 해서 지는 플레이어인 경우
                // 점수가 0 밑으로 떨어지지 않도록 삼항 연산자로 하한선(0) 방어
                total_scr = (total_scr > L) ? total_scr - L : 0;
            }
        }else{
            // 전적 정보가 없는 플레이어인 경우 (문제 조건에 따라 패배 처리)
            total_scr = (total_scr > L) ? total_scr - L : 0;
        }
    }
    
    // N번의 게임을 모두 마쳤으나 목표 점수 G를 달성하지 못한 경우
    cout << "I AM IRONMAN!!" << "\n";

    return 0;
}
