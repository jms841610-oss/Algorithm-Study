#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // max 함수 사용을 위함

using namespace std;

int main(){
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.length();
    int len2 = str2.length();

    // 2차원 DP 테이블 생성 (0으로 초기화)
    // 크기를 (len1 + 1) x (len2 + 1)로 만들어 인덱스 관리를 편하게 합니다.
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    // DP 진행
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            
            // 두 문자가 같다면, 왼쪽 대각선 위(이전 상태)의 값 + 1
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } 
            // 두 문자가 다르다면, 위쪽 혹은 왼쪽의 값 중 더 큰 값
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // 최종 결과는 2차원 배열의 가장 마지막 칸에 저장됩니다.
    cout << dp[len1][len2] << "\n";
    
    return 0;
}
