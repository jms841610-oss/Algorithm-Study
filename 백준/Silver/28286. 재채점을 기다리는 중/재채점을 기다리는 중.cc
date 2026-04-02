#include <iostream>
#include <vector>

using namespace std;

vector<int> push(int p, vector<int> my_answer){
    int size = my_answer.size();

    for(int i=size-1;i>p;i--){
        my_answer[i] = my_answer[i-1];
    }
    my_answer[p] = 0;

    return my_answer;
}
vector<int> pull(int p, vector<int> my_answer){
    int size = my_answer.size();

    for(int i=p;i<size-1;i++){
        my_answer[i] = my_answer[i+1];
    }
    my_answer[size-1] = 0;

    return my_answer;
}
int compare(vector<int> &correct_answer, vector<int> &my_answer){
    int size = correct_answer.size();
    int result = 0;

    for(int i=0;i<size;i++){
        if(correct_answer[i] == my_answer[i]){
            result++;
        }
    }
    return result;
}
void DFS(int depth, int N, int K, int &max_num, vector<int> &correct_answer, vector<int> my_answer){
    max_num = max(max_num, compare(correct_answer, my_answer));

    if(depth == K) return;

    for(int i=0;i<N;i++){
        DFS(depth+1, N, K, max_num, correct_answer, push(i, my_answer));

        DFS(depth+1, N, K, max_num, correct_answer, pull(i, my_answer));
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> correct_answer(N);
    vector<int> my_answer(N);

    for(int i=0;i<N;i++){
        cin >> correct_answer[i];
    }
    for(int i=0;i<N;i++){
        cin >> my_answer[i];
    }
    int max_num = 0;
    DFS(0, N, K, max_num, correct_answer, my_answer);
    
    cout << max_num << "\n";
    return 0;
}