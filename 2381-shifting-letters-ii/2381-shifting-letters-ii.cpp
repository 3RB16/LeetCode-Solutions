class Solution {
  public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = int(s.size());
        vector <int> ranges(n + 5, 0);
        for(const vector <int> shift : shifts){
            int l = shift[0];
            int r = shift[1];
            int d = shift[2];
            if(d){
             ++ranges[l];
             --ranges[r + 1];
            } else {
             --ranges[l];
             ++ranges[r + 1];
            }
        }
        for(int i = 1;i <= n;i++)
            ranges[i] += ranges[i - 1];
        vector <int> cur(n , 0);
        string ans = "";
        for(int i = 0;i < n;i++){
            cur[i] = (s[i] - 'a') + ranges[i];
            while(cur[i] < 0)
                cur[i] += 26;
            cur[i] %= 26;
            ans += char(cur[i] + 'a');
        }
        return ans;
    }
};