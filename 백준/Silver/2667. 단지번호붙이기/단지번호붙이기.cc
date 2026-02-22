#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 지도의 크기 (N x N)

// 지도 정보와 방문 여부를 저장할 2차원 벡터 
// (문제의 최대 크기인 25로 여유 있게 초기화)
vector<vector<bool>> is_house(25, vector<bool>(25, false));
vector<vector<bool>> is_visited(25, vector<bool>(25, false));

// 각 단지별 집의 개수를 저장할 배열
vector<int> house_num;

// 상하좌우 탐색을 위한 방향 벡터 설정 (dy: 행, dx: 열)
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

// DFS를 활용하여 연결된 집(단지)을 탐색하는 함수
// num은 참조자(&)로 받아 원본 변수의 값을 직접 증가시킴
void visiting(int row, int col, int& num) {
    is_visited[row][col] = true; // 현재 위치 방문 처리
    num++; // 현재 단지의 집 개수 1 증가

    // 4방향(상, 하, 좌, 우) 인접 칸 탐색
    for(int i = 0; i < 4; i++) {
        int next_y = row + dy[i];
        int next_x = col + dx[i];

        // 1. 다음 탐색할 좌표가 지도 범위(0 ~ N-1) 내에 있는지 경계 검사
        if((0 <= next_y) && (next_y < N) && (0 <= next_x) && (next_x < N)) {
            // 2. 아직 방문하지 않았고, 해당 칸에 집이 존재한다면 연속된 단지로 간주하여 재귀 호출
            if((!is_visited[next_y][next_x]) && (is_house[next_y][next_x])) {
                visiting(next_y, next_x, num);
            }
        }
    }
    return;
}

// 지도를 전체 순회하며 새로운 단지의 시작점을 찾는 함수
void get_num() {
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            // 집이 존재하지만 아직 방문하지 않은 좌표 = '새로운 단지의 시작점'
            if((is_house[row][col]) && (!is_visited[row][col])) {
                int num = 0; // 새로운 단지의 집 개수 카운트 초기화
                visiting(row, col, num);  // DFS 시작
                house_num.push_back(num); // 탐색 종료 후 완성된 단지 크기를 벡터에 저장
            }
        }
    }
    return;
}

int main() {
    // C++ 표준 입출력 동기화 해제로 실행 속도 최적화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    // 지도 데이터 입력 처리
    for(int row = 0; row < N; row++) {
        string line;
        cin >> line; // 띄어쓰기 없이 입력되므로 string으로 한 줄 통째로 받음

        // 문자열의 각 문자를 확인하여 '1'인 경우 집으로 마킹
        for(int col = 0; col < N; col++) {
            if(line[col] == '1') is_house[row][col] = true;
        }
    }
    
    get_num(); // 단지 탐색 로직 실행

    // 문제 요구사항에 따라 단지 내 집의 수를 오름차순 정렬
    sort(house_num.begin(), house_num.end());

    // 총 단지 수 출력
    cout << house_num.size() << "\n";

    // 각 단지별 집의 개수 출력
    for(int i = 0; i < house_num.size(); i++) {
        cout << house_num[i] << "\n";
    }
    
    return 0;
}
