#include <iostream>
#include <string>

using namespace std;

string N,M,Q,R;

string reversing(string a){
    int len = a.size();

    for(int i=0;i<len/2;i++){
        char tmp = a[i];
        a[i] = a[len-i-1];
        a[len-i-1] = tmp;
    }
    return a;
}
string subtracting(string a,string b){
    if(a==b) return "0";
    
    string result = "";

    a = reversing(a);
    b = reversing(b);

    int len_a = a.size();
    int len_b = b.size();
    int bring = 0;

    for(int i=0;i<len_a;i++){
        int a_ele = a[i] - '0';
        int b_ele = (len_b > i) ? (b[i] - '0') : 0;
        int ele_sum = a_ele - b_ele - bring;

        if(ele_sum<0){
            ele_sum += 10;
            bring = 1;
        }else{
            bring = 0;
        }
        result.push_back(ele_sum + '0');
    }
    result = reversing(result);

    while((result[0]=='0')&&(result.size()>0)) result.erase(0,1);

    return result;
}
bool is_bigger(string a,string b){
    if     (a.size() > b.size()) return true;
    else if(a.size() < b.size()) return false;
    else                         return (a>=b);
}
void dividing(){
    Q = "";
    R = "";

    for(char digit : N){
        R.push_back(digit);

        while((R[0]=='0')&&(R.size()>0)) R.erase(0,1);

        int cnt = 0;

        while(is_bigger(R,M)){
            R = subtracting(R,M);
            cnt++;
        }
        Q.push_back(cnt + '0');
    }
    int len_Q = Q.size();
    int cnt_Q = 0;

    for(int i=0;i<len_Q;i++){
        if(Q[i]!='0'){
            cnt_Q = i;
            break;
        }
    }
    Q.erase(0,cnt_Q);

    if(Q.empty()) Q = "0";
    if(R.empty()) R = "0";

    return;
}
int main(){
    cin >> N >> M;

    dividing();

    cout << Q << endl << R << endl;

    return 0;
}