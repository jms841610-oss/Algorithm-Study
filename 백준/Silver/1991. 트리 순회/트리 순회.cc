#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// [트리 자료구조 정의]
// 키(Key): 부모 노드의 이름 (예: 'A')
// 값(Value): 자식 노드들을 담은 크기 2짜리 벡터 
//           (인덱스 0: 왼쪽 자식, 인덱스 1: 오른쪽 자식)
unordered_map<char,vector<char>> tree;

// 1. 전위 순회 (Preorder): 나 -> 왼쪽 -> 오른쪽
void preorder(char root){
    // [종료 조건] 문제에서 자식이 없는 경우 '.'으로 주어집니다.
    // 앞서 이야기했던 "방문할 노드가 비어있을 때" 돌아간다는 바로 그 부분입니다!
    if(root == '.'){
        return;
    }
    cout << root; // 1. [내 데이터 처리] 현재 노드를 먼저 출력합니다.

    preorder(tree[root][0]); // 2. 왼쪽 자식으로 재귀 이동

    preorder(tree[root][1]); // 3. 오른쪽 자식으로 재귀 이동
}

// 2. 중위 순회 (Inorder): 왼쪽 -> 나 -> 오른쪽
void inorder (char root){
    if(root == '.'){ // [종료 조건]
        return;
    }
    inorder(tree[root][0]); // 1. 왼쪽 자식을 향해 끝까지 들어갑니다.

    cout << root; // 2. [내 데이터 처리] 왼쪽을 다 보고 돌아왔을 때 현재 노드 출력

    inorder(tree[root][1]); // 3. 오른쪽 자식으로 재귀 이동
}

// 3. 후위 순회 (Postorder): 왼쪽 -> 오른쪽 -> 나
void postorder (char root){
    if(root == '.'){ // [종료 조건]
        return;
    }
    postorder(tree[root][0]); // 1. 왼쪽 자식 끝까지 방문

    postorder(tree[root][1]); // 2. 오른쪽 자식 끝까지 방문

    cout << root; // 3. [내 데이터 처리] 자식들을 모두 다 보고 나서야 마지막으로 내 노드 출력
}

int main(){
    // [최적화] C++ 입출력 속도를 높여주는 마법의 코드입니다. 
    // 알고리즘 문제 풀이에서 시간 초과를 막기 위해 아주 유용합니다.
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N; // 노드의 개수 입력

    // N번 반복하며 트리의 구조를 만들어 줍니다.
    for(int i = 0; i < N; i++){
        char root;
        vector<char> sub_tree(2);

        // 부모 노드, 왼쪽 자식, 오른쪽 자식 순서대로 입력받기
        cin >> root >> sub_tree[0] >> sub_tree[1];
        
        // 입력받은 관계를 해시맵(트리)에 저장합니다.
        tree.insert({root, sub_tree});
    }
    
    // 항상 'A'가 루트 노드라고 가정하고 탐색을 시작합니다.
    preorder('A');
    cout << "\n";

    inorder('A');
    cout << "\n";

    postorder('A');
    cout << "\n";

    return 0;
}
