/**
 * @file coordinate_compression.cpp
 * @brief 좌표 압축 (Coordinate Compression) 구현
 * @details
 * - 원본 좌표의 값을 대소 관계를 유지한 채 0 ~ (distinct N - 1) 범위로 매핑하는 기법.
 * - 값의 범위가 매우 크지만(e.g., -10^9 ~ 10^9), 개수(N)는 적을 때 유용함.
 * * @algorithm
 * 1. 입력받은 좌표를 복사하여 정렬한다 (O(N log N)).
 * 2. 중복된 값을 제거한다 (unique & erase idiom) (O(N)).
 * 3. 원본 좌표가 정렬된 배열에서 몇 번째 위치하는지 이분 탐색(lower_bound)으로 찾는다 (O(log N)).
 * * @complexity
 * - Time Complexity: O(N log N) (정렬 및 이분 탐색)
 * - Space Complexity: O(N) (두 개의 벡터 저장)
 */

#include <iostream>
#include <vector>
#include <algorithm> // sort, unique, lower_bound

using namespace std;

int main(){
    // [Fast I/O] 입출력 속도 향상
    // C++의 iostream과 C의 stdio 버퍼 동기화를 끊고, cin/cout의 묶음을 풂.
    // 대량의 입출력이 있는 문제(N > 100,000 등)에서 필수적임.
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    // sorted_coordinate: 중복을 제거하고 정렬하여 '기준'이 될 벡터
    // origin_coordinate: 입력 순서를 기억하여 나중에 답을 출력할 벡터
    vector<int> sorted_coordinate;
    vector<int> origin_coordinate;

    // [Optimization] 벡터의 재할당(Reallocation) 방지를 위해 메모리 미리 확보
    sorted_coordinate.reserve(N);
    origin_coordinate.reserve(N);

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        sorted_coordinate.push_back(x);
        origin_coordinate.push_back(x);
    }

    // 1단계: 오름차순 정렬 (Binary Search를 위해 필수)
    // 시간 복잡도: O(N log N)
    sort(sorted_coordinate.begin(), sorted_coordinate.end());

    // 2단계: 중복 제거 (Unique & Erase)
    // std::unique는 중복되지 않은 요소들을 앞으로 모으고, '쓰레기 값'이 시작되는 지점(iterator)을 반환함.
    auto last = unique(sorted_coordinate.begin(), sorted_coordinate.end());
    
    // 실제로 벡터의 뒷부분(쓰레기 값)을 잘라냄.
    sorted_coordinate.erase(last, sorted_coordinate.end());
    
    // 3단계: 압축된 좌표 출력 (Ranking)
    // 원본 좌표가 압축된(정렬+중복제거된) 배열의 몇 번째 인덱스에 해당하는지 찾음.
    for(int j = 0; j < N; j++){
        // std::lower_bound: 정렬된 범위에서 값 이상인 첫 번째 위치(iterator)를 반환 (이분 탐색).
        // 시간 복잡도: O(log N)
        // iterator - begin()을 통해 인덱스(정수)를 구함.
        int idx = lower_bound(sorted_coordinate.begin(), sorted_coordinate.end(), origin_coordinate[j]) 
                  - sorted_coordinate.begin();
        
        cout << idx << " ";
    }

    return 0;
}
