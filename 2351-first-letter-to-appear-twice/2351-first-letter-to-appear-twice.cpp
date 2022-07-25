class Solution {
public:
    char repeatedCharacter(string s) {
        map<char , int> freq;
        for(const char c : s) {
            if(++freq[c] == 2)
                return c;
        }
        return 'a';
    }
};