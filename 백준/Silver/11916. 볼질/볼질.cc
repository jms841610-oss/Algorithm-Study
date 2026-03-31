#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int cnt_ball = 0;

    vector<int> area(4,0);

    for(int i=0;i<N;i++){
        int type;
        cin >> type;

        if((type == 1)||(type == 3)) cnt_ball++;

        if((cnt_ball == 4)||(type == 2)||(type == 3)){
            if(((area[1] != 0)&&(area[2] != 0)&&(area[3] != 0))||((type == 3)&&(area[3] != 0))){
                area[0] += area[3];
                area[3] = 0;
            }
            if(((area[1] != 0)&&(area[2] != 0))||((type == 3)&&(area[2] != 0))){
                area[3] += area[2];
                area[2] = 0;
            }
            if((area[1] != 0)){
                area[2] += area[1];
                area[1] = 0;
            }
            if((cnt_ball == 4)||(type == 2)){
                area[1]++;
                cnt_ball = 0;
            }
        }
    }
    cout << area[0];
    return 0;
}