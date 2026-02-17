#include <iostream>
#include <vector>

using namespace std;

int N,M,B;
int max_height = 0;
int min_time = 500*500*256*2;

vector<int> frequency(257,0);

void flattening(){
    for(int target_height=0;target_height<257;target_height++){
        int needed_block = 0;
        int getted_block = 0;
        for(int current_height=0;current_height<257;current_height++){
            if(current_height>target_height) getted_block += (current_height-target_height) * frequency[current_height];
            else                             needed_block += (target_height-current_height) * frequency[current_height];
        }
        if((getted_block+B) >= needed_block){
            int target_time = getted_block*2 + needed_block;
            if(target_time <= min_time){
                min_time = target_time;
                max_height = target_height;
            }
        }  
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> B;

    for(int row=0;row<N;row++){
        for(int col=0;col<M;col++){
            int height;
            cin >> height;
            frequency[height]++;
        }
    }
    flattening();

    cout << min_time << " " << max_height << endl;

    return 0;
}