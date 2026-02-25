#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 💡 상하좌우 탐색을 위한 방향 배열 (우, 하, 좌, 상)
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct Tomato {
    int y;
    int x;
};

void BFS(vector<vector<int>> &tomato_status, int length, int width) {
    queue<Tomato> q;

    int unriped_tomato = 0;

    // 1. 초기 상태 세팅 (Multi-source BFS)
    for (int row = 0; row < length; row++) {
        for (int col = 0; col < width; col++) {
            if (tomato_status[row][col] == 1) {
                // 시작점이 여러 개일 수 있으므로 익은 토마토를 모두 큐에 삽입
                q.push({row, col});
            }
            if (tomato_status[row][col] == 0) {
                // 남은 익지 않은 토마토 개수 카운트
                unriped_tomato++;
            }
        }
    }
    
    // 💡 최적화 핵심 1: 최대 걸린 시간을 1부터 시작 (초기 익은 토마토 값이 1이므로)
    int max_cost = 1;

    // 2. In-place BFS 탐색
    while (!q.empty()) {
        Tomato current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_row = current.y + dy[i];
            int next_col = current.x + dx[i];

            // 맵 범위 내에 있는지 확인
            if ((0 <= next_row) && (next_row < length) && (0 <= next_col) && (next_col < width)) {
                
                // 💡 최적화 핵심 2: 별도의 is_visited 배열 없이, 맵의 값이 0(익지 않음)일 때만 방문
                if (tomato_status[next_row][next_col] == 0) {
                    unriped_tomato--;
                    
                    // 💡 최
