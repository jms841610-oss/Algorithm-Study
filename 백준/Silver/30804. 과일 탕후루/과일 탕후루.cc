#include <iostream>
#include <vector>

using namespace std;

int main(){
    // [최적화] 입출력 스트림 동기화 해제로 실행 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // line: 입력된 전체 과일 순서를 저장하는 배열 (공간 복잡도 O(N))
    vector<int> line(N);
    // freq: 현재 윈도우(구간) 내 각 과일 번호(0~9)의 개수를 저장하는 해시맵 역할 (공간 복잡도 O(1))
    vector<int> freq(10,0);

    for(int i=0;i<N;i++){
        int type;
        cin >> type;
        line[i] = type;
    }
    
    // [투 포인터 및 윈도우 상태 변수]
    int left = 0;
    int max_len = 0;
    int num_type = 0; // 현재 윈도우 내에 존재하는 '과일 종류의 수'를 상수 시간에 추적

    // right 포인터를 우측으로 이동시키며 윈도우를 확장 (시간 복잡도 O(N))
    for(int right=0;right<N;right++){
        // 1. 윈도우 확장 시 새로운 과일 종류 판별
        // 현재 구간에 없던 과일(빈도수 0)이 새로 들어오면 종류 개수(num_type) 1 증가
        if(freq[line[right]]==0) num_type++;
        freq[line[right]]++; // 해당 과일의 등장 횟수 증가

        // 2. 윈도우 축소 (조건: 과일 종류가 2개를 초과할 때)
        // 종류가 2개 이하가 될 때까지 left 포인터를 우측으로 당겨 구간을 줄임
        while(num_type>2){
            freq[line[left]]--; // 가장 왼쪽 과일을 구간에서 제외
            
            // 제외한 후 해당 과일의 빈도수가 0이 되었다면, 그 과일 종류가 완전히 사라진 것임
            if(freq[line[left]]==0) num_type--;
            left++; // left 포인터 이동
        }
        
        // 3. 유효한 구간의 최대 길이 갱신
        // while문을 빠져나왔다는 것은 현재 구간(left ~ right)의 과일 종류가 반드시 2개 이하라는 의미
        // 기존 최대 길이와 현재 구간의 길이(right - left + 1)를 비교하여 최댓값 저장
        max_len = max(max_len,right-left+1);
    }
    
    cout << max_len << "\n";

    return 0;
}
