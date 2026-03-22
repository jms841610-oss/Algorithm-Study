#include <stdio.h>
#include <stdlib.h>

// 1. 노드 구조체 정의
typedef struct Node {
    int data;           // 실제 저장되는 데이터
    struct Node* prev;  // 이전 노드를 가리키는 포인터
    struct Node* next;  // 다음 노드를 가리키는 포인터
} Node;

// 2. 리스트 구조체 정의
typedef struct {
    Node* head;         // 리스트의 첫 번째 노드
    Node* tail;         // 리스트의 마지막 노드
    size_t size;        // 현재 리스트에 있는 노드의 개수
} List;

// 3. 리스트 초기화 함수
void init_list(List* lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}

// 4. 새로운 노드를 생성하는 내부 헬퍼 함수
Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("메모리 할당 실패!\n");
        exit(1);
    }
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// 5. 뒤에 요소 추가 (C++의 push_back)
void push_back(List* lst, int value) {
    Node* new_node = create_node(value);
    
    if (lst->size == 0) {
        // 리스트가 비어있을 때는 head와 tail 모두 새 노드를 가리킴
        lst->head = new_node;
        lst->tail = new_node;
    } else {
        // 기존 tail의 다음에 새 노드 연결
        lst->tail->next = new_node;
        // 새 노드의 이전을 기존 tail로 연결
        new_node->prev = lst->tail;
        // tail 포인터를 새 노드로 갱신
        lst->tail = new_node;
    }
    lst->size++;
    printf("🔗 [뒤] 요소 %d 추가 완료\n", value);
}

// 6. 앞에 요소 추가 (C++의 push_front)
void push_front(List* lst, int value) {
    Node* new_node = create_node(value);
    
    if (lst->size == 0) {
        lst->head = new_node;
        lst->tail = new_node;
    } else {
        // 기존 head의 이전에 새 노드 연결
        lst->head->prev = new_node;
        // 새 노드의 다음을 기존 head로 연결
        new_node->next = lst->head;
        // head 포인터를 새 노드로 갱신
        lst->head = new_node;
    }
    lst->size++;
    printf("🔗 [앞] 요소 %d 추가 완료\n", value);
}

// 7. 전체 리스트 출력 (순방향 탐색)
void print_list(List* lst) {
    printf("\n--- 리스트 내용 출력 (앞 -> 뒤) ---\n");
    Node* current = lst->head;
    while (current != NULL) {
        printf("[%d] ", current->data);
        current = current->next; // 다음 노드로 이동
    }
    printf("\n(총 %zu개)\n\n", lst->size);
}

// 8. 메모리 해제 함수 (모든 노드 정리)
void free_list(List* lst) {
    Node* current = lst->head;
    while (current != NULL) {
        Node* next_node = current->next; // 다음 노드 주소 임시 저장
        free(current);                   // 현재 노드 메모리 해제
        current = next_node;             // 다음 노드로 이동
    }
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}

int main() {
    List my_list;
    init_list(&my_list);
    
    // 뒤로 데이터 추가
    push_back(&my_list, 10);
    push_back(&my_list, 20);
    push_back(&my_list, 30);
    
    // 앞으로 데이터 추가
    push_front(&my_list, 5);
    push_front(&my_list, 1);
    
    // 결과 출력
    print_list(&my_list);
    
    // 메모리 정리
    free_list(&my_list);
    
    return 0;
}
