#include <iostream>
#include <vector>

using namespace std;

// 그리디 알고리즘을 이용한 최소 동전 개수 구하기 함수
int getMinCoins(int targetAmount, const vector<int>& coinTypes) {
    int totalCoins = 0; // 거슬러 준 동전의 총개수

    // 가장 큰 화폐 단위부터 순서대로 확인 (배열이 내림차순 정렬되어 있다고 가정)
    for (int coin : coinTypes) {
        // 1. 해당 동전으로 거슬러 줄 수 있는 최대 개수를 구하여 더함
        totalCoins += targetAmount / coin;
        
        // 2. 거슬러 주고 남은 나머지 금액으로 타겟 금액을 업데이트
        targetAmount %= coin;
        
        // 3. 남은 금액이 0원이 되면 더 이상 계산할 필요 없이 반복문 종료
        if (targetAmount == 0) {
            break;
        }
    }

    return totalCoins;
}

int main() {
    // 1. 거슬러 주어야 할 총금액
    int amount = 1260; 

    // 2. 사용할 수 있는 동전의 종류 (반드시 '가장 큰 단위부터' 내림차순으로 정렬되어 있어야 함)
    vector<int> coins = {500, 100, 50, 10};

    cout << "거슬러 주어야 할 금액: " << amount << "원\n";

    // 3. 그리디 알고리즘 실행
    int result = getMinCoins(amount, coins);

    // 4. 결과 출력
    cout << "필요한 최소 동전 개수: " << result << "개\n";

    return 0;
}
