#include <iostream>
#include <vector>
#include <algorithm> // 정렬을 위해 필요

using namespace std;

// 투 포인터 알고리즘 함수 (합이 target이 되는 두 수의 쌍 찾기)
pair<int, int> twoPointers(const vector<int>& arr, int target) {
    int left = 0;                  // 왼쪽 포인터는 배열의 첫 번째 인덱스(0)에서 시작
    int right = arr.size() - 1;    // 오른쪽 포인터는 배열의 마지막 인덱스에서 시작

    // 두 포인터가 서로 교차하기 전까지 반복
    while (left < right) {
        int currentSum = arr[left] + arr[right]; // 두 포인터가 가리키는 값의 합

        if (currentSum == target) {
            // 1. 합이 타겟과 일치하는 경우 (성공!)
            return {arr[left], arr[right]};
        } 
        else if (currentSum < target) {
            // 2. 합이 타겟보다 작은 경우
            // 값을 키워야 하므로, 왼쪽 포인터를 한 칸 오른쪽으로 이동(+)
            left++;
        } 
        else {
            // 3. 합이 타겟보다 큰 경우
            // 값을 줄여야 하므로, 오른쪽 포인터를 한 칸 왼쪽으로 이동(-)
            right--;
        }
    }

    // 반복문을 다 돌았는데도 조건에 맞는 쌍을 찾지 못한 경우
    return {-1, -1}; 
}

int main() {
    // 1. 탐색할 데이터 배열 (무작위 상태)
    vector<int> numbers = {2, 7, 11, 15, 4, 9, 3};
    int target = 13; // 우리가 만들고 싶은 두 수의 합

    // 2. 양방향 투 포인터를 사용하기 위해 반드시 오름차순 정렬을 해줍니다.
    sort(numbers.begin(), numbers.end());

    cout << "정렬된 데이터: ";
    for (int num : numbers) cout << num << " ";
    cout << "\n\n";

    // 3. 투 포인터 알고리즘 실행
    pair<int, int> result = twoPointers(numbers, target);

    // 4. 결과 출력
    if (result.first != -1) {
        cout << "성공! 합이 " << target << "이(가) 되는 두 수는 " 
             << result.first << "와(과) " << result.second << "입니다.\n";
    } else {
        cout << "실패! 합이 " << target << "이(가) 되는 두 수를 찾을 수 없습니다.\n";
    }

    return 0;
}
