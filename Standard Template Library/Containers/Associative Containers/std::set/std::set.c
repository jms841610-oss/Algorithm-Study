#include <stdio.h>
#include <stdlib.h>

// 1. 트리 노드 구조체 정의
typedef struct Node {
    int data;               // 실제 저장되는 데이터
    struct Node* left;      // 자신보다 작은 값을 가진 왼쪽 자식
    struct Node* right;     // 자신보다 큰 값을 가진 오른쪽 자식
} Node;

// 2. 새로운 노드를 생성하는 함수
Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("메모리 할당 실패!\n");
        exit(1);
    }
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// 3. 요소 추가 함수 (C++의 insert)
// 반환값: 트리의 새로운(또는 기존) 루트 노드 포인터
Node* insert(Node* root, int value) {
    // 트리가 비어있거나, 들어갈 빈자리를 찾은 경우 새 노드를 반환하여 연결
    if (root == NULL) {
        printf("🌱 노드 추가 완료: %d\n", value);
        return create_node(value);
    }
    
    // 추가하려는 값이 현재 노드의 값보다 작으면 왼쪽으로!
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // 추가하려는 값이 현재 노드의 값보다 크면 오른쪽으로!
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // 이미 존재하는 값이라면 (중복) 아무것도 하지 않음! (이것이 std::set의 특징)
    else {
        printf("⚠️ 중복 데이터 무시됨: %d\n", value);
    }
    
    return root; // 변경된 트리(현재 노드)를 다시 반환
}

// 4. 특정 데이터 존재 여부 확인 (C++의 find)
int contains(Node* root, int value) {
    if (root == NULL) return 0; // 찾지 못함 (false)
    
    if (root->data == value) return 1; // 찾음 (true)
    
    if (value < root->data) return contains(root->left, value);
    else return contains(root->right, value);
}

// 5. 트리를 정렬된 순서로 출력 (중위 순회: Inorder Traversal)
// 왼쪽 자식 -> 나 자신 -> 오른쪽 자식 순서로 방문하면 자동으로 오름차순 정렬이 됩니다!
void print_inorder(Node* root) {
    if (root != NULL) {
        print_inorder(root->left);     // 나보다 작은 애들 먼저 다 출력해
        printf("%d ", root->data);     // 그다음 나를 출력해
        print_inorder(root->right);    // 마지막으로 나보다 큰 애들 다 출력해
    }
}

// 6. 메모리 해제 함수 (후위 순회 방식)
void free_tree(Node* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    Node* my_set = NULL; // 트리의 루트 노드를 NULL로 초기화
    
    printf("--- 데이터 추가 시작 ---\n");
    // 순서가 뒤죽박죽으로 들어와도 트리가 알아서 자리를 잡습니다.
    my_set = insert(my_set, 50);
    my_set = insert(my_set, 30);
    my_set = insert(my_set, 70);
    my_set = insert(my_set, 20);
    my_set = insert(my_set, 40);
    
    // 중복 데이터 삽입 시도
    my_set = insert(my_set, 30); 
    my_set = insert(my_set, 50);
    
    printf("\n--- set의 내용 출력 (자동 오름차순 정렬됨) ---\n[ ");
    print_inorder(my_set);
    printf("]\n");
    
    printf("\n--- 데이터 검색 ---\n");
    printf("40이 존재하나요? %s\n", contains(my_set, 40) ? "네" : "아니요");
    printf("90이 존재하나요? %s\n", contains(my_set, 90) ? "네" : "아니요");
    
    // 메모리 정리
    free_tree(my_set);
    
    return 0;
}
