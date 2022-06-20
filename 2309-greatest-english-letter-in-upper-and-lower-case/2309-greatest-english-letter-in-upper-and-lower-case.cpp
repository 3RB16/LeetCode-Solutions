class Solution {
public:
    string greatestLetter(string s) {
        unordered_map <char , int> seen;
        for(auto &item : s)
            seen[item] = 1;
        string ans = "";
        for(char item = 'A';item <= 'Z';++item)
            if(seen[item] and seen[tolower(item)])
               ans = item;
        return ans;
    }
};