#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 노드의 개수를 저장할 변수
int N;

// 1번 노드를 제외한 나머지 노드들을 중복 없이, 오름차순으로 저장하기 위한 set
// (나중에 2번 노드부터 순서대로 부모를 출력할 때 유용합니다)
set<int> node;

// 그래프의 간선 정보를 저장하는 인접 리스트
// edge[u]는 노드 u와 연결된 모든 노드들의 목록을 담습니다.
// 최대 노드 개수가 100,000개라고 가정하여 크기를 100,001로 할당했습니다.
vector<vector<int>> edge(100001);

// 각 노드의 부모 노드를 저장하는 배열 (초기값은 모두 1)
vector<int> parent(100001, 1);
// 재귀 호출 시 무한 루프에 빠지지 않도록 방문 여부를 체크하는 배열
vector<bool> is_visited(100001, false);

// 깊이 우선 탐색(DFS)을 이용해 부모 노드를 찾는 재귀 함수
void find(int current) {
    // 현재 노드(current)와 연결된 모든 노드들을 하나씩 확인합니다.
    for(int i = 0; i < edge[current].size(); i++) {
        int next_node = edge[current][i]; // 다음으로 방문할 후보 노드
        
        // 아직 방문하지 않은 노드라면? (즉, 내 자식 노드라면)
        if(!is_visited[next_node]) {
            // 1. 다음 노드의 부모를 '현재 노드'로 기록합니다.
            parent[next_node] = current;
            // 2. 방문 처리하여 중복 탐색을 막습니다.
            is_visited[next_node] = true;
            // 3. 자식 노드로 이동하여 동일한 과정을 반복(재귀)합니다.
            find(next_node);
        }
    }
    return; // 더 이상 연결된 미방문 노드가 없으면 함수를 종료하고 이전 호출로 돌아갑니다.
}

int main() {
    // C++ 입출력 속도를 높이기 위한 최적화 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    // 간선 정보 입력받기
    // 주의: 보통 N개의 노드를 가진 트리의 간선은 N-1개입니다.
    // 만약 문제에서 주어지는 간선이 N개라면 이 반복문이 맞지만, 
    // 간선이 N-1개라면 i < N-1 로 수정해야 할 수도 있습니다!
    for(int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;

        // 1번(루트) 노드가 아니라면 set에 추가하여 출력 목록을 구성합니다.
        if(u != 1) node.insert(u);
        if(v != 1) node.insert(v);

        // 양방향 간선으로 연결해 줍니다. (누가 부모인지 아직 모르기 때문)
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    
    // 탐색의 시작점인 루트 노드(1번) 방문 처리
    is_visited[1] = true;
    // 1번 노드부터 DFS 탐색 시작
    find(1);

    // set은 자동으로 오름차순 정렬이 되므로, 작은 번호의 노드부터 순회합니다.
    for(const int ele : node) {
        // 미리 기록해둔 각 노드의 부모(parent)를 출력합니다.
        cout << parent[ele] << "\n";
    }
    
    return 0;
}
