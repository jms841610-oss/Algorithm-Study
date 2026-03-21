#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
   // 입출력 속도 향상을 위한 설정
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   string line;
   getline(cin, line);

   vector<string> ans;
   ans.reserve(1000);

   bool is_correct = false;
   
   for(int len = 0; len < 26; len++){
      ans.clear();

      // 수정 포인트 1: 매 반복마다 stringstream을 새로 선언하여 문자열의 처음부터 다시 읽도록 합니다.
      stringstream ss(line);
      string word;

      while(ss >> word){
         string str = "";

         for(int i = 0; i < word.length(); i++){
            char ch = word[i];

            if(('A' <= ch) && (ch <= 'Z')){
               // 수정 포인트 2: 결과가 음수가 되는 것을 방지하기 위해 26을 더해줍니다.
               ch = (ch - 'A' - len + 26) % 26 + 'A';
            }
            str.push_back(ch);
         }
         ans.push_back(str);

         // 정답 단어가 포함되어 있는지 확인
         if((str == "CHIPMUNKS") || (str == "LIVE")){
            is_correct = true;
         }
      }
      
      // 정답을 찾았다면 출력 후 종료
      if(is_correct){
         for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
         }
         cout << "\n";
         break;
      }
   }
   return 0;
}
