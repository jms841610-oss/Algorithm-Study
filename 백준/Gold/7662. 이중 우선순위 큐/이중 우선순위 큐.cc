#include <iostream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        int k;
        cin >> k;
        
        multiset<int> ms;

        for(int j=0;j<k;j++){
            char command;
            cin >> command;

            if(command=='I'){
                int num;
                cin >> num;
                ms.emplace(num);

            }else if(command=='D'){
                int num;
                cin >> num;

                if(!ms.empty()){ 

                    if(num==1){
                        ms.erase(prev(ms.end()));
                        
                    }else if(num==-1){
                        ms.erase(ms.begin());
                    }
                }
            }
        }
        if(!ms.empty()){
            cout << *ms.rbegin() << " " << *ms.begin() << "\n";
        }else{
            cout << "EMPTY\n";
        }
    }
    return 0;
}