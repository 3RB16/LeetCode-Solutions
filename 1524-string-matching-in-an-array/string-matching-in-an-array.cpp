class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_map<string, bool> exist_words;
        for(const string word : words) {
            exist_words[word] = true;
        }
        unordered_set <string> matched_words;
        for(const string word : words) {
         int n = word.size();
         for(int i = 0;i < n;i++) {
            string sub_word = "";
            for(int j = i;j < n;j++) {
                sub_word += word[j];
                if(sub_word != word and exist_words[sub_word]){
                    matched_words.insert(sub_word);
                }
            }
         }
        }

        vector <string> answer;
        for(const auto word : matched_words)
            answer.push_back(word);

        return answer;
    }
};