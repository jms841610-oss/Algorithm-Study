#include <iostream>
#include <vector>

using namespace std;

// 3. 결합 (Combine): 두 개의 정렬된 부분 배열을 하나로 합치는 함수
void merge(vector<int>& arr, int left, int mid, int right) {
    // 임시로 정렬된 결과를 담을 배열
    vector<int> temp;
    int i = left;       // 왼쪽 부분 배열의 시작점
    int j = mid + 1;    // 오른쪽 부분 배열의 시작점

    // 두 부분 배열의 원소들을 크기 순서대로 비교하여 temp에 넣음
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    // 왼쪽 배열에 남은 원소들이 있다면 몽땅 털어 넣음
    while (i <= mid) temp.push_back(arr[i++]);
    
    // 오른쪽 배열에 남은 원소들이 있다면 몽땅 털어 넣음
    while (j <= right) temp.push_back(arr[j++]);

    // 임시 배열(temp)에 정렬된 결과를 원래 배열(arr)에 덮어씀
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

// 1. 분할 (Divide) & 2. 정복 (Conquer): 배열을 반으로 쪼개는 함수
void mergeSort(vector<int>& arr, int left, int right) {
    // 쪼개진 배열의 크기가 1보다 클 때만 실행 (크기가 1이면 이미 정렬된 것과 같음)
    if (left < right) {
        int mid = left + (right - left) / 2; // 중간 지점 계산

        // 배열을 반으로 나누어 각각 재귀적으로 정복(Conquer)
        mergeSort(arr, left, mid);       // 왼쪽 절반 쪼개기
        mergeSort(arr, mid + 1, right);  // 오른쪽 절반 쪼개기

        // 쪼개서 정렬한 두 배열을 결합(Combine)
        merge(arr, left, mid, right);
    }
}

int main() {
    // 무작위로 섞인 데이터 배열
    vector<int> numbers = {38, 27, 43, 3, 9, 82, 10};

    cout << "정렬 전: ";
    for (int num : numbers) cout << num << " ";
    cout << "\n";

    // 분할 정복(병합 정렬) 실행! (배열의 처음부터 끝까지)
    mergeSort(numbers, 0, numbers.size() - 1);

    cout << "정렬 후: ";
    for (int num : numbers) cout << num << " ";
    cout << "\n";

    return 0;
}
