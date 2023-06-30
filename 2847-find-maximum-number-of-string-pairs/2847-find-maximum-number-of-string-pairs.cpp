class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int count = 0;
        map<string , int> pairs;
        for(const string word : words) {
            string cur_word = word;
            reverse(begin(cur_word) , end(cur_word));
            count += pairs[cur_word];
            pairs[word]++;
        }
        return count;
    }
};