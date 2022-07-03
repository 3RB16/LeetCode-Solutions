class Solution {
public:
    string decodeMessage(string key, string message) {
        char cur = 'a';
        unordered_map <char , bool> seen;
        unordered_map <char , char> mapped;
        for(auto item : key) {
            if(item == ' ')continue;
            if(seen[item])continue;
            seen[item] = true;
            mapped[item] = cur++;
        }
        for(auto &item : message){
            if(item == ' ')continue;
            item = mapped[item];
        }
        return message;
    }
};