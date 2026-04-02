#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void back_order(int current_idx, int current_val, vector<vector<int>> &tree, unordered_map<int,int> &key){
    if((tree[current_idx][0] == -1)&&(tree[current_idx][1] == -1)){
        cout << current_val << "\n";
        return;
    }
    if(tree[current_idx][0] != -1){
        int next_idx = tree[current_idx][0];
        back_order(next_idx, key[next_idx], tree, key);
    }
    if(tree[current_idx][1] != -1){
        int next_idx = tree[current_idx][1];
        back_order(next_idx, key[next_idx], tree, key);
    }

    cout << current_val << "\n";

    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int,int> key;

    int key_val;
    int cnt = 0;

    while(cin >> key_val){
        key[cnt++] = key_val;
    }
    vector<vector<int>> tree(cnt,vector<int>(2,-1));

    for(int i=1;i<cnt;i++){
        int root_val = key[0];
        int root_idx = 0;

        int node_val = key[i];
        int node_idx = i;

        while(true){
            if(node_val < root_val){
                if(tree[root_idx][0] == -1){
                    tree[root_idx][0] = node_idx;
                    break;
                }else{
                    root_idx = tree[root_idx][0];
                    root_val = key[root_idx];
                }
            }else{
                if(tree[root_idx][1] == -1){
                    tree[root_idx][1] = node_idx;
                    break;
                }else{
                    root_idx = tree[root_idx][1];
                    root_val = key[root_idx];
                }
            }
        }
    }
    back_order(0, key[0], tree, key);
    return 0;
}