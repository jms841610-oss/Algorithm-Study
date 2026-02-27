#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int D(int n){
    return (2*n)%10000;
}
int S(int n){
    if(n==0) return 9999;
    else     return n-1;
}
int L(int n){
    if(n==0) return 0;

    int digit[4];
    int Q = 1000;

    for(int i=0;i<4;i++){
        int d = n / Q;
        digit[i] = d;
        n %= Q;
        Q /= 10;
    }
    return ((digit[1] * 10 + digit[2]) * 10 + digit[3]) * 10 + digit[0];
}
int R(int n){
    if(n==0) return 0;

    int digit[4];
    int Q = 1000;

    for(int i=0;i<4;i++){
        int d = n / Q;
        digit[i] = d;
        n %= Q;
        Q /= 10;
    }
    return ((digit[3] * 10 + digit[0]) * 10 + digit[1]) * 10 + digit[2];
}
string BFS(int A,int B){
    vector<int> parent(10000);
    vector<char> command(10000);
    vector<bool> is_visited(10000,false);
    queue<int> order;

    order.push(A);
    is_visited[A] = true;
    parent[A] = A;

    while(!order.empty()){
        int current = order.front();
        order.pop();

        if(current==B){
            string result = "";

            while(current!=A){
                result += command[current];
                current = parent[current];
            }
            int len = result.length();

            for(int i=0;i<len/2;i++){
                char temp = result[i];
                result[i] = result[len-1-i];
                result[len-1-i] = temp;
            }
            return result;
        }
        int D_val = D(current);
        int S_val = S(current);
        int L_val = L(current);
        int R_val = R(current);

        if(!is_visited[D_val]){
            order.push(D_val);
            is_visited[D_val] = true;
            parent[D_val] = current;
            command[D_val] = 'D';
        }
        if(!is_visited[S_val]){
            order.push(S_val);
            is_visited[S_val] = true;
            parent[S_val] = current;
            command[S_val] = 'S';
        }
        if(!is_visited[L_val]){
            order.push(L_val);
            is_visited[L_val] = true;
            parent[L_val] = current;
            command[L_val] = 'L';
        }
        if(!is_visited[R_val]){
            order.push(R_val);
            is_visited[R_val] = true;
            parent[R_val] = current;
            command[R_val] = 'R';
        }
    }
    return "ERROR";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        int A,B;
        cin >> A >> B;

        string command = BFS(A,B);

        cout << command << "\n";
    }
    return 0;
}