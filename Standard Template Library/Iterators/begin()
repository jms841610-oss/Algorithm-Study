#include <stdio.h>
#include <stdlib.h>

// ==========================================
// 1. Vector (연속된 메모리 구조)를 위한 begin
// ==========================================
typedef struct {
    int* data;      // 실제 데이터가 들어있는 동적 배열
    size_t size;
    size_t capacity;
} Vector;

// Vector의 begin() 구현: 배열의 첫 번째 요소 주소를 그대로 반환합니다.
// 반환 타입이 int*(정수 포인터)입니다.
int* vector_begin(Vector* v) {
    if (v->data == NULL || v->size == 0) return NULL;
    return v->data; // v->data 자체가 배열의 첫 번째 주소입니다!
}

// ==========================================
// 2. List (노드 연결 구조)를 위한 begin
// ==========================================
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;     // 리스트의 첫 번째 노드
    size_t size;
} List;

// List의 begin() 구현: 첫 번째 노드의 주소를 반환합니다.
// 반환 타입이 Node*(노드 포인터)입니다.
Node* list_begin(List* lst) {
    return lst->head; // 리스트의 머리(head) 부분 주소를 반환!
}

// ==========================================
// 3. 일반 C언어 배열을 위한 begin (매크로 활용)
// C++의 std::begin(arr) 비멤버 함수를 흉내냅니다.
// ==========================================
#define ARRAY_BEGIN(arr) (arr) // 배열의 이름은 그 자체로 첫 번째 요소의 주소입니다.

int main() {
    printf("--- 1. Vector의 begin() 테스트 ---\n");
    Vector my_vector;
    my_vector.size = 3;
    my_vector.data = (int*)malloc(sizeof(int) * 3);
    my_vector.data[0] = 10; my_vector.data[1] = 20; my_vector.data[2] = 30;
    
    int* v_it = vector_begin(&my_vector); // C++의 auto it = my_vector.begin(); 느낌
    if (v_it != NULL) {
        printf("Vector의 첫 번째 데이터: %d (메모리 주소: %p)\n", *v_it, (void*)v_it);
    }
    free(my_vector.data);


    printf("\n--- 2. List의 begin() 테스트 ---\n");
    List my_list;
    Node n1 = {100, NULL};
    Node n2 = {200, NULL};
    n1.next = &n2;
    my_list.head = &n1; // 수동으로 리스트 연결
    
    Node* l_it = list_begin(&my_list);
    if (l_it != NULL) {
        printf("List의 첫 번째 데이터: %d (메모리 주소: %p)\n", l_it->data, (void*)l_it);
    }


    printf("\n--- 3. 일반 배열의 begin() 테스트 ---\n");
    int my_array[] = {999, 888, 777};
    int* a_it = ARRAY_BEGIN(my_array);
    printf("Array의 첫 번째 데이터: %d (메모리 주소: %p)\n", *a_it, (void*)a_it);

    return 0;
}
