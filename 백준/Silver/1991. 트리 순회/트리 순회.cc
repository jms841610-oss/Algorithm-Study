#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char,vector<char>> tree;

void preorder(char root){
    if(root=='.'){
        return;
    }
    cout << root;

    preorder(tree[root][0]);

    preorder(tree[root][1]);
}
void inorder (char root){
    if(root=='.'){
        return;
    }
    inorder(tree[root][0]);

    cout << root;

    inorder(tree[root][1]);
}
void postorder (char root){
    if(root=='.'){
        return;
    }
    postorder(tree[root][0]);

    postorder(tree[root][1]);

    cout << root;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        char root;
        vector<char> sub_tree(2);

        cin >> root >> sub_tree[0] >> sub_tree[1];
        tree.insert({root,sub_tree});
    }
    preorder('A');
    cout << "\n";

    inorder('A');
    cout << "\n";

    postorder('A');
    cout << "\n";

    return 0;
}