class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int , unordered_map<char , bool>> frequencylist;
        int ans = 0 , index = 0;
        for(auto &word : words){
           unordered_map<char , bool> frequency;
           for(auto &c : word)frequency[c] = true;
           frequencylist[index++] = frequency;
        }
        for(int i = 0;i < words.size();i++){
           for(int j = i + 1;j < words.size();j++){
            bool valid = true;
            for(char c = 'a';c <= 'z';c++) {
             if(frequencylist[i][c] && frequencylist[j][c]){
               valid = false;
               break;
             }
            }
            if(valid){
             ans = max(ans , (int)words[i].size() * (int)words[j].size());
            }
           }
        }
        return ans;
    }
};