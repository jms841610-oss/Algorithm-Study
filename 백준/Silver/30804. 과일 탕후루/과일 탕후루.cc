#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> line(N);
    vector<int> freq(10,0);

    for(int i=0;i<N;i++){
        int type;
        cin >> type;
        line[i] = type;
    }
    int left = 0;
    int max_len = 0;
    int num_type = 0;

    for(int right=0;right<N;right++){
        if(freq[line[right]]==0) num_type++;
        freq[line[right]]++;

        while(num_type>2){
            freq[line[left]]--;
            if(freq[line[left]]==0) num_type--;
            left++;
        }
        max_len = max(max_len,right-left+1);
    }
    cout << max_len << "\n";

    return 0;
}