class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int , int> frequency;
        for(auto &digits : num) {
         ++frequency[digits - '0'];
        }
        for(int i = 0;i < num.size();i++){
            if(frequency[i] != (num[i] - '0')){
              return false;
            }
        }
        return true;
    }
};
