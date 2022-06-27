class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        int n = (int)s.size();
        int curLength = 0;
        for(int i = n - 1;i >= 0;i--) {
            if(s[i] == '-')continue;
            ans += toupper(s[i]);
            ++curLength;
            if(curLength == k){
             ans += "-";
             curLength = 0;
            }
        }
        reverse(ans.begin() , ans.end());
        if(ans[0] == '-')ans.erase(ans.begin());
        return ans;
    }
};