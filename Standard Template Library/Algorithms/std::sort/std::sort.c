#include <stdio.h>
#include <stdlib.h>

// 값을 교환하는 유틸리티 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ---------------------------------------------------
// 1. 마무리 투수: 삽입 정렬 (Insertion Sort)
// 크기가 작은 배열에서 압도적으로 빠른 성능을 냅니다.
// ---------------------------------------------------
void insertion_sort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ---------------------------------------------------
// 2. 안전망: 힙 정렬 (Heap Sort) 구현부
// 퀵 정렬이 최악의 상황에 빠졌을 때 구원투수로 등판합니다.
// ---------------------------------------------------
void heapify(int arr[], int n, int i, int offset) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[offset + l] > arr[offset + largest]) largest = l;
    if (r < n && arr[offset + r] > arr[offset + largest]) largest = r;

    if (largest != i) {
        swap(&arr[offset + i], &arr[offset + largest]);
        heapify(arr, n, largest, offset);
    }
}

void heap_sort(int arr[], int left, int right) {
    int n = right - left + 1;
    // 최대 힙(Max Heap) 구성
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, left);
    }
    // 하나씩 추출하며 뒤로 보내기 (오름차순 정렬)
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[left], &arr[left + i]);
        heapify(arr, i, 0, left);
    }
}

// ---------------------------------------------------
// 3. 주전 에이스: 퀵 정렬 (Quick Sort) 파티션 함수
// 배열을 피벗(기준값)을 중심으로 둘로 쪼갭니다.
// ---------------------------------------------------
int partition(int arr[], int left, int right) {
    int pivot = arr[right]; // 맨 오른쪽 값을 기준값으로 설정
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1; // 피벗의 최종 위치 반환
}

// ---------------------------------------------------
// 4. 알고리즘 오케스트라 지휘자: Introsort Core
// 상황에 맞춰 세 가지 정렬 알고리즘을 스위칭합니다.
// ---------------------------------------------------
void introsort_util(int arr[], int left, int right, int depth_limit) {
    int size = right - left + 1;

    // 조건 1: 배열 크기가 16보다 작으면 삽입 정렬로 마무리!
    if (size < 16) {
        insertion_sort(arr, left, right);
        return;
    }

    // 조건 2: 재귀 깊이가 한계에 달하면 (퀵 정렬이 비효율적이 되면) 힙 정렬로 전환!
    if (depth_limit == 0) {
        heap_sort(arr, left, right);
        return;
    }

    // 기본 동작: 퀵 정렬 수행 및 분할
    int pivot_index = partition(arr, left, right);
    
    // 깊이 한계(depth_limit)를 1씩 줄여가며 양쪽을 재귀적으로 정렬
    introsort_util(arr, left, pivot_index - 1, depth_limit - 1);
    introsort_util(arr, pivot_index + 1, right, depth_limit - 1);
}

// 깊이 한계치를 계산하는 함수 ( 2 * log2(N) )
int get_depth_limit(int n) {
    int depth = 0;
    while (n > 1) {
        depth++;
        n /= 2;
    }
    return 2 * depth;
}

// ---------------------------------------------------
// ★ 최종 목표: std::sort 처럼 사용할 수 있는 래퍼 함수
// ---------------------------------------------------
void my_std_sort(int arr[], int n) {
    if (n <= 1) return;
    int depth_limit = get_depth_limit(n);
    introsort_util(arr, 0, n - 1, depth_limit);
}

// 메인 함수: 테스트
int main() {
    int arr[] = {42, 12, 88, 5, 23, 77, 19, 1, 95, 33, 64, 51, 8, 29, 70, 15, 60, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // 우리가 만든 std::sort 실행!
    my_std_sort(arr, n);

    printf("정렬 후: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
