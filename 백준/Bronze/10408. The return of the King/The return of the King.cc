#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    getline(cin,line); // 띄어쓰기를 포함해 한 줄 전체를 가져옴
    
    int len = line.length();

    int cnt = 0;
    int total = 0;
    bool is_ten = false;

    // 뒤에서부터 순회
    for(int i = len - 1; i >= 0; i--){
        // 1. 방금 전에 '0'을 만났고, 이번 문자가 '1'일 때 (즉, "10"의 완성)
        if((is_ten) && (line[i] == '1')){
            total += 10;
            cnt++;
            is_ten = false; // 플래그를 정확히 소멸시킴 (아주 좋음)
        }
        // 2. 현재 문자가 '0'일 때
        else if(line[i] == '0'){
            is_ten = true; 
            // [오류 포인트] 여기서 0점을 무조건 "10"의 예비 단계로만 취급합니다.
            // 만약 진짜 0점이었다면 여기서 점수 누락이 발생합니다.
        }
        // 3. '0'이 아니고 "10"의 '1'도 아닐 때 ('2'~'9', 공백 문자, '1' 등)
        else{
            total += line[i] - '0'; // 문자를 숫자로 변환
            // [오류 포인트] line[i]가 공백(' ')이면 의도치 않은 쓰레기값(-16)이 더해집니다.
            cnt++;
            is_ten = false; // 다른 숫자를 만났으므로 기존에 켜져 있던 10의 예비 플래그를 취소함
        }
    }
    
    // [오류 포인트] cnt가 0일 경우 (예: "0"만 입력되었을 때) 0으로 나누기 발생
    double avg = (double)total / cnt;

    cout << fixed << setprecision(2);
    cout << avg << "\n";

    return 0;
}
