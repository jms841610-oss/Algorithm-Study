#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 2차원 공간 시뮬레이션 함수
void simulateMovement(int n, string plans) {
    // 1. 시작 위치 설정 (가장 왼쪽 위를 1행 1열로 시작합니다)
    int x = 1; // 행 (Row, 세로 방향)
    int y = 1; // 열 (Column, 가로 방향)

    // 2. 방향 벡터 설정: L(좌), R(우), U(상), D(하)에 따른 x, y의 변화량
    // x는 위아래 이동(행), y는 좌우 이동(열)을 담당합니다.
    int dx[4] = {0, 0, -1, 1}; // 좌, 우, 상, 하 순서
    int dy[4] = {-1, 1, 0, 0}; // 좌, 우, 상, 하 순서
    char moveTypes[4] = {'L', 'R', 'U', 'D'};

    // 3. 사용자의 이동 계획을 하나씩 확인하며 시뮬레이션 진행
    for (char plan : plans) {
        // 공백 문자는 무시하고 넘어갑니다.
        if (plan == ' ') continue;

        int nextX = -1, nextY = -1;

        // 현재 계획된 명령(plan)이 어느 방향인지 확인하고 다음 위치를 계산
        for (int i = 0; i < 4; i++) {
            if (plan == moveTypes[i]) {
                nextX = x + dx[i];
                nextY = y + dy[i];
                break;
            }
        }

        // 4. 예외 처리: 계산된 다음 위치가 지도(N x N) 범위를 벗어나는지 확인
        if (nextX < 1 || nextY < 1 || nextX > n || nextY > n) {
            // 범위를 벗어난다면 이번 명령은 무시하고 다음 명령으로 넘어갑니다.
            continue;
        }

        // 5. 범위 안이라면 캐릭터의 실제 위치를 이동시킵니다.
        x = nextX;
        y = nextY;
    }

    // 최종 위치 출력
    cout << "모든 이동을 마친 후 캐릭터의 최종 위치: (" << x << ", " << y << ")\n";
}

int main() {
    // 지도의 크기 (5 x 5)
    int n = 5;

    // 캐릭터의 이동 계획 (문자열)
    // R: 오른쪽, L: 왼쪽, U: 위쪽, D: 아래쪽
    string plans = "R R R U D D";

    cout << "지도의 크기: " << n << " x " << n << "\n";
    cout << "이동 계획: " << plans << "\n\n";

    // 시뮬레이션 실행!
    simulateMovement(n, plans);

    return 0;
}
