#include <iostream>
#include <vector>

using namespace std;

// 각 노드의 부모(대표) 노드를 저장할 배열
vector<int> parent_node;

// 💡 Find 연산: 특정 노드가 속한 그룹의 '루트(대표) 노드'를 찾는 함수
int find(int x) {
    // 자기 자신이 부모라면(즉, 자신이 루트 노드라면) 그대로 반환
    if (parent_node[x] == x) return x;
    
    // 경로 압축(Path Compression) 최적화: 
    // 루트 노드를 찾으면서 거쳐가는 모든 노드의 부모를 바로 루트로 갱신하여 탐색 속도를 높임
    return parent_node[x] = find(parent_node[x]);
}

// 💡 Union 연산: 두 노드가 속한 그룹을 하나로 합치는 함수
void union_nodes(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    
    // 두 노드의 루트가 다르다면(다른 그룹이라면) 하나로 합쳐줌
    if (rootA != rootB) {
        parent_node[rootB] = rootA; // B의 루트를 A의 루트 밑으로 연결
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M; // N: 사람의 수, M: 파티의 수

    // 1. 초기화: 처음에는 모든 사람(노드)이 자기 자신을 루트로 갖는 독립적인 그룹
    parent_node.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        parent_node[i] = i;
    }

    // 2. 진실을 아는 사람들 입력
    int truth_count;
    cin >> truth_count;
    
    vector<int> truth(truth_count);
    for (int i = 0; i < truth_count; i++) {
        cin >> truth[i];
    }

    // 각 파티의 정보를 저장할 배열
    vector<vector<int>> parties(M);

    // 3. 파티 정보 입력 및 Union 수행
    for (int i = 0; i < M; i++) {
        int p_count;
        cin >> p_count;
        
        parties[i].resize(p_count);
        for (int j = 0; j < p_count; j++) {
            cin >> parties[i][j];
            
            // 파티에 2명 이상 있다면, 첫 번째 사람과 나머지 사람들을 모두 같은 그룹으로 묶음(Union)
            if (j > 0) {
                union_nodes(parties[i][j - 1], parties[i][j]);
            }
        }
    }

    // 4. 거짓말 가능 여부 판별
    int ans = 0;
    
    for (int i = 0; i < M; i++) {
        bool can_lie = true;
        
        // 해당 파티에 참석한 사람 중 단 한 명이라도
        for (int j = 0; j < parties[i].size(); j++) {
            int person = parties[i][j];
            
            // 진실을 아는 사람들과 같은 그룹에 속해 있는지(루트가 같은지) 확인
            for (int k = 0; k < truth_count; k++) {
                if (find(person) == find(truth[k])) {
                    can_lie = false; // 같은 그룹이면 거짓말 불가
                    break;
                }
            }
            if (!can_lie) break; // 이미 거짓말을 못 한다면 다음 사람을 확인할 필요 없음
        }
        
        // 파티 참석자 모두가 진실을 아는 사람과 연결되어 있지 않을 때만 카운트
        if (can_lie) {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}