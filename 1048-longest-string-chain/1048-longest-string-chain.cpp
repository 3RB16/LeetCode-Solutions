class Solution {
public:
    int longestStrChain(vector<string>& words) {
       unordered_map<string , int> dp;
       sort(words.begin() , words.end() , [&](string word1 , string word2){
           return word1.size() < word2.size();
       });
       int longest = 0;
       for(int i = 0;i < (int)words.size();i++){
        int n = (int)words[i].size();
        for(int j = 0;j < n;j++){
          string cur = words[i].substr(0 , j) +  words[i].substr(j + 1, n);
          dp[words[i]] = max(dp[words[i]] , 1 + dp[cur]);
        }
        longest = max(longest , dp[words[i]]);
       }
       return longest;
    }
};