class Solution {
public:
    int minimumLengthEncoding(vector<string> &words) {
        set<string> good(begin(words) , end(words));
        for (string word: words) {
            for (int k = 1; k < word.length(); ++k)
                good.erase(word.substr(k));
        }

        int ans = 0;
        for (auto word: good)
            ans += word.length() + 1;
        return ans;
    }
};