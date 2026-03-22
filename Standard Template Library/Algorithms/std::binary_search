#include <stdio.h>

// 1. std::binary_search를 흉내 낸 탐색 함수
// first: 탐색 시작 포인터, last: 탐색 종료 포인터(배열의 끝 다음), value: 찾을 값
// 반환값: 찾으면 1(true), 못 찾으면 0(false) 반환
int my_binary_search(int* first, int* last, int value) {
    // 탐색할 범위가 남아있는 동안 계속 반복합니다.
    while (first < last) {
        // 현재 범위의 '정중앙' 위치(포인터)를 계산합니다.
        // 포인터끼리 더할 수는 없으므로, (끝 - 시작) 거리의 절반을 시작점에 더해줍니다.
        int* mid = first + (last - first) / 2;

        if (*mid == value) {
            return 1; // 정답을 찾았습니다! 즉시 1 반환
        } 
        else if (*mid < value) {
            // 중앙값보다 찾는 값이 더 크면, 오른쪽 절반으로 범위를 좁힙니다.
            // mid 위치의 값은 이미 확인했으므로 mid + 1부터 시작합니다.
            first = mid + 1;
        } 
        else {
            // 중앙값보다 찾는 값이 더 작으면, 왼쪽 절반으로 범위를 좁힙니다.
            // last는 탐색 범위에 포함되지 않는 '끝점'이므로 그냥 mid를 넣어줍니다.
            last = mid;
        }
    }
    
    // 범위가 다 좁혀질 때까지 못 찾았다면 없는 것입니다.
    return 0; 
}

int main() {
    // ⚠️ 주의: 이진 탐색은 반드시 데이터가 '오름차순으로 정렬'되어 있어야만 작동합니다!
    int arr[] = {1, 5, 8, 12, 19, 23, 33, 42, 51, 60, 77, 88, 95};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int* begin = arr;
    int* end = arr + n;
    
    printf("--- 이진 탐색 시작 ---\n");
    
    // 1. 존재하는 값 찾기
    int target1 = 33;
    printf("목표값 %d 찾기: ", target1);
    if (my_binary_search(begin, end, target1)) {
        printf("✅ 찾았습니다! (존재함)\n");
    } else {
        printf("❌ 없습니다.\n");
    }
    
    // 2. 존재하지 않는 값 찾기
    int target2 = 50;
    printf("목표값 %d 찾기: ", target2);
    if (my_binary_search(begin, end, target2)) {
        printf("✅ 찾았습니다! (존재함)\n");
    } else {
        printf("❌ 없습니다.\n");
    }

    // 3. 배열의 양 끝단에 있는 값 찾기 (경계 조건 테스트)
    printf("목표값 %d 찾기: %s\n", 95, my_binary_search(begin, end, 95) ? "✅" : "❌");
    printf("목표값 %d 찾기: %s\n", 1, my_binary_search(begin, end, 1) ? "✅" : "❌");

    return 0;
}
