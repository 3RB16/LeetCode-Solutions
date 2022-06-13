class Solution {
public:
    bool is_same(char a , char b) {
      return tolower(a) == tolower(b) and a != b;  
    }
    string makeGood(string s) {
      stack <char> last;
      for(int i = 0;i < s.size();i++) {
          if(!last.empty() and is_same(last.top() , s[i])){
              last.pop();
              continue;
          }
          last.push(s[i]);
      }  
      string answer = "";
      while(!last.empty()){
         char current = last.top();
         answer = current + answer;
         last.pop();  
      }  
      return answer;
    }
};