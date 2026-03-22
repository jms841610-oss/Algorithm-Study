#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 멘토(Mentor)를 Key로, 멘티(Mentee)들의 목록을 Value로 저장하는 map
    map<string, vector<string>> mentorMap;

    // 1. 입력 받기
    for(int i = 0; i < N; i++){
        string mento, menti;
        cin >> mento >> menti;
        
        // 해당 멘토의 벡터에 멘티를 바로 추가합니다.
        // map 특성상 키가 없으면 자동으로 빈 vector를 만든 뒤 추가해 줍니다.
        mentorMap[mento].push_back(menti);
    }

    // 2. 정렬 및 출력
    // map은 이미 Key(멘토)를 기준으로 오름차순 정렬이 되어 있습니다.
    for(auto& pair : mentorMap){
        // pair.first는 멘토, pair.second는 멘티들의 vector입니다.
        
        // 멘티 목록을 내림차순(greater)으로 정렬합니다.
        sort(pair.second.begin(), pair.second.end(), greater<string>());

        // 정렬된 멘티들을 차례대로 출력합니다.
        for(const string& menti : pair.second){
            // 멘토와 멘티 사이에 공백을 넣어 출력 형식을 맞춥니다.
            cout << pair.first << " " << menti << "\n";
        }
    }

    return 0;
}
