class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string answer = "";
        int cur_index = 0;
        for(int i = 0;i < int(s.size());i++) {
           if(cur_index < int(spaces.size()) and i == spaces[cur_index]) {
                answer += " ";
                cur_index += 1;
           }
           answer += s[i];
        }
        return answer;
    }
};