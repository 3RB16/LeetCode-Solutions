class WordFilter {
   private:
    unordered_map<string, int> position;

   public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string word = words[i];
            int wordSize = word.size();
            for (int j = 1; j <= wordSize; j++) {
                string p = word.substr(0, j);
                for (int k = 0; k < wordSize; k++) {
                    string s = word.substr(k, wordSize);
                    position[p + "|" + s] = i;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string s = prefix + "|" + suffix;
        return position.find(s) != position.end() ? position[s] : -1;
    }
};