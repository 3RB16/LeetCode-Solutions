class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string , int> countSenders;
        auto countWords = [&](string word) -> int{
          int count = 1;
          for(char c : word)
            count += c == ' ';
          return count;
        };
        int index = 0;
        for(auto message : messages){
          countSenders[senders[index++]] += countWords(message);
        }
        string largestWord = "";
        int largest = 0;
        for(auto [key , value] : countSenders) {
            if(value > largest){
               largest = value;
               largestWord = key;
            } else if(value == largest){
               largestWord = max(largestWord , key);
            }
        }
        return largestWord;
    }
};