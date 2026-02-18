#include <iostream>

using namespace std;

int main(){
    long long X,Y;

    cin >> X >> Y;

    long long area = X * Y;

    int one_bag = 5 * 4840;

    int need = ((area -1) / one_bag) +1;

    cout << need << endl;

    return 0;
}