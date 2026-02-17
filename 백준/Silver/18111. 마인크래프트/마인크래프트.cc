#include <iostream>
#include <vector>

using namespace std;

// 전역 변수 선언: 재귀나 함수 호출 시 파라미터 전달 비용 절약
int N, M, B;

// 결과값 초기화
// max_height: 조건 만족 시, 더 높은 층을 우선하므로 0부터 시작해서 갱신
// min_time: 이론상 최대 시간(모든 블록을 깎는 경우)보다 넉넉하게 큰 값으로 초기화
int max_height = 0;
int min_time = 500 * 500 * 256 * 2; 

// [Core Optimization] 
// 2차원 맵 전체를 저장하는 대신, 각 높이가 몇 번 등장하는지만 저장 (Counting Sort 개념)
// 공간 복잡도를 O(N*M)에서 O(1)로, 탐색 시간을 단축시키는 핵심 자료구조
vector<int> frequency(257, 0);

void flattening() {
    // 가능한 모든 땅의 높이(0 ~ 256)를 목표(Target)로 설정해보고 최적해 탐색 (Brute Force)
    for (int target_height = 0; target_height < 257; target_height++) {
        int needed_block = 0; // 쌓아야 할 블록 수 (인벤토리에서 꺼냄, 1초)
        int getted_block = 0; // 깎아야 할 블록 수 (인벤토리로 들어감, 2초)

        // 현재 맵에 존재하는 높이들을 순회하며 비용 계산
        for (int current_height = 0; current_height < 257; current_height++) {
            // 해당 높이의 땅이 없다면 계산 스킵 (최적화)
            if (frequency[current_height] == 0) continue; 

            int count = frequency[current_height];

            if (current_height > target_height) {
                // 현재 땅이 목표보다 높음 -> 깎아야 함 (블록 획득)
                getted_block += (current_height - target_height) * count;
            }
            else {
                // 현재 땅이 목표보다 낮음 -> 쌓아야 함 (블록 소모)
                needed_block += (target_height - current_height) * count;
            }
        }

        // [Constraint Check] 
        // 획득한 블록 + 초기 인벤토리(B)로 부족한 부분을 메울 수 있는지 확인
        if ((getted_block + B) >= needed_block) {
            // 시간 계산: 깎기(2초) + 쌓기(1초)
            int target_time = getted_block * 2 + needed_block;

            // [Update Logic]
            // 시간이 더 적게 걸리면 무조건 갱신
            // 시간이 같을 경우, 높이가 더 높은 것을 선택해야 하므로 '=' 포함 (target_height가 오름차순이므로 자연스럽게 갱신)
            if (target_time <= min_time) {
                min_time = target_time;
                max_height = target_height;
            }
        }
    }
    return;
}

int main() {
    // 입출력 속도 향상 (대량의 I/O 발생 시 필수)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> B;

    // 맵 데이터를 입력받으면서 바로 빈도수(Frequency) 테이블 생성
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            int height;
            cin >> height;
            frequency[height]++;
        }
    }

    flattening();

    cout << min_time << " " << max_height << endl;

    return 0;
}
