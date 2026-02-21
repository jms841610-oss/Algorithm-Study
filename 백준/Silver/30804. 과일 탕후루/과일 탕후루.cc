#include <iostream>
#include <vector>

using namespace std;

int get_type(const vector<int> &freq){
    int num = 0;

    for(int i=1;i<10;i++){
        if(freq[i]>0) num++;
    }
    return num;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> line(N);
    vector<int> freq(10,0);
    vector<int> &ref_freq = freq;

    for(int i=0;i<N;i++){
        int type;
        cin >> type;
        line[i] = type;
    }
    int left = 0;
    int max_len = 0;

    for(int right=0;right<N;right++){
        freq[line[right]]++;
        int num_type = get_type(ref_freq);

        while(num_type>2){
            freq[line[left]]--;
            left++;
            num_type = get_type(ref_freq);
        }
        max_len = max(max_len,right-left+1);
    }
    cout << max_len << "\n";

    return 0;
}