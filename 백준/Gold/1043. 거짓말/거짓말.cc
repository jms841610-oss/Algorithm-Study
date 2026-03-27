#include <iostream>
#include <vector>

using namespace std;

// 💡 진실을 아는 사람과 연결된 모든 사람을 찾는 DFS (깊이 우선 탐색) 함수
void DFS(int current, vector<vector<int>> &graph, vector<bool> &is_visited){
    // 1. 현재 노드(사람)를 방문 처리 (진실을 아는 사람으로 표시)
    is_visited[current] = true;

    // 2. 현재 사람과 연결된(같은 파티에 참석한 적 있는) 다른 사람들을 확인
    for(int i=0; i<graph[current].size(); i++){
        // 3. 연결된 사람 중 아직 방문하지 않은 사람(진실을 모르는 사람)이 있다면
        if(!is_visited[graph[current][i]]){
            // 재귀적으로 DFS를 호출하여 그 사람도 진실을 알게 됨을 표시
            DFS(graph[current][i], graph, is_visited);
        }
    }
    return;
}

int main(){
    // 입출력 속도 향상을 위한 설정 (C++ 알고리즘 풀이 필수 세팅)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M; // N: 사람의 수, M: 파티의 수

    // 그래프 생성 (사람 번호가 1번부터 시작하므로 크기를 N+1로 설정)
    vector<vector<int>> graph(N+1);
    // 각 파티에 참석하는 사람들의 목록을 저장하는 배열
    vector<vector<int>> party(M);
    // 해당 사람이 진실을 아는지 여부를 저장하는 배열 (true면 아는 사람)
    vector<bool> is_visited(N+1, false);

    int n;
    cin >> n; // 최초로 이야기의 진실을 아는 사람의 수

    vector<int> start(n);

    // 최초로 진실을 아는 사람들의 번호를 배열에 저장
    for(int i=0; i<n; i++){
        cin >> start[i];
    }

    // [입력 파트] 각 파티별 참석자 정보 입력받기
    for(int i=0; i<M; i++){
        int m;
        cin >> m; // 해당 파티에 오는 사람의 수

        for(int j=0; j<m; j++){
            int node;
            cin >> node;
            party[i].push_back(node); // 파티 배열에 참석자 번호 추가
        }
    }

    // 💡 핵심 로직 1: 같은 파티에 참석한 사람들을 그래프로 모두 연결
    for(int i=0; i<M; i++){
        for(int j=0; j<party[i].size(); j++){
            for(int k=0; k<party[i].size(); k++){
                // 파티 참석자들끼리 서로 양방향 간선을 만들어 줌
                // (자기 자신과는 연결할 필요가 없으므로 j != k 일 때만 추가)
                if(j != k) graph[party[i][j]].push_back(party[i][k]);
            }
        }
    }

    // 💡 핵심 로직 2: 최초로 진실을 아는 사람들을 시작점으로 DFS 탐색
    // 이 탐색을 마치면, 진실을 건너건너 전해 듣게 될 모든 사람이 is_visited에 true로 체크됨
    for(int i=0; i<n; i++){
        DFS(start[i], graph, is_visited);
    }

    int ans = 0; // 거짓말(과장된 이야기)을 할 수 있는 파티의 수

    // 💡 핵심 로직 3: 각 파티를 확인하며 거짓말 가능 여부 판별
    for(int i=0; i<M; i++){
        bool possible = true; // 우선 거짓말이 가능하다고 가정
        
        for(int j=0; j<party[i].size(); j++){
            // 파티 참석자 중 단 한 명이라도 진실을 아는 사람이 있다면 (is_visited == true)
            if(is_visited[party[i][j]]){
                possible = false; // 거짓말을 할 수 없음
                break;            // 더 이상 확인할 필요 없이 해당 파티 탐색 중단
            }
        }
        
        // 참석자 전원이 진실을 모를 경우에만 정답 카운트 증가
        if(possible){
            ans++;
        }
    }

    // 최종적으로 거짓말을 할 수 있는 파티의 최대 개수 출력
    cout << ans << "\n";
    return 0;
}
