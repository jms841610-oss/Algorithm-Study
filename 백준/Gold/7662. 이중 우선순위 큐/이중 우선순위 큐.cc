#include <iostream>
#include <set>

using namespace std;

int main(){
    // [최적화] C++ 입출력 속도 향상
    // C와 C++의 버퍼를 분리하고, cin/cout의 묶음을 풀어 속도를 대폭 높임
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        int k;
        cin >> k;
        
        // [핵심 자료구조] 이중 우선순위 큐 역할을 수행할 multiset
        // 1. 중복된 값을 허용 (set 대신 multiset 사용)
        // 2. 내부적으로 오름차순 정렬 상태를 항상 유지 (Red-Black Tree 구조)
        multiset<int> ms;

        for(int j=0;j<k;j++){
            char command;
            cin >> command;

            if(command=='I'){
                int num;
                cin >> num;
                // 삽입 시 자동으로 정렬 위치를 찾아 들어감: O(log K)
                ms.emplace(num);

            }else if(command=='D'){
                int num;
                cin >> num;

                // 큐가 비어있지 않을 때만 삭제 연산 수행
                if(!ms.empty()){ 

                    if(num==1){
                        // [주의점] 최댓값 삭제
                        // ms.end()는 마지막 원소 '다음'의 가상(Past-the-end) 공간을 가리킴
                        // 따라서 prev()를 사용해 반복자를 한 칸 앞으로 옮겨 실제 마지막 원소(최댓값)를 지목해야 함
                        ms.erase(prev(ms.end()));
                        
                    }else if(num==-1){
                        // 최솟값 삭제
                        // ms.begin()은 트리의 가장 왼쪽 아래 노드(최솟값)를 정확히 가리킴
                        ms.erase(ms.begin());
                    }
                }
            }
        }
        
        // 모든 연산이 끝난 후 출력 처리
        if(!ms.empty()){
            // *ms.rbegin(): 역방향 반복자의 시작점 = 실제 최댓값
            // *ms.begin(): 정방향 반복자의 시작점 = 실제 최솟값
            cout << *ms.rbegin() << " " << *ms.begin() << "\n";
        }else{
            cout << "EMPTY\n";
        }
    }
    return 0;
}
