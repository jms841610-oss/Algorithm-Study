#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 후위 순회 (Post-order Traversal) 함수를 더 직관적으로 정리했습니다.
void back_order(int current_idx, vector<vector<int>> &tree, unordered_map<int,int> &key){
    if(current_idx == -1) return; // 빈 노드에 도달하면 리턴

    // 왼쪽 자식 탐색
    back_order(tree[current_idx][0], tree, key);
    // 오른쪽 자식 탐색
    back_order(tree[current_idx][1], tree, key);

    // 현재 노드 출력 (후위 순회: 좌 -> 우 -> 루트)
    cout << key[current_idx] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int,int> key;
    int key_val;
    int cnt = 0;

    while(cin >> key_val){
        key[cnt++] = key_val;
    }

    if(cnt == 0) return 0; // 입력이 없는 경우 방어 코드

    // 트리를 2차원 벡터로 구성 [왼쪽 자식 인덱스, 오른쪽 자식 인덱스]
    vector<vector<int>> tree(cnt, vector<int>(2, -1));

    // 1번 인덱스부터 끝까지 트리에 삽입
    for(int i = 1; i < cnt; i++){
        int current_idx = 0; // 새 노드를 넣을 때마다 항상 루트(0번)에서 시작!
        int node_val = key[i];

        // 빈 자리를 찾을 때까지 무한 반복하며 파고 내려갑니다.
        while(true){
            if(node_val < key[current_idx]){
                // 왼쪽으로 가야 하는 경우
                if(tree[current_idx][0] == -1){ 
                    tree[current_idx][0] = i; // 비어있으면 연결하고 종료
                    break;
                } else {
                    current_idx = tree[current_idx][0]; // 비어있지 않으면 계속 내려감
                }
            } else {
                // 오른쪽으로 가야 하는 경우
                if(tree[current_idx][1] == -1){
                    tree[current_idx][1] = i; // 비어있으면 연결하고 종료
                    break;
                } else {
                    current_idx = tree[current_idx][1]; // 비어있지 않으면 계속 내려감
                }
            }
        }
    }
    
    // 루트(0번 인덱스)부터 후위 순회 시작
    back_order(0, tree, key);
    return 0;
}
