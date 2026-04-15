#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    
    for(const char ch : s){
        if(st.empty()){
            st.push(ch);
        }else{
            char top = st.top();
            
            if((top == '(')&&(ch == ')')){
                st.pop();
            }else{
                st.push(ch);
            }
        }
    }
    if(st.empty()) answer = true;
    else          answer = false;
    return answer;
}