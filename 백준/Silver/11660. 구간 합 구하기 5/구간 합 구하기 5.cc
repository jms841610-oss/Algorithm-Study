#include <iostream>
#include <vector>

using namespace std;

int main(){
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    // 1-based indexing을 사용하기 위해 크기를 N+1로 설정합니다.
    // 인덱스 0 부분은 0으로 채워져 있으므로 예외 처리가 필요 없습니다.
    vector<vector<int>> stable(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> total(N + 1, vector<int>(N + 1, 0));

    // 1. 배열 입력 받기 (1번 인덱스부터 시작)
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> stable[i][j];
        }
    }

    // 2. 2차원 누적 합(Prefix Sum) 계산하기
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            total[i][j] = total[i-1][j] + total[i][j-1] - total[i-1][j-1] + stable[i][j];
        }
    }

    // 3. M개의 구간 합 쿼리 처리하기 (O(1) 시간 복잡도)
    for(int i = 0; i < M; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 공식을 이용하여 단 한 번의 계산으로 답을 도출합니다.
        int ans = total[x2][y2] - total[x1-1][y2] - total[x2][y1-1] + total[x1-1][y1-1];
        
        cout << ans << "\n";
    }

    return 0;
}
