#include <iostream>
#include <vector>
#include <algorithm> // min, max 함수 사용을 위해 명시적으로 추가 권장

using namespace std;

int row, col;
int matrix_sum = 0;
// 주의: 문제의 입력 범위에 따라 초기화 값이 충분히 크거나 작지 않을 수 있음
int matrix_min = 100000;
int matrix_max = -100000;

// 원본 데이터를 저장할 2차원 배열
vector<vector<int>> matrix(50, vector<int>(50, 0));
// 🌟 [핵심 최적화]: 매번 행렬을 업데이트하지 않고, 각 행과 열에 더해질 값을 누적해두는 1차원 배열
vector<int> row_add(50, 0);
vector<int> col_add(50, 0);

// 모든 쿼리가 끝난 후, 원본 배열과 누적된 변화량을 한 번에 계산하는 함수
void solving(){
    for(int y = 0; y < row; y++){
        for(int x = 0; x < col; x++){
            // 원본 값 + 해당 행에 누적된 더하기 값 + 해당 열에 누적된 더하기 값
            int val = matrix[y][x] + row_add[y] + col_add[x];
            
            matrix_sum += val;
            matrix_min = min(matrix_min, val);
            matrix_max = max(matrix_max, val);
        }
    }
    return;
}

int main(){
    // Fast I/O: 입출력 속도 향상을 위한 동기화 해제
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> row >> col;

    // 초기 행렬 상태 입력
    for(int y = 0; y < row; y++){
        for(int x = 0; x < col; x++){
            int val;
            cin >> val;
            matrix[y][x] = val;
        }
    }
    
    int Q;
    cin >> Q;

    // Q개의 쿼리 처리 (O(1) 시간 복잡도로 누적만 수행)
    for(int i = 0; i < Q; i++){
        string order;
        int k, val;
        cin >> order >> k >> val;
        
        // 직접 배열을 순회하지 않고, 변화량만 기록 (인덱스는 0부터 시작하므로 k-1)
        if      (order == "row") row_add[k-1] += val;
        else if (order == "col") col_add[k-1] += val;
    }
    
    // 기록된 변화량을 바탕으로 최종 결과 도출
    solving();

    cout << matrix_sum << " " << matrix_min << " " << matrix_max << '\n'; // endl 대신 '\n' 사용 권장

    return 0;
}
