#include <iostream>
#include <vector>

using namespace std;

// 누적 합 배열을 미리 만들어주는 함수
vector<int> makePrefixSum(const vector<int>& arr) {
    int n = arr.size() - 1; // 0번 인덱스는 비워두었으므로 실제 데이터 개수는 size - 1
    
    // 누적 합을 저장할 배열 (원본과 똑같이 n+1 크기로 만듦)
    vector<int> prefixSum(n + 1, 0);

    // 1번 인덱스부터 n번 인덱스까지 차례대로 누적 합 계산
    for (int i = 1; i <= n; i++) {
        // 현재 위치의 누적 합 = 바로 직전까지의 누적 합 + 현재 원소의 값
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    return prefixSum;
}

// 특정 구간(left ~ right)의 합을 아주 빠르게 구하는 함수
int getRangeSum(const vector<int>& prefixSum, int left, int right) {
    // right까지의 전체 합에서, left 바로 앞(left - 1)까지의 합을 덜어냅니다.
    return prefixSum[right] - prefixSum[left - 1];
}

int main() {
    // 1. 원본 데이터 배열 (계산을 쉽게 하기 위해 0번 인덱스는 0으로 비워두고 1번부터 씁니다)
    // 인덱스:        0,  1,  2,  3,  4,  5
    vector<int> arr = {0, 10, 20, 30, 40, 50};

    cout << "원본 데이터: ";
    for (int i = 1; i < arr.size(); i++) cout << arr[i] << " ";
    cout << "\n\n";

    // 2. 누적 합 메모장 만들기 (이 작업은 단 한 번만 하면 됩니다!)
    vector<int> prefixSum = makePrefixSum(arr);

    cout << "누적 합 메모장: ";
    for (int i = 1; i < prefixSum.size(); i++) cout << prefixSum[i] << " ";
    cout << "\n\n";

    // 3. 쏜살같이 빠른 구간 합 쿼리 처리
    // 예제 1: 2번째 원소(20)부터 4번째 원소(40)까지의 합 구하기
    int left1 = 2, right1 = 4;
    cout << left1 << "번째부터 " << right1 << "번째까지의 합: " 
         << getRangeSum(prefixSum, left1, right1) << "\n"; // 기대값: 20+30+40 = 90

    // 예제 2: 1번째 원소(10)부터 5번째 원소(50)까지의 전체 합 구하기
    int left2 = 1, right2 = 5;
    cout << left2 << "번째부터 " << right2 << "번째까지의 합: " 
         << getRangeSum(prefixSum, left2, right2) << "\n"; // 기대값: 150

    return 0;
}
