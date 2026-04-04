#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    // C++ 입출력 속도를 높여주는 설정입니다. (시간 초과 방지)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2; // str1: 전체 문자열, str2: 폭발 문자열

    // 스택 역할을 할 배열 (문자열 최대 길이가 1,000,000이므로 넉넉하게 잡았습니다)
    char stack[1000000] = {};
    
    // idx는 다음에 문자가 들어갈 '빈칸'의 위치를 가리킵니다.
    int idx = 0; 

    int len1 = str1.length();
    int len2 = str2.length();

    // 0번 인덱스부터 원본 문자열의 끝까지 순회합니다.
    for(int i=0; i<len1; i++){
        // 1. [우선 삽입] 현재 문자를 무조건 스택에 넣고 봅니다.
        // 넣은 직후 idx가 1 증가하므로, 방금 넣은 문자는 stack[idx-1]이 됩니다.
        stack[idx++] = str1[i];

        // 2. [조건부 검사] 방금 스택에 넣은 문자가 폭발 문자열의 마지막 글자와 같은지 확인합니다.
        if(stack[idx-1] == str2[len2-1]){
            bool possible = false;

            // 3. 스택에 쌓인 글자 수가 폭발 문자열의 길이 이상일 때만 폭발이 가능합니다.
            if(idx >= len2){
                possible = true; // 일단 폭발이 가능하다고 가정합니다.

                // 4. [역순 검사] 마지막 글자는 이미 확인했으니, 그 앞 글자들을 비교합니다.
                // j=2부터 시작해서 폭발 문자열 길이만큼 앞으로 가면서 검사하는 센스 있는 로직입니다!
                for(int j=2; j<=len2; j++){
                    if(stack[idx-j] != str2[len2-j]){
                        possible = false; // 글자가 하나라도 다르면 폭발 실패
                        break; // 더 이상 볼 필요 없이 반복문 탈출 (시간 절약 핵심!)
                    }
                }
            }
            
            // 5. [폭발 처리] 폭발 문자열과 완벽히 일치한다면?
            if(possible){
                // 인덱스를 폭발 문자열 길이만큼 뒤로 되돌립니다.
                // 배열의 값을 실제로 지우진 않지만, 다음에 문자가 들어올 때 덮어쓰게 되므로 삭제와 같은 효과입니다.
                idx = idx - len2;
            }
        }
    }
    
    // 루프가 끝난 후, 바깥에서 한 번 더 검사하던 중복 코드가 사라졌습니다! (코드 다이어트 성공)

    // 6. [결과 출력] 스택에 문자가 남아있다면 (idx가 0이 아니라면) 처음부터 idx 직전까지 출력합니다.
    if(idx != 0){
        for(int i=0; i<idx; i++){
            cout << stack[i];
        }
        cout << "\n";
    }else{
        // 7. 스택이 비어있다면 모두 폭발하여 사라진 것이므로 문제의 요구사항대로 "FRULA"를 출력합니다.
        cout << "FRULA\n";
    }
    
    return 0;
}
