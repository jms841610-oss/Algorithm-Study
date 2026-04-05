#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------
// [1] 두 행렬 A와 B를 곱하는 함수
// 시간 복잡도: O(N^3)
// ---------------------------------------------------------
vector<vector<long long>> product(int N, const vector<vector<long long>> &A, const vector<vector<long long>> &B){
    // 결과를 저장할 N x N 크기의 0으로 초기화된 행렬 생성
    vector<vector<long long>> result(N, vector<long long>(N,0));

    // 3중 for문을 이용한 기본 행렬 곱셈 알고리즘
    for(int col=0; col<N; col++){
        for(int row=0; row<N; row++){
            for(int x=0; x<N; x++){
                // 1000으로 나눈 나머지를 더해줍니다. 
                // (각 곱셈 단계마다 나머지를 구해야 값이 long long 범위를 초과하는 것을 방지할 수 있습니다)
                result[col][row] += (A[col][x] * B[x][row]) % 1000;
            }
            // 덧셈이 모두 끝난 후에도 다시 한번 1000으로 나누어 결과를 안전하게 저장합니다.
            result[col][row] %= 1000;
        }
    }
    return result;
}

// ---------------------------------------------------------
// [2] 분할 정복을 이용해 행렬을 B번 거듭제곱하는 재귀 함수
// 시간 복잡도: O(log B)
// ---------------------------------------------------------
vector<vector<long long>> solve(int N, long long B, const vector<vector<long long>> &matrix){
    // Base Case: 거듭제곱 횟수가 1번 남았을 때 종료
    if(B == 1){
        return matrix;
    }
    
    // 지수가 홀수인 경우 (예: A^5 = A^4 * A)
    // 지수에서 1을 빼서 짝수로 만든 뒤 계산하고, 마지막에 원본 matrix를 한 번 더 곱해줍니다.
    if(B % 2 == 1){
        return product(N, solve(N, B-1, matrix), matrix);
    } 
    // 지수가 짝수인 경우 (예: A^4 = A^2 * A^2)
    else {
        // [핵심 최적화] 절반(B/2)에 대한 계산을 딱 한 번만 수행하여 'half' 변수에 저장합니다.
        // 만약 product(N, solve(N, B/2), solve(N, B/2)) 처럼 작성하면 똑같은 계산을 두 번 하게 되어 
        // 시간 초과가 발생하므로, 반드시 결과를 변수에 담아두고 재사용(메모이제이션)해야 합니다.
        vector<vector<long long>> half = solve(N, B/2, matrix);
        return product(N, half, half);
    }
}

int main(){
    // C++ 입출력 속도를 높이기 위한 필수 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long B; // 지수 B는 매우 큰 수(예: 1000억)일 수 있으므로 반드시 long long을 사용합니다.
    cin >> N >> B;

    // 초기 행렬 상태를 저장할 2차원 벡터 생성
    vector<vector<long long>> matrix(N, vector<long long>(N,0));

    for(int col=0; col<N; col++){
        for(int row=0; row<N; row++){
            long long val;
            cin >> val;
            // [중요한 반례 해결] 
            // 만약 B가 1이고 입력값이 1000이라면, solve 함수에서 B==1 조건에 걸려 
            // 연산 없이 그대로 1000을 출력하게 됩니다 (오답 원인).
            // 이를 방지하기 위해 입력받을 때부터 미리 1000으로 나눈 나머지를 저장해 둡니다.
            matrix[col][row] = val % 1000;
        }
    }
    
    // 거듭제곱 계산 실행
    vector<vector<long long>> answer = solve(N, B, matrix);

    // 결과 출력
    for(int col=0; col<N; col++){
        for(int row=0; row<N; row++){
            cout << answer[col][row] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
