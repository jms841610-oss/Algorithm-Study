#include <iostream>
#include <vector>

using namespace std;

int main(){
    // 입출력 성능 최적화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        // 인덱스와 숫자를 직관적으로 맞추기 위해 크기를 10으로 할당 (인덱스 1~9 사용)
        vector<int> freq(10);
        // cumulative: 큰 숫자(9)부터 배치할 때 특정 숫자로 넘어가는 분기점(누적합) 기록
        vector<int> cumulative(10);

        // 1. 숫자별 빈도수 입력
        for(int j = 1; j < 10; j++){
            int num;
            cin >> num;
            freq[j] = num;
        }
        
        // 2. 6과 9를 호환 가능한 동일한 숫자로 취급 (9로 통합)
        freq[9] += freq[6];
        freq[6] = 0;
        
        int total = 0;

        // 3. 내림차순(9->1)으로 누적합 계산
        for(int k = 9; k > 0; k--){
            total += freq[k];
            cumulative[k] = total;
        }
        
        int card = 9; // 가장 큰 숫자부터 배치를 시작함
        int idx = 0;  // 결과 배열의 인덱스 위치
        int cnt = 0;  // 현재까지 배치한 카드의 누적 개수
        
        bool is_left = true; // 양방향 교차 배치를 위한 토글 스위치

        // 결과를 담을 배열 (총 카드 개수만큼 할당)
        vector<int> ans(total);

        // 4. 양 끝 포인터를 좁혀가며 숫자 배치
        while(cnt != total){
            // 배치 방향에 따른 인덱스 결정 (바깥에서 안쪽으로)
            if(is_left){
                idx = 0 + cnt / 2;
                is_left = false;
            } else {
                idx = (total - 1) - cnt / 2;
                is_left = true;
            }
            
            // 현재 카드의 누적합이 배치한 개수(cnt)보다 작거나 같으면
            // 해당 번호의 카드를 다 썼다는 의미이므로 다음으로 큰 숫자로 넘어감
            while(cumulative[card] <= cnt){
                card--;
            }
            
            ans[idx] = card; // 결정된 위치와 숫자를 저장
            cnt++;
        }
        
        // 5. 정답 출력 (변수 섀도잉 방지를 위해 루프 변수를 j로 변경)
        for(int j = 0; j < total; j++){
            cout << ans[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
