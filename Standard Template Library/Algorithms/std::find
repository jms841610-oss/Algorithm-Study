#include <stdio.h>

// 1. std::find를 흉내 낸 탐색 함수
// first: 탐색을 시작할 위치의 포인터
// last: 탐색을 종료할 위치의 포인터 (배열의 끝을 넘어선 주소)
// value: 찾고자 하는 값
int* my_std_find(int* first, int* last, int value) {
    // 시작 포인터가 끝 포인터에 도달할 때까지 반복합니다.
    while (first != last) {
        // 포인터가 가리키는 실제 값을 확인하여 찾고자 하는 값과 같으면
        if (*first == value) {
            return first; // 찾은 위치의 포인터를 즉시 반환!
        }
        // 값을 못 찾았다면 포인터를 다음 칸으로 이동시킵니다.
        first++;
    }
    
    // 반복문이 끝날 때까지 못 찾았다면, last 포인터를 그대로 반환합니다.
    return last;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // C++의 arr.begin()과 arr.end() 느낌으로 포인터를 준비합니다.
    int* begin = arr;        // 첫 번째 요소의 주소 (10)
    int* end = arr + n;      // 마지막 요소(60)의 바로 다음 메모리 주소
    
    printf("--- 데이터 탐색 시작 ---\n");
    
    // 1. 존재하는 값 탐색 (30)
    int target1 = 30;
    int* result1 = my_std_find(begin, end, target1);
    
    if (result1 != end) { // 반환값이 end와 다르면 찾은 것입니다!
        // 주소의 차이를 이용해 인덱스를 계산할 수 있습니다.
        int index = result1 - begin;
        printf("✅ %d을(를) 찾았습니다! (인덱스: %d, 포인터 주소: %p)\n", target1, index, (void*)result1);
    } else {
        printf("❌ %d을(를) 찾지 못했습니다.\n", target1);
    }
    
    // 2. 존재하지 않는 값 탐색 (99)
    int target2 = 99;
    int* result2 = my_std_find(begin, end, target2);
    
    if (result2 != end) {
        printf("✅ %d을(를) 찾았습니다!\n", target2);
    } else {
        // 결과를 보면 result2가 정확히 end 포인터와 동일함을 알 수 있습니다.
        printf("❌ %d을(를) 찾지 못했습니다. (반환된 주소가 end 주소와 동일함)\n", target2);
    }

    return 0;
}
