#include <iostream>

using namespace std;
using pos = pair<int,int>;

void visiting(pos target,pos current,int len,int &idx){
    if(len==1){
        cout << idx << "\n";
    }else{
        len /= 2;

        bool is_up = true;
        bool is_left = true;

        if(target.first >= current.first + len){
            is_up = false;
        }
        if(target.second >= current.second + len){
            is_left = false;
        }
        if((is_up)&&(is_left)){
            visiting(target,current,len,idx);
        }else if((is_up)&&(!is_left)){
            current.second += len;
            idx += len * len;
            visiting(target,current,len,idx);
        }else if((!is_up)&&(is_left)){
            current.first += len;
            idx += len * len * 2;
            visiting(target,current,len,idx);
        }else if((!is_up)&&(!is_left)){
            current.first += len;
            current.second += len;
            idx += len * len * 3;
            visiting(target,current,len,idx);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,row,col;
    cin >> N >> row >> col;

    int len = 1;

    for(int i=0;i<N;i++){
        len *= 2;
    }
    pos start;
    start.first = 0;
    start.second = 0;
    
    pos target;
    target.first = row;
    target.second = col;

    int idx = 0;

    visiting(target,start,len,idx);

    return 0;
}