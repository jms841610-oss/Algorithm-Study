#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,P;
    int W,L,G;
    
    cin >> N >> P;
    cin >> W >> L >> G;

    unordered_map<string,char> player;

    for(int i=0;i<P;i++){
        string name;
        char result;
        cin >> name >> result;
        player[name] = result;
    }
    int total_scr = 0;

    for(int i=0;i<N;i++){
        string name;
        cin >> name;

        if(player.find(name) != player.end()){
            if(player[name]=='W'){
                total_scr += W;
                if(total_scr >= G){
                    cout << "I AM NOT IRONMAN!!" << "\n";
                    return 0;
                }
            }else if(player[name]=='L'){
                total_scr = (total_scr>L) ? total_scr-L : 0;
            }
        }else{
            total_scr = (total_scr>L) ? total_scr-L : 0;
        }
    }
    cout << "I AM IRONMAN!!" << "\n";

    return 0;
}