#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t=0;t<T;t++){
        string func;
        cin >> func;

        int len;
        cin >> len;

        string digit_in_str = "";

        deque<int> dq;

        while(true){
            char ele;
            cin >> ele;

            if(('0'<=ele)&&(ele<='9')){
                digit_in_str += ele;
            }else{
                if(!digit_in_str.empty()){
                    dq.push_back(stoi(digit_in_str));
                    digit_in_str = "";
                }
            }
            if(ele==']') break;
        }
        bool is_reversed = false;
        bool is_error = false;

        for(char const &command : func){
            if(command=='R'){
                is_reversed = !is_reversed;
            }else if(command=='D'){
                if(dq.empty()){
                    is_error = true;
                    break;
                }
                if(!is_reversed){
                    dq.pop_front();
                }else{
                    dq.pop_back();
                }
            }
        }
        if(is_error){
            cout << "error" << "\n";
        }else{
            if(!dq.empty()){
                cout << "[";
                if(!is_reversed){
                    for(int i=0;i<dq.size()-1;i++){
                        cout << dq[i] << ",";
                    }
                    cout << dq[dq.size()-1] << "]" << "\n";
                }else{
                    for(int i=dq.size()-1;i>0;i--){
                        cout << dq[i] << ",";
                    }
                    cout << dq[0] << "]" << "\n";
                }
            }else{
                cout << "[]" << "\n";
            }
        }
    }
    return 0;
}