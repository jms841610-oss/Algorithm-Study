#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   string line;
   getline(cin,line);

   vector<string> ans;
   ans.reserve(1000);

   bool is_correct = false;
   
   for(int len=0;len<26;len++){
      stringstream ss(line);
      string word;

      ans.clear();

      while(ss >> word){
         string str = "";

         for(int i=0;i<word.length();i++){
            char ch = word[i];

            if(('A'<=ch)&&(ch<='Z')){
               ch = (ch-'A'-len+26)%26 + 'A';
            }
            str.push_back(ch);
         }
         ans.push_back(str);

         if((str=="CHIPMUNKS")||(str=="LIVE")){
            is_correct = true;
         }
      }
      if(is_correct){
         for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
         }
         cout << "\n";
         break;
      }
   }
   return 0;
}