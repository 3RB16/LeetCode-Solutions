class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector <int> target = paint(pattern);
        vector <string> answer;
        for(const string word : words){
            vector <int> current = paint(word);
            if(current == target)
                answer.push_back(word);
        }
        return answer;
    }
private:
    vector <int> paint(string current) {
        int color = 1;
        unordered_map <char , int> seen;
        vector <int> to_return;
        for(int i = 0;i < int(current.size());i++){
            if(!seen[current[i]])
                seen[current[i]] = color++;
            to_return.push_back(seen[current[i]]);
        }
        return to_return;
    }
};