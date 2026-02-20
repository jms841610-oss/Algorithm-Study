#include <iostream>
#include <vector>
// #include <climits> // 💡 Tip: LLONG_MAX를 사용하기 위해 추가하면 좋은 헤더

using namespace std;
using dot = pair<int,int>; // 코드 가독성을 높이기 위한 타입 별칭(Type Alias)

int N;

// 점의 개수가 최대 100개라고 가정하고 고정 크기 할당.
// 만약 N이 가변적이라면 main 함수 내에서 vector<dot> coordinate(N); 으로 동적 할당하는 것이 더 유연함.
vector<dot> coordinate(100);

// 주어진 직선의 방정식(y = ax + b)과 실제 점들 사이의 오차 제곱합(RSS)을 구하는 함수
long long get_rss(int a,int b){
    // [중요] 누적 합을 구하기 전, 알 수 없는 쓰레기값이 더해지는 것을 막기 위해 반드시 0으로 초기화!
    long long rss = 0;

    for(int i=0;i<N;i++){
        int x = coordinate[i].first;
        int y = coordinate[i].second;

        // 예측값(기대값) 계산
        int func_val = a * x + b;
        // 실제값과 예측값의 차이(오차)
        int diff = y - func_val;

        // [핵심] int형 변수끼리의 곱셈에서 발생하는 오버플로우를 막기 위한 조치.
        // 곱셈이 수행되기 '전'에 명시적으로 (long long) 형변환을 하여 임시 공간의 크기를 넓힘.
        rss += (long long)diff * diff;
    }
    return rss;
}

int main(){
    cin >> N;

    // 좌표 입력받기
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        
        coordinate[i].first  = x;
        coordinate[i].second = y;
    }
    
    // [주의 요망] 최소값을 찾기 위한 초기 설정값.
    // 현재 1억(100,000,000)으로 설정되어 있으나, 데이터에 따라 오차 제곱합이 이보다 커질 수 있음.
    // 더 안전한 처리를 위해서는 무한대에 가까운 값(예: 9e18 또는 LLONG_MAX)을 사용하는 것을 권장.
    long long min_rss = 100000000;
    
    int min_a = 0;
    int min_b = 0;

    // a와 b의 가능한 모든 범위를 탐색 (완전 탐색, Brute Force)
    // a와 b가 각각 1~100 범위라는 문제의 제약 조건이 있다고 가정.
    for(int a=1;a<=100;a++){
        for(int b=1;b<=100;b++){
            long long current = get_rss(a,b); // 현재 a, b 조합의 오차 제곱합 계산

            // 기존의 최소 오차보다 현재 조합의 오차가 더 작다면 최적의 해 갱신
            if(min_rss > current){
                min_rss = current;
                min_a = a;
                min_b = b;
            }
        }
    }
    
    // 최적의 기울기(a)와 y절편(b) 출력
    cout << min_a << " " << min_b << "\n";

    return 0;
}
