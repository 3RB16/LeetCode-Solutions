class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<pair<string ,  string>, int>> lettersWithIndex;
        vector <string> digitLogs;
        
        
        auto isLetter = [&](string &log , string &identifier) -> bool{
            vector <string> extractWords;
            log += " ";
            string currentWord = "";
            for(int i = 0;i < int(log.size());i++) {
                if(log[i] == ' '){
                  extractWords.push_back(currentWord);
                  currentWord = "";
                } else {
                  currentWord += log[i];  
                }
            }
            bool allLetters = true;
            
            for(const char letter : extractWords[1])
                if(isdigit(letter))
                    allLetters = false;
            
            identifier = extractWords[0];
            extractWords.erase(extractWords.begin());
            log = "";
            for(const auto word : extractWords)
                log += word , log += " ";
            log.pop_back();
            return allLetters;
        };
        
        for(int i = 0;i < int(logs.size());i++){
            string currentLog = logs[i];
            string identifier = "";
            if(isLetter(currentLog , identifier)) {
               lettersWithIndex.push_back(
                {{currentLog , identifier} , i}
               ); 
            } else {
                digitLogs.push_back(logs[i]);
            }
        }
        
        sort(begin(lettersWithIndex) , end(lettersWithIndex));
        
        vector <string> answer;
        
        for(const auto [word , index] : lettersWithIndex)
            answer.push_back(logs[index]);
        
        for(const auto word : digitLogs)
            answer.push_back(word);
        
        return answer;
    }
};