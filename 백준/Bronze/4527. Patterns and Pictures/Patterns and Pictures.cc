#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        int I;
        cin >> I;

        int pattern = 0;

        for(int i=0;i<I;i++){
            int S,R;
            cin >> S >> R;

            pattern += S*R;
        }
        int one_square_yard = 36*36;
        int two_square_yard = 2*36*36;
        int three_square_yard = 3*36*36;

        cout << one_square_yard/pattern << " ";
        cout << two_square_yard/pattern << " ";
        cout << three_square_yard/pattern << "\n";
    }
    return 0;
}