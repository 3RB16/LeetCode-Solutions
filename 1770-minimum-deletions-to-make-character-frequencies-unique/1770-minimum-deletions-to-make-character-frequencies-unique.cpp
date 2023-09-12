class Solution {
public:
    int minDeletions(string s) {
     map<char , int> freq;
     vector <char> has;
     for(char c : s) {
       if(++freq[c] == 1)
        has.push_back(c);
     }
     sort(begin(has) , end(has) , [&](const auto a , const auto b){
       return freq[a] > freq[b];
     });
     int ans = 0;
     unordered_set <int> taken;
     for(int i = 0;i < has.size();i++) {
      int cur = freq[has[i]];
      while(taken.count(cur) && cur > 0){
       ++ans;
       --cur;
      }
      taken.insert(cur);
     }
     return ans;
    }
};