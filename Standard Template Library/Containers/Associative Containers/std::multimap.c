#include <stdio.h>
#include <stdlib.h>

// 1. 멀티맵 노드 구조체 정의 (Key와 Value 쌍)
typedef struct Node {
    int key;                // 기준이 되는 키 (예: 과목 코드)
    int value;              // 실제 데이터 (예: 학생의 점수)
    struct Node* left;
    struct Node* right;
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

// 3. 요소 추가 함수 (★ multimap의 핵심: 덮어쓰지 않음!)
Node* insert(Node* root, int key, int value) {
    // 빈자리를 찾으면 새로운 키-값 쌍을 무조건 새로 생성하여 연결
    if (root == NULL) {
        printf("🌱 새 데이터 추가됨 - 키: %d, 값: %d\n", key, value);
        return create_node(key, value);
    }
    
    // 삽입하려는 키가 현재 노드의 키보다 작으면 왼쪽으로!
    if (key < root->key) {
        root->left = insert(root->left, key, value);
    }
    // 삽입하려는 키가 현재 노드의 키보다 크거나 **같으면** 오른쪽으로!
    // (이 조건 덕분에 기존 값을 덮어쓰지 않고 중복 키가 트리에 추가됩니다)
    else {
        root->right = insert(root->right, key, value);
    }
    
    return root;
}

// 4. 특정 키가 가진 값들의 개수를 세는 함수 (C++의 multimap::count)
int count_key(Node* root, int search_key) {
    if (root == NULL) return 0; // 찾지 못함
    
    if (search_key < root->key) {
        return count_key(root->left, search_key);
    } else if (search_key > root->key) {
        return count_key(root->right, search_key);
    } else {
        // 키를 찾았더라도, 오른쪽에 같은 키가 더 있을 수 있으므로 계속 탐색하여 더함!
        return 1 + count_key(root->right, search_key);
    }
}

// 5. 특정 키를 가진 모든 값을 출력하는 함수 (C++의 multimap::equal_range 느낌)
void print_values_for_key(Node* root, int search_key) {
    if (root == NULL) return;
    
    if (search_key < root->key) {
        print_values_for_key(root->left, search_key);
    } else if (search_key > root->key) {
        print_values_for_key(root->right, search_key);
    } else {
        // 키를 찾았을 때 값을 출력하고, 
        printf("  -> 점수: %d\n", root->value);
        // 오른쪽에 같은 키가 더 있을 수 있으므로 마저 탐색!
        print_values_for_key(root->right, search_key);
    }
}

// 6. 멀티맵의 전체 내용을 정렬된 상태로 출력 (중위 순회)
void print_multimap(Node* root) {
    if (root != NULL) {
        print_multimap(root->left);
        printf("[과목: %d] -> 학생 점수: %d\n", root->key, root->value);
        print_multimap(root->right);
    }
}

// 7. 메모리 해제 함수
void free_multimap(Node* root) {
    if (root != NULL) {
        free_multimap(root->left);
        free_multimap(root->right);
        free(root);
    }
}

int main() {
    Node* my_multimap = NULL;
    
    printf("--- 데이터 추가 시작 ---\n");
    // 과목 코드(Key)와 학생 점수(Value)를 넣습니다.
    my_multimap = insert(my_multimap, 101, 85); // 수학 과목 85점
    my_multimap = insert(my_multimap, 102, 92); // 영어 과목 92점
    
    // 똑같은 과목 코드(Key)로 다른 학생들의 점수를 추가해 봅니다. (중복 허용)
    my_multimap = insert(my_multimap, 101, 99); // 수학 과목 99점 추가
    my_multimap = insert(my_multimap, 101, 78); // 수학 과목 78점 추가
    
    printf("\n--- multimap의 전체 내용 출력 (키 오름차순 정렬) ---\n");
    print_multimap(my_multimap);
    
    printf("\n--- 특정 과목(Key)의 데이터 분석 ---\n");
    int target_subject = 101;
    printf("과목 %d의 등록된 점수 개수: %d개\n", target_subject, count_key(my_multimap, target_subject));
    printf("과목 %d의 점수 목록:\n", target_subject);
    print_values_for_key(my_multimap, target_subject);
    
    free_multimap(my_multimap);
    return 0;
}
