class Solution {
  public:
    string makeGood(string s) {
        if(s.size() < 2)
            return s;
        stack <int> stk;
        auto need_to_remove = [&](char a, char b) -> bool{
            if(a < b)swap(a, b);
            return (a - 'a') == (b - 'A');
        };
        for(int i = 0; i < int(s.size()); i++) {
            if(stk.empty()) {
                stk.push(i);
            } else {
                if(need_to_remove(s[i], s[stk.top()])) {
                    stk.pop();
                } else {
                    stk.push(i);
                }
            }
        }
        unordered_map <int, int> taken;
        while(stk.size()) {
            taken[stk.top()] = 1;
            stk.pop();
        }
        string ans = "";
        for(int i = 0; i < int(s.size()); i++)
            if(taken[i])ans += s[i];
        return ans;
    }
};