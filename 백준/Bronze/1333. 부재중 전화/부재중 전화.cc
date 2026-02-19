#include <iostream>

using namespace std;

int main() {
    // 입출력 속도 향상을 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // N: 앨범에 포함된 노래의 개수
    // L: 각 노래의 길이 (초 단위)
    // D: 벨소리가 울리는 주기 (초 단위)
    int N, L, D;
    cin >> N >> L >> D;
    
    // T: 벨소리가 울리는 시점. 처음 울리는 시간은 D초 후이므로 D로 초기화
    int T = D;
    
    // cycle: 노래 1곡이 재생되고 조용한 5초를 보내는 전체 주기 (L + 5)
    int cycle = L + 5;

    // 벨소리를 들을 수 있는 시간을 찾을 때까지 반복
    while (true) {
        // [종료 조건 1] 모든 앨범이 끝난 경우
        // 전체 플레이리스트 시간 = (N * cycle). 
        // 단, 마지막 곡 이후에는 5초 쉬는 구간이 없으므로 최종 끝나는 시간은 (N * cycle - 5)
        if (T >= (N * cycle - 5)) {
            break; // 노래가 다 끝났으므로 항상 벨소리를 들을 수 있음
        }

        // 현재 벨소리 시간(T)이 속한 주기의 어느 지점(초)인지 계산
        int time_in_cycle = T % cycle;

        // [종료 조건 2 & 진행] 현재 주기의 재생 구간인지 휴식 구간인지 판별
        if (time_in_cycle < L) {
            // 0 ~ (L-1)초 사이라면 노래가 재생 중이라 벨소리를 듣지 못함. 
            // 다음 벨소리가 울리는 시간으로 T를 건너뜀
            T += D;
        } else {
            // L ~ (L+4)초 사이라면 조용한 5초 구간이므로 벨소리를 들을 수 있음
            break; 
        }
    }
    
    // 가장 처음 벨소리를 듣게 되는 시간 출력
    cout << T << "\n";

    return 0;
}
