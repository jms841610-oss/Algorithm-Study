#include <stdio.h>
#include <stdlib.h>

// ==========================================
// 1. Vector (연속된 메모리 구조)
// ==========================================
typedef struct {
    int* data;
    size_t size;
} Vector;

int* vector_begin(Vector* v) {
    return v->data;
}

// ★ Vector의 end() 구현: '시작 주소 + 데이터 개수'를 통해 마지막 다음 칸의 주소 반환
int* vector_end(Vector* v) {
    if (v->data == NULL) return NULL;
    return v->data + v->size; 
}

// ==========================================
// 2. List (노드 연결 구조)
// ==========================================
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

Node* list_begin(List* lst) {
    return lst->head;
}

// ★ List의 end() 구현: 리스트의 끝을 의미하는 NULL 반환
Node* list_end(List* lst) {
    // (C++ 표준 라이브러리는 때때로 더미 노드를 쓰기도 하지만, 
    // 논리적인 원리는 "더 이상 유효한 노드가 없는 상태(NULL)"와 완벽히 같습니다.)
    return NULL; 
}

// ==========================================
// 3. 일반 배열을 위한 매크로
// ==========================================
#define ARRAY_BEGIN(arr) (arr)
// ★ 배열의 크기를 구해 시작 포인터에 더해줍니다.
#define ARRAY_END(arr) ((arr) + (sizeof(arr) / sizeof((arr)[0])))

int main() {
    printf("--- 1. Vector 순회 (begin ~ end) ---\n");
    Vector v;
    v.size = 3;
    v.data = (int*)malloc(sizeof(int) * 3);
    v.data[0] = 10; v.data[1] = 20; v.data[2] = 30;
    
    // C++의 for (auto it = v.begin(); it != v.end(); ++it) 와 완벽히 동일한 구조입니다!
    for (int* it = vector_begin(&v); it != vector_end(&v); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    free(v.data);


    printf("\n--- 2. List 순회 (begin ~ end) ---\n");
    List lst;
    Node n3 = {300, NULL};
    Node n2 = {200, &n3};
    Node n1 = {100, &n2};
    lst.head = &n1;
    
    // it이 list_end() 즉, NULL이 될 때까지 다음 노드로 이동합니다.
    for (Node* it = list_begin(&lst); it != list_end(&lst); it = it->next) {
        printf("%d ", it->data);
    }
    printf("\n");


    printf("\n--- 3. 일반 배열 순회 (begin ~ end) ---\n");
    int arr[] = {7, 8, 9, 10};
    
    for (int* it = ARRAY_BEGIN(arr); it != ARRAY_END(arr); it++) {
        printf("%d ", *it);
    }
    printf("\n");

    return 0;
}
