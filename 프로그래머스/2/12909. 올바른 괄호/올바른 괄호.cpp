#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    // 💡 복습 포인트: 가장 최근에 열린 괄호를 찾기 위해 LIFO(후입선출) 구조인 Stack을 사용합니다.
    stack<char> st; 
    
    // 문자열 s의 문자를 처음부터 끝까지 순서대로 하나씩 꺼내어 검사합니다.
    for(const char ch : s){
        
        // 1. 스택이 비어있는 경우
        if(st.empty()){
            // 비교할 대상(이전 괄호)이 없으므로 현재 문자를 스택에 넣습니다.
            st.push(ch);
        }else{
            
            // 2. 스택이 비어있지 않은 경우
            // 스택의 가장 위에 있는 문자(가장 최근에 스택에 들어간 문자)를 확인합니다.
            char top = st.top();
            
            // 3. 짝이 맞는 경우 확인
            // 스택의 맨 위가 열린 괄호 '(' 이고, 지금 검사하는 문자가 닫힌 괄호 ')' 라면 온전한 한 쌍이 됩니다.
            if((top == '(') && (ch == ')')){
                // 짝이 맞춰졌으므로 스택에서 해당 열린 괄호를 제거(pop)합니다.
                st.pop();
            }else{
                // 4. 짝이 맞지 않는 경우
                // 열린 괄호 '('가 연속으로 들어오거나, 이미 짝이 어긋난 상태라면 그대로 스택에 쌓습니다.
                st.push(ch);
            }
        }
    }
    
    // 모든 문자에 대한 검사가 끝난 후,
    // 스택이 완전히 비어있다면 모든 괄호가 정상적으로 짝을 이뤄 제거(pop)되었다는 뜻입니다.
    if(st.empty()) answer = true;
    
    // 스택에 문자가 하나라도 남아있다면, 짝을 찾지 못하고 남은 괄호가 있다는 뜻이므로 false입니다.
    else           answer = false;
    
    return answer;
}
