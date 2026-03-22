#include <stdio.h>
#include <stdlib.h>

// 1. 트리 노드 구조체 정의 (set과 동일)
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 2. 새로운 노드를 생성하는 함수 (set과 동일)
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

// 3. 요소 추가 함수 (C++의 insert) - ★ 여기가 multiset의 핵심!
Node* insert(Node* root, int value) {
    if (root == NULL) {
        printf("🌱 노드 추가 완료: %d\n", value);
        return create_node(value);
    }
    
    // 추가하려는 값이 현재 노드의 값보다 엄격히 작으면 왼쪽으로!
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // 추가하려는 값이 현재 노드의 값보다 크거나 **같으면** 오른쪽으로!
    // (이 조건 덕분에 중복 데이터가 무시되지 않고 트리에 추가됩니다)
    else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// 4. 특정 데이터의 개수 세기 (C++의 count) - multiset의 필수 기능
int count(Node* root, int value) {
    if (root == NULL) return 0; // 찾지 못함
    
    // 찾는 값이 더 작으면 왼쪽 탐색
    if (value < root->data) {
        return count(root->left, value);
    }
    // 찾는 값이 더 크면 오른쪽 탐색
    else if (value > root->data) {
        return count(root->right, value);
    }
    // 값을 찾은 경우! (value == root->data)
    else {
        // 나 자신(1) + 내 오른쪽 자식들 중에도 똑같은 값이 있는지 계속 탐색
        return 1 + count(root->right, value);
    }
}

// 5. 트리를 정렬된 순서로 출력 (중위 순회)
void print_inorder(Node* root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}

// 6. 메모리 해제 함수
void free_tree(Node* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    Node* my_multiset = NULL;
    
    printf("--- 데이터 추가 시작 ---\n");
    // 동일한 데이터를 여러 번 넣어봅니다.
    my_multiset = insert(my_multiset, 50);
    my_multiset = insert(my_multiset, 30);
    my_multiset = insert(my_multiset, 30); // 중복 데이터!
    my_multiset = insert(my_multiset, 70);
    my_multiset = insert(my_multiset, 30); // 또 중복 데이터!
    my_multiset = insert(my_multiset, 50); // 또또 중복 데이터!
    
    printf("\n--- multiset의 내용 출력 (자동 오름차순 & 중복 허용) ---\n[ ");
    print_inorder(my_multiset);
    printf("]\n");
    
    printf("\n--- 데이터 개수 확인 ---\n");
    printf("30의 개수: %d개\n", count(my_multiset, 30));
    printf("50의 개수: %d개\n", count(my_multiset, 50));
    printf("90의 개수: %d개\n", count(my_multiset, 90));
    
    free_tree(my_multiset);
    return 0;
}
