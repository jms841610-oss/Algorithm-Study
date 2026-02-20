#include <iostream>
#include <vector>

using namespace std;
using dot = pair<int,int>;

int N;

vector<dot> coordinate(100);

long long get_rss(int a,int b){
    long long rss = 0;

    for(int i=0;i<N;i++){
        int x = coordinate[i].first;
        int y = coordinate[i].second;

        int func_val = a * x + b;
        int diff = y - func_val;

        rss += (long long)diff * diff;
    }
    return rss;
}
int main(){
    cin >> N;

    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        
        coordinate[i].first  = x;
        coordinate[i].second = y;
    }
    long long min_rss = 100000000;
    
    int min_a = 0;
    int min_b = 0;

    for(int a=1;a<=100;a++){
        for(int b=1;b<=100;b++){
            long long current = get_rss(a,b);

            if(min_rss>current){
                min_rss = current;
                min_a = a;
                min_b = b;
            }
        }
    }
    cout << min_a << " " << min_b << "\n";

    return 0;
}