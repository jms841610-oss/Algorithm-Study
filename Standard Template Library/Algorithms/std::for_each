#include <stdio.h>

// 1. 함수 포인터 타입 정의 (C++의 람다나 함수 객체 역할을 합니다)
// int 포인터를 매개변수로 받아 반환값이 없는(void) 함수의 형태를 'ActionFunc'로 정의합니다.
typedef void (*ActionFunc)(int*);

// 2. std::for_each를 흉내 낸 알고리즘 함수
// 데이터의 범위(first, last)와 적용할 함수(action)를 받습니다.
void my_std_for_each(int* first, int* last, ActionFunc action) {
    while (first != last) {
        action(first); // 현재 가리키는 요소의 주소를 함수에 전달하여 실행!
        first++;       // 다음 칸으로 이동
    }
}

// ---------------------------------------------------
// 3. 데이터에 적용할 구체적인 동작(Action) 함수들
// ---------------------------------------------------

// 동작 A: 요소를 화면에 출력하기만 하는 함수 (읽기 전용 느낌)
void print_element(int* val) {
    printf("%d ", *val);
}

// 동작 B: 요소의 값을 2배로 증가시키는 함수 (데이터 수정)
void double_element(int* val) {
    *val = (*val) * 2; 
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int* begin = arr;
    int* end = arr + n;
    
    printf("--- 1. 원본 배열 출력 (print_element 함수 적용) ---\n");
    // 배열의 모든 요소에 대해 print_element 함수를 실행합니다.
    my_std_for_each(begin, end, print_element);
    printf("\n");
    
    printf("\n--- 2. 배열의 모든 요소 2배로 만들기 (double_element 함수 적용) ---\n");
    // 배열의 모든 요소에 대해 double_element 함수를 실행합니다. (for문이 없어도 알아서 다 돌아갑니다!)
    my_std_for_each(begin, end, double_element);
    printf("✅ 변환 완료!\n");
    
    printf("\n--- 3. 수정된 배열 다시 출력 ---\n");
    // 값이 진짜로 바뀌었는지 다시 출력해 봅니다.
    my_std_for_each(begin, end, print_element);
    printf("\n");

    return 0;
}
