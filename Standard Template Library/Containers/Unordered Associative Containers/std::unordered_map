#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 7 // 버킷(배열)의 개수. (보통 소수로 설정하면 데이터가 골고루 퍼집니다)

// 1. 노드 구조체 (키, 값, 그리고 다음 노드를 가리키는 포인터)
// 같은 버킷에 여러 데이터가 들어올 경우(충돌) 연결 리스트로 묶기 위해 next가 필요합니다.
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// 2. 해시 테이블 구조체 (unordered_map)
typedef struct {
    Node** buckets;    // 버킷 배열 (Node 포인터들을 담는 배열)
    size_t size;       // 현재 해시 테이블에 들어있는 데이터의 총 개수
} UnorderedMap;

// 3. 맵 초기화 함수
void init_map(UnorderedMap* map) {
    map->size = 0;
    map->buckets = (Node**)calloc(BUCKET_COUNT, sizeof(Node*)); // 모든 버킷을 NULL로 초기화
    if (map->buckets == NULL) {
        printf("메모리 할당 실패!\n");
        exit(1);
    }
}

// 4. 해시 함수 (Hash Function)
// 키를 버킷의 개수로 나눈 나머지를 반환합니다. (결과는 항상 0 ~ BUCKET_COUNT-1)
int hash_function(int key) {
    return key % BUCKET_COUNT; 
}

// 5. 새로운 노드 생성 함수
Node* create_node(int key, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// 6. 데이터 추가 및 덮어쓰기 (C++의 map[key] = value)
void insert_or_assign(UnorderedMap* map, int key, int value) {
    int bucket_idx = hash_function(key); // 1단계: 어느 버킷에 들어갈지 계산!
    
    // 해당 버킷의 연결 리스트를 순회하며 이미 같은 키가 있는지 확인
    Node* current = map->buckets[bucket_idx];
    while (current != NULL) {
        if (current->key == key) {
            // 이미 키가 존재하면 값만 덮어쓰고 종료!
            printf("🔄 [버킷 %d] 기존 데이터 수정: 키 %d의 값이 %d(으)로 변경됨\n", bucket_idx, key, value);
            current->value = value;
            return;
        }
        current = current->next;
    }
    
    // 키가 없다면, 새로운 노드를 만들어 연결 리스트의 맨 앞에 추가 (O(1) 속도)
    Node* new_node = create_node(key, value);
    new_node->next = map->buckets[bucket_idx];
    map->buckets[bucket_idx] = new_node;
    map->size++;
    printf("⚡ [버킷 %d] 새 데이터 추가: 키 %d, 값 %d\n", bucket_idx, key, value);
}

// 7. 특정 키 검색 (C++의 map.find)
int* find_value(UnorderedMap* map, int key) {
    int bucket_idx = hash_function(key); // 단번에 버킷 번호를 알아냅니다.
    
    Node* current = map->buckets[bucket_idx];
    while (current != NULL) {
        if (current->key == key) {
            return &(current->value); // 찾음! 값의 메모리 주소 반환
        }
        current = current->next;
    }
    return NULL; // 못 찾음
}

// 8. 해시 테이블 전체 출력 (순서가 뒤죽박죽인 것을 확인하세요!)
void print_unordered_map(UnorderedMap* map) {
    printf("\n--- unordered_map 내부 상태 (버킷별 출력) ---\n");
    for (int i = 0; i < BUCKET_COUNT; i++) {
        printf("버킷[%d]: ", i);
        Node* current = map->buckets[i];
        if (current == NULL) {
            printf("(비어있음)");
        }
        while (current != NULL) {
            printf("[K:%d, V:%d] -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
    printf("총 데이터 개수: %zu\n", map->size);
}

// 9. 메모리 해제
void free_map(UnorderedMap* map) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        Node* current = map->buckets[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(map->buckets);
    map->size = 0;
}

int main() {
    UnorderedMap my_umap;
    init_map(&my_umap);
    
    printf("--- 데이터 추가 시작 ---\n");
    insert_or_assign(&my_umap, 10, 100); // 10 % 7 = 버킷 3
    insert_or_assign(&my_umap, 20, 200); // 20 % 7 = 버킷 6
    insert_or_assign(&my_umap, 15, 150); // 15 % 7 = 버킷 1
    
    // 충돌 유도: 17 % 7 = 버킷 3 (키 10과 같은 버킷을 사용하게 됩니다!)
    insert_or_assign(&my_umap, 17, 170); 
    
    // 기존 데이터 덮어쓰기
    insert_or_assign(&my_umap, 10, 999); 
    
    // 순서가 없음을 확인해 보세요! 입력한 순서나 크기 순서와 전혀 다르게 저장됩니다.
    print_unordered_map(&my_umap);
    
    printf("\n--- 데이터 검색 ---\n");
    int* val = find_value(&my_umap, 17);
    if (val != NULL) printf("키 17의 값은 %d입니다. (탐색 속도 O(1)!)\n", *val);
    
    free_map(&my_umap);
    return 0;
}
