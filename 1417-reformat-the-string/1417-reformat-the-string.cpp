class Solution {
  public:
    string reformat(string s) {
        deque <char> digits, letters;
        for(auto item : s) {
            if(isdigit(item)) {
                digits.push_back(item);
            } else {
                letters.push_back(item);
            }
        }
        if(abs((int)letters.size() - (int)digits.size()) > 1)
            return "";
        string ans = "";
        if(letters.size() > digits.size()) {
            ans += letters.front();
            letters.pop_front();
        } else {
            ans += digits.front();
            digits.pop_front();
        }
        while((int)ans.size() < (int)s.size()) {
            if(isdigit(ans.back())) {
                ans += letters.front();
                letters.pop_front();
            } else {
                ans += digits.front();
                digits.pop_front();
            }
        }
        return ans;
    }
};