#include <iostream>
#include <vector>

using namespace std;

// 특정 사람(target)이 현재 팀(v)에 들어갈 수 있는지 확인하는 함수
bool is_possible(int target, vector<int> &v, vector<vector<bool>> &hate){
    bool possible = true;

    // 현재 팀(v)에 속해 있는 모든 사람들과 target의 관계를 확인
    for(int i=0; i<v.size(); i++){
        // 팀원 중 한 명이라도 target과 '싫어하는 관계(hate)'라면
        if(hate[v[i]][target]){
            possible = false; // 팀에 들어갈 수 없음
            break;            // 더 이상 확인할 필요 없이 반복문 종료
        }
    }
    return possible;
}

int main(){
    // C++ 입출력 속도 향상을 위한 설정 (시간 초과 방지)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    // N: 사람의 수, M: 서로 싫어하는 관계의 수
    cin >> N >> M;

    // hate[A][B] = true 이면 A와 B는 서로 싫어하는 관계 (인접 행렬 방식)
    // 사람 번호가 1번부터 시작하므로 크기를 N+1로 설정
    vector<vector<bool>> hate(N+1, vector<bool>(N+1, false));
    
    // 각 사람이 팀에 배정되었는지 여부를 확인하는 배열
    vector<bool> is_visited(N+1, false);
    
    // 완성된 팀들을 저장할 2차원 배열 (팀들의 집합)
    vector<vector<int>> team;

    // 싫어하는 관계 입력받기
    for(int i=0; i<M; i++){
        int A, B;
        cin >> A >> B;

        // 양방향으로 서로 싫어함을 표시
        hate[A][B] = true;
        hate[B][A] = true;
    }

    // 1번 사람부터 N번 사람까지 순회하며 팀 구성
    for(int i=1; i<=N; i++){
        // i번째 사람이 아직 어떤 팀에도 배정되지 않았다면 새로운 팀 생성 시작
        if(!is_visited[i]){
            vector<int> v;      // 새로운 팀 생성
            v.push_back(i);     // 새로운 팀에 i번째 사람 추가
            is_visited[i] = true; // i번째 사람 방문(배정) 처리

            // i번째 사람과 같은 팀이 될 수 있는 다른 사람들을 찾음
            for(int j=1; j<=N; j++){
                // j번째 사람이 아직 팀이 없다면
                if(!is_visited[j]){
                    // j번째 사람이 현재 팀(v)에 들어갈 수 있는지 확인
                    if(is_possible(j, v, hate)){
                        v.push_back(j);     // 팀에 추가
                        is_visited[j] = true; // 방문(배정) 처리
                    }
                }
            }
            // 구성이 완료된 팀(v)을 전체 팀 목록(team)에 추가
            team.push_back(v);
        }
    }

    // 결과 출력: 만들어진 전체 팀의 개수
    cout << team.size() << "\n";

    // 결과 출력: 각 팀의 팀원 목록
    for(int i=0; i<team.size(); i++){
        // 범위 기반 for문을 사용하여 팀(team[i]) 내의 모든 팀원(ele) 출력
        for(const int& ele : team[i]){
            cout << ele << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    
    return 0;
}
