#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 정답을 저장할 전역 변수 (가장 큰 값으로 초기화)
int ans = 2e9; 

// DFS 함수: 조합(Combination) 방식으로 M개를 선택하고, 즉시 최솟값을 계산합니다.
void DFS(int depth, int start, int M, vector<pair<int,int>> &arr, const vector<pair<int,int>> &arrive, const vector<pair<int,int>> &depart){
    // 목표한 M개를 모두 선택했을 때
    if(depth == M){
        int tmp_sum = 0;
        
        // 각 출발지(depart)에 대해 가장 가까운 도착지(arr 안의 요소)를 찾습니다.
        for(const auto& d : depart){
            int min_dist = 2e9;
            for(const auto& c : arr){
                int dist = abs(c.first - d.first) + abs(c.second - d.second);
                min_dist = min(min_dist, dist);
            }
            tmp_sum += min_dist;
        }
        
        // 기존의 최솟값과 현재 조합의 거리 합을 비교하여 더 작은 값으로 갱신합니다.
        ans = min(ans, tmp_sum);
        return;
    }

    // start 인덱스부터 탐색하여 중복 선택(순열)을 방지합니다.
    for(int i = start; i < arrive.size(); i++){
        arr.push_back(arrive[i]); // 도착지 선택
        
        // 다음 깊이로 이동, 다음 선택은 i+1 번부터 하도록 넘겨줌
        DFS(depth + 1, i + 1, M, arr, arrive, depart); 
        
        arr.pop_back(); // 탐색이 끝나면 선택한 도착지를 다시 빼줌 (백트래킹)
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<pair<int,int>> depart;
    vector<pair<int,int>> arrive;
    vector<pair<int,int>> arr; // DFS 중 현재 선택된 M개의 도착지를 담을 벡터

    depart.reserve(N*N);
    arrive.reserve(N*N);

    // 입력 받기
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            int input;
            cin >> input;

            if(input == 1){
                depart.push_back({y,x});
            }else if(input == 2){
                arrive.push_back({y,x});
            }
        }
    }

    // DFS 탐색 시작: 깊이 0, 시작 인덱스 0
    DFS(0, 0, M, arr, arrive, depart);

    // 정답 출력
    cout << ans << "\n";
    return 0;
}
