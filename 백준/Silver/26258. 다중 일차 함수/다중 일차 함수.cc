#include <iostream>
#include <vector>
#include <algorithm> // upper_bound를 사용하기 위해 추가

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // x좌표와 y좌표를 따로 저장하거나, 기울기만 따로 저장하여 탐색 효율을 높입니다.
    vector<long long> x_coords(N);
    vector<long long> y_coords(N);

    for (int i = 0; i < N; i++) {
        cin >> x_coords[i] >> y_coords[i];
    }

    // 각 구간의 기울기(증가 1, 감소 -1, 평행 0)를 저장할 벡터
    vector<int> slopes(N - 1);
    for (int i = 0; i < N - 1; i++) {
        if (y_coords[i + 1] > y_coords[i]) {
            slopes[i] = 1;
        } else if (y_coords[i + 1] < y_coords[i]) {
            slopes[i] = -1;
        } else {
            slopes[i] = 0;
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        double query;
        cin >> query;

        // upper_bound: query보다 '초과'하는 첫 번째 원소의 위치(반복자)를 찾습니다.
        auto it = upper_bound(x_coords.begin(), x_coords.end(), query);
 
        // 해당 x좌표의 인덱스를 구한 뒤 1을 빼주면, query가 속한 구간의 인덱스가 됩니다.
        int index = distance(x_coords.begin(), it) - 1;
        cout << slopes[index] << "\n";
        
    }
    return 0;
}
