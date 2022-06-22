class Solution {
public:
    vector <string> ans;
    unordered_map<string , bool> vis;
    void solve(int n , string &s) {
     if((int)s.size() == n){
      if(!vis[s]){
        ans.push_back(s);
        vis[s] = true;
      }
      return;
     }
     for(char i = 'a';i <= 'c';i++){
        if(!s.empty() && s.back() == i)continue;
        s += i;
        solve(n , s);
        s.pop_back();
     }
    }
    string getHappyString(int n, int k) {
      ans.clear();
      vis.clear();
      string s = "";
      solve(n , s);
      sort(begin(ans) , end(ans));
      return (int)ans.size() < k ? "" : ans[k - 1];
    }
};