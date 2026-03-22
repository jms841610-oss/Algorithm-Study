#include <iostream>
#include <vector>
#include <algorithm> // 정렬 함수(sort)를 사용하기 위해 필요

using namespace std;

// 이진 탐색 함수
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;                      // 탐색 범위의 시작 인덱스
    int right = arr.size() - 1;        // 탐색 범위의 끝 인덱스

    // 시작점이 끝점보다 커지면 탐색할 범위가 없다는 뜻이므로 종료
    while (left <= right) {
        // 중간 인덱스 계산 (오버플로우 방지를 위해 이렇게 작성하는 것이 안전합니다)
        int mid = left + (right - left) / 2;

        // 1. 중간점의 데이터가 타겟과 일치하는 경우 (탐색 성공)
        if (arr[mid] == target) {
            return mid; // 찾은 데이터의 '인덱스'를 반환
        }
        // 2. 중간점의 데이터보다 타겟이 더 큰 경우 -> 오른쪽 절반 탐색
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // 3. 중간점의 데이터보다 타겟이 더 작은 경우 -> 왼쪽 절반 탐색
        else {
            right = mid - 1;
        }
    }

    // 반복문을 다 돌았는데도 못 찾았다면 -1을 반환
    return -1; 
}

int main() {
    // 1. 탐색할 데이터 배열 (정렬되지 않은 상태)
    vector<int> numbers = {35, 12, 59, 24, 8, 77, 41, 93, 18};
    int target = 41; // 우리가 찾고 싶은 숫자

    cout << "정렬 전 데이터: ";
    for (int num : numbers) cout << num << " ";
    cout << "\n";

    // 2. 이진 탐색을 위해 반드시 데이터를 오름차순으로 정렬합니다.
    sort(numbers.begin(), numbers.end());

    cout << "정렬 후 데이터: ";
    for (int num : numbers) cout << num << " ";
    cout << "\n";

    // 3. 이진 탐색 실행
    int result = binarySearch(numbers, target);

    // 4. 결과 출력
    if (result != -1) {
        cout << "\n성공! 숫자 " << target << "은(는) 정렬된 배열의 " 
             << result << "번째 인덱스에 있습니다.\n";
    } else {
        cout << "\n실패! 숫자 " << target << "을(를) 찾을 수 없습니다.\n";
    }

    return 0;
}
