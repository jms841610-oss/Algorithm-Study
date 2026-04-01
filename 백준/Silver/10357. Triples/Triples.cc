#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void reverse(string &a){
    int len = a.length();

    for(int i=0;i<len/2;i++){
        char tmp = a[i];
        a[i] = a[len-1-i];
        a[len-1-i] = tmp;
    }
    return;
}
string add(string a, string b){
    string result = "";

    int len_a = a.length();
    int len_b = b.length();
    int max_len = max(len_a, len_b);

    int bring = 0;

    for(int i=0;i<max_len;i++){
        char ch_a = (len_a-1 >= i) ? a[i] : '0';
        char ch_b = (len_b-1 >= i) ? b[i] : '0';

        int sub_sum = (ch_a - '0') + (ch_b - '0') + bring;
        
        result.push_back((sub_sum % 10) + '0');
 
        bring = sub_sum / 10;
    }
    if(bring != 0) result.push_back(bring + '0');

    return result;
}
string multi(string a, string b){
    if((a == "0")||(b == "0")) return "0";

    string result = "0";
    
    for(int i=0;i<b.length();i++){
        string tmp = "";

        for(int j=0;j<i;j++) tmp.push_back('0');

        int pass = 0;

        for(int j=0;j<a.length();j++){
            int current = (a[j] - '0') * (b[i] - '0') + pass;
            tmp.push_back((current % 10) + '0');
            pass = current / 10;
        }
        if(pass != 0) tmp.push_back(pass + '0');
        result = add(result, tmp);
    }
    return result;
}
string square(int a, int b){
    if(a == 0) return "0";

    string result = "1";
    string string_a = to_string(a);
    reverse(string_a);

    for(int i=0;i<b;i++){
        result = multi(result, string_a);
    }
    return result;
}
int get_num(int m, int j){
    int result = 0;

    vector<string> square_j(m+1);

    for(int i=0;i<=m;i++){
        square_j[i] = square(i, j);
    }
    for(int x=0;x<=m;x++){
        for(int y=x;y<=m;y++){
            string add_x_y = add(square_j[x], square_j[y]);

            for(int z=y;z<=m;z++){
                if(add_x_y == square_j[z]){
                    result++;
                }
            }
        }
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    int ans = 0;

    for(int j=2;j<=n;j++){
        ans += get_num(m, j);
    }
    cout << ans << "\n";
    return 0;
}