#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    // 입출력 속도 최적화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        // freq: 1~9까지 숫자의 등장 횟수를 저장
        // (참고: 키가 1~9로 작고 고정되어 있으므로 vector<int> 사용을 권장하지만 원본 유지)
        unordered_map<int,int> freq;
        // cumulative: 큰 숫자(9)부터 작은 숫자(1) 순으로 누적된 카드 개수
        vector<int> cumulative(11);

        // 1. 숫자 빈도수 입력 (내부 변수를 j로 변경하여 변수 섀도잉 방지)
        for(int j = 1; j < 10; j++){
            int num;
            cin >> num;
            freq[j] = num;
        }
        
        // 2. 6과 9를 상호 호환 처리 (6의 개수를 모두 9로 몰아줌)
        freq[9] += freq[6];
        freq[6] = 0;
        
        int total = 0;

        // 3. 누적합 계산 (9부터 1까지 내림차순)
        for(int j = 9; j > 0; j--){
            total += freq[j];
            cumulative[j] = total; // 누적합 기록 (이 숫자로 넘어가는 임계점이 됨)
        }
        
        int card = 9; // 현재 배치할 숫자 (가장 큰 수부터 시작)
        int idx = 0;  // 배열에 들어갈 인덱스
        int cnt = 0;  // 현재까지 배치한 카드의 총 개수
        
        bool is_left = true; // 양끝 교차 배치를 위한 플래그

        vector<int> ans(total); // 결과를 저장할 배열

        // 4. 양끝에서부터 교차하며 숫자 배치 (투 포인터 방식 응용)
        while(cnt != total){
            if(is_left){
                // 왼쪽 끝에서부터 안쪽으로 들어오는 인덱스
                idx = 0 + cnt / 2;
                is_left = false;
            } else {
                // 오른쪽 끝에서부터 안쪽으로 들어오는 인덱스
                idx = (total - 1) - cnt / 2;
                is_left = true;
            }

            // 누적합을 확인하여 현재 'card' 번호를 다 썼다면 더 작은 번호로 넘어감
            while(cumulative[card] <= cnt){
                card--;
            }
            
            // 계산된 위치에 카드 배치
            ans[idx] = card;
            cnt++;
        }
        
        // 5. 정답 출력
        for(int j = 0; j < total; j++){
            cout << ans[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
