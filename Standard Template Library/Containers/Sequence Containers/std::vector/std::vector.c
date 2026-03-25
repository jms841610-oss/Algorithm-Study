#include <stdio.h>
#include <stdlib.h>

// 1. 벡터 구조체 정의
typedef struct {
    int* data;      // 실제 데이터가 저장될 배열의 포인터
    size_t size;    // 현재 저장된 요소의 개수
    size_t capacity;// 현재 할당된 메모리의 최대 용량
} Vector;

// 2. 벡터 초기화 함수
void init_vector(Vector* v, size_t initial_capacity) {
    v->capacity = initial_capacity;
    v->size = 0;
    
    // capacity가 0보다 크면 메모리 할당, 아니면 NULL
    if (initial_capacity > 0) {
        v->data = (int*)malloc(v->capacity * sizeof(int));
    } else {
        v->data = NULL;
    }
}

// 3. 요소 추가 함수 (C++의 push_back)
void push_back(Vector* v, int value) {
    // 할당된 메모리 용량이 꽉 찼는지 확인
    if (v->size == v->capacity) {
        // 용량을 2배로 늘림 (초기 용량이 0일 경우 1로 설정)
        v->capacity = (v->capacity == 0) ? 1 : v->capacity * 2;
        
        // realloc을 사용하여 메모리 재할당 (기존 데이터 자동 복사 포함)
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
        
        if (v->data == NULL) {
            printf("메모리 할당 실패!\n");
            exit(1);
        }
        
        printf("🔄 메모리 재할당 발생! 새로운 용량: %zu\n", v->capacity);
    }
    
    // 데이터 추가 및 size 증가
    v->data[v->size] = value;
    v->size++;
}

// 4. 요소 접근 함수 (C++의 v[index])
int get(Vector* v, size_t index) {
    if (index >= v->size) {
        printf("에러: 인덱스 범위를 벗어났습니다.\n");
        exit(1);
    }
    return v->data[index];
}

// 5. 메모리 해제 함수
void free_vector(Vector* v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

int main() {
    Vector my_vector;
    
    // 초기 용량 2로 벡터 초기화
    init_vector(&my_vector, 2);
    
    printf("--- 데이터 추가 시작 ---\n");
    push_back(&my_vector, 10); // size: 1, capacity: 2
    push_back(&my_vector, 20); // size: 2, capacity: 2
    
    // 용량이 꽉 찼으므로, 여기서 재할당 발생! (용량 4로 증가)
    push_back(&my_vector, 30); // size: 3, capacity: 4
    push_back(&my_vector, 40); // size: 4, capacity: 4
    
    // 다시 용량이 꽉 찼으므로, 여기서 재할당 발생! (용량 8로 증가)
    push_back(&my_vector, 50); // size: 5, capacity: 8
    
    printf("\n--- 벡터의 내용 출력 ---\n");
    for (size_t i = 0; i < my_vector.size; i++) {
        printf("인덱스 [%zu]: %d\n", i, get(&my_vector, i));
    }
    
    printf("\n📊 최종 상태 분석:\n");
    printf("- 현재 크기(size): %zu\n", my_vector.size);
    printf("- 현재 용량(capacity): %zu\n", my_vector.capacity);
    
    // 사용이 끝난 메모리 반환
    free_vector(&my_vector);
    
    return 0;
}
