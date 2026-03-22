#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 4 // 이해를 돕기 위해 블록 하나당 4개의 요소를 저장

// 1. 데큐 구조체 정의
typedef struct {
    int** map;         // 블록(청크) 포인터들을 저장하는 배열
    size_t map_cap;    // 현재 Map이 가질 수 있는 최대 블록 개수
    size_t start_idx;  // 첫 번째 데이터의 가상(전역) 인덱스
    size_t size;       // 현재 저장된 요소의 총 개수
} Deque;

// 2. 데큐 초기화 함수
void init_deque(Deque* dq, size_t initial_map_cap) {
    dq->map_cap = initial_map_cap > 0 ? initial_map_cap : 4;
    dq->map = (int**)calloc(dq->map_cap, sizeof(int*)); // NULL로 초기화
    
    // 앞뒤로 자유롭게 확장할 수 있도록 Map의 중앙에서 시작
    size_t mid_chunk = dq->map_cap / 2;
    dq->map[mid_chunk] = (int*)malloc(CHUNK_SIZE * sizeof(int));
    
    // 첫 블록의 중간 지점부터 데이터를 채우도록 시작 인덱스 설정
    dq->start_idx = mid_chunk * CHUNK_SIZE + (CHUNK_SIZE / 2);
    dq->size = 0;
}

// 3. Map 재할당 및 중앙 정렬 함수
// 앞이나 뒤로 공간이 부족해지면 Map의 크기를 키우고 기존 블록들을 중앙으로 옮깁니다.
void reallocate_map(Deque* dq) {
    size_t new_cap = dq->map_cap * 2;
    int** new_map = (int**)calloc(new_cap, sizeof(int*));
    
    // 기존 map에서 사용 중인 블록의 범위 찾기
    size_t start_chunk = dq->start_idx / CHUNK_SIZE;
    size_t end_chunk = dq->size > 0 ? (dq->start_idx + dq->size - 1) / CHUNK_SIZE : start_chunk;
    size_t num_chunks = end_chunk - start_chunk + 1;
    
    // 새 map의 정중앙에 블록들 배치
    size_t new_start_chunk = (new_cap - num_chunks) / 2;
    
    for (size_t i = 0; i < num_chunks; i++) {
        new_map[new_start_chunk + i] = dq->map[start_chunk + i];
    }
    
    // start_idx 업데이트 (새로운 블록 위치에 맞게 오프셋 조정)
    size_t offset_in_chunk = dq->start_idx % CHUNK_SIZE;
    dq->start_idx = new_start_chunk * CHUNK_SIZE + offset_in_chunk;
    
    free(dq->map);
    dq->map = new_map;
    dq->map_cap = new_cap;
    printf("🔄 Map 재할당! 중앙 정렬 완료. (새로운 Map 용량: %zu)\n", dq->map_cap);
}

// 4. 뒤에 요소 추가 (C++의 push_back)
void push_back(Deque* dq, int value) {
    size_t end_idx = dq->start_idx + dq->size;
    size_t chunk_idx = end_idx / CHUNK_SIZE; // 데이터가 들어갈 블록 인덱스
    size_t offset = end_idx % CHUNK_SIZE;    // 블록 내부에서의 위치
    
    // Map이 꽉 찼다면 재할당
    if (chunk_idx >= dq->map_cap) {
        reallocate_map(dq);
        // 위치가 중앙으로 바뀌었으므로 인덱스 다시 계산
        end_idx = dq->start_idx + dq->size;
        chunk_idx = end_idx / CHUNK_SIZE;
        offset = end_idx % CHUNK_SIZE;
    }
    
    // 해당 블록이 비어있다면 새로 메모리 할당
    if (dq->map[chunk_idx] == NULL) {
        dq->map[chunk_idx] = (int*)malloc(CHUNK_SIZE * sizeof(int));
        printf("📦 [뒤] 새로운 청크 할당됨! (Map 인덱스: %zu)\n", chunk_idx);
    }
    
    dq->map[chunk_idx][offset] = value;
    dq->size++;
}

// 5. 앞에 요소 추가 (C++의 push_front)
void push_front(Deque* dq, int value) {
    // 앞으로 갈 공간이 더 이상 없다면 Map 재할당
    if (dq->start_idx == 0) {
        reallocate_map(dq);
    }
    
    dq->start_idx--; // 시작 인덱스를 한 칸 앞으로 당김
    size_t chunk_idx = dq->start_idx / CHUNK_SIZE;
    size_t offset = dq->start_idx % CHUNK_SIZE;
    
    if (dq->map[chunk_idx] == NULL) {
        dq->map[chunk_idx] = (int*)malloc(CHUNK_SIZE * sizeof(int));
        printf("📦 [앞] 새로운 청크 할당됨! (Map 인덱스: %zu)\n", chunk_idx);
    }
    
    dq->map[chunk_idx][offset] = value;
    dq->size++;
}

// 6. 요소 접근 함수 (C++의 dq[index])
int get(Deque* dq, size_t index) {
    if (index >= dq->size) {
        printf("에러: 인덱스 범위를 벗어났습니다.\n");
        exit(1);
    }
    // 논리적 인덱스를 물리적 2차원 배열 위치로 변환
    size_t actual_idx = dq->start_idx + index;
    return dq->map[actual_idx / CHUNK_SIZE][actual_idx % CHUNK_SIZE];
}

// 7. 메모리 해제 함수
void free_deque(Deque* dq) {
    for (size_t i = 0; i < dq->map_cap; i++) {
        if (dq->map[i] != NULL) free(dq->map[i]); // 할당된 각 블록 해제
    }
    free(dq->map); // Map 해제
}

int main() {
    Deque my_deque;
    init_deque(&my_deque, 4); // Map 용량 4로 초기화
    
    printf("--- 데이터 추가 시작 ---\n");
    
    // 뒤로 데이터 추가
    push_back(&my_deque, 10);
    push_back(&my_deque, 20);
    push_back(&my_deque, 30); // 기본 할당 블록을 넘어서면 새 블록 할당됨
    
    // 앞으로 데이터 추가
    push_front(&my_deque, 5);
    push_front(&my_deque, 1); // 앞으로 확장하다 공간 부족 시 Map 재할당됨
    
    printf("\n--- 데큐의 내용 출력 ---\n");
    for (size_t i = 0; i < my_deque.size; i++) {
        printf("인덱스 [%zu]: %d\n", i, get(&my_deque, i));
    }
    
    free_deque(&my_deque);
    return 0;
}
