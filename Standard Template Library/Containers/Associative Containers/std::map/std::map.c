#include <stdio.h>
#include <stdlib.h>

// 1. 맵 노드 구조체 정의 (Key와 Value를 함께 가집니다)
typedef struct Node {
    int key;                // 기준이 되는 키 (예: 학번)
    int value;              // 실제 데이터 (예: 점수)
    struct Node* left;      // 키가 더 작은 왼쪽 자식
    struct Node* right;     // 키가 더 큰 오른쪽 자식
} Node;

// 2. 새로운 노드를 생성하는 함수
Node* create_node(int key, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("메모리 할당 실패!\n");
        exit(1);
    }
    new_node->key = key;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// 3. 요소 추가 및 수정 함수 (C++의 map[key] = value 동작)
Node* insert_or_assign(Node* root, int key, int value) {
    // 빈자리를 찾으면 새로운 키-값 쌍을 만들어 연결
    if (root == NULL) {
        printf("🌱 새 데이터 추가됨 - 키: %d, 값: %d\n", key, value);
        return create_node(key, value);
    }
    
    // 삽입하려는 키가 현재 노드의 키보다 작으면 왼쪽으로!
    if (key < root->key) {
        root->left = insert_or_assign(root->left, key, value);
    }
    // 삽입하려는 키가 현재 노드의 키보다 크면 오른쪽으로!
    else if (key > root->key) {
        root->right = insert_or_assign(root->right, key, value);
    }
    // 이미 존재하는 키를 만났다면? 값을 덮어씁니다! (Update)
    else {
        printf("🔄 기존 데이터 수정됨 - 키: %d, 값: %d -> %d\n", key, root->value, value);
        root->value = value;
    }
    
    return root;
}

// 4. 특정 키를 검색하여 값을 반환하는 함수 (C++의 map.find 또는 map[key])
// 값을 찾으면 해당 값의 포인터를 반환하고, 없으면 NULL을 반환합니다.
int* find_value(Node* root, int key) {
    if (root == NULL) return NULL; // 키를 찾지 못함
    
    if (key == root->key) {
        return &(root->value); // 키를 찾음! 값의 메모리 주소 반환
    }
    
    if (key < root->key) return find_value(root->left, key);
    else return find_value(root->right, key);
}

// 5. 맵의 전체 내용을 정렬된 상태로 출력 (중위 순회)
// 키를 기준으로 중위 순회를 하므로, 키가 오름차순으로 예쁘게 정렬되어 출력됩니다.
void print_map(Node* root) {
    if (root != NULL) {
        print_map(root->left);
        printf("[키: %d] -> 값: %d\n", root->key, root->value);
        print_map(root->right);
    }
}

// 6. 메모리 해제 함수
void free_map(Node* root) {
    if (root != NULL) {
        free_map(root->left);
        free_map(root->right);
        free(root);
    }
}

int main() {
    Node* my_map = NULL;
    
    printf("--- 데이터 추가 및 수정 시작 ---\n");
    // 학번(Key)과 점수(Value)를 맵에 넣습니다.
    my_map = insert_or_assign(my_map, 202301, 85);
    my_map = insert_or_assign(my_map, 202303, 92);
    my_map = insert_or_assign(my_map, 202302, 78);
    
    // 똑같은 학번(Key)으로 다른 점수(Value)를 넣으면 값이 덮어씌워집니다.
    my_map = insert_or_assign(my_map, 202301, 99); 
    
    printf("\n--- map의 전체 내용 출력 (키 오름차순 정렬) ---\n");
    print_map(my_map);
    
    printf("\n--- 특정 키(학번) 검색 ---\n");
    int search_key1 = 202302;
    int* result1 = find_value(my_map, search_key1);
    if (result1 != NULL) printf("학번 %d의 점수는 %d점 입니다.\n", search_key1, *result1);
    else printf("학번 %d를 찾을 수 없습니다.\n", search_key1);

    int search_key2 = 202305;
    int* result2 = find_value(my_map, search_key2);
    if (result2 != NULL) printf("학번 %d의 점수는 %d점 입니다.\n", search_key2, *result2);
    else printf("학번 %d를 찾을 수 없습니다.\n", search_key2);
    
    free_map(my_map);
    return 0;
}
