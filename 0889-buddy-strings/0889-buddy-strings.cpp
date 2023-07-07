class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(size(s) != size(goal)) {
            return false;
        }
        int n = int(s.size());
        map<char , map<char , vector<int>>> matrix;
        for(int i = 0;i < n;i++) {
          matrix[s[i]][goal[i]].push_back(i);
        }
        for(char i = 'a';i <= 'z';i++) {
          for(char j = 'a';j <= 'z';j++) {
            if(!matrix[i][j].empty() and !matrix[j][i].empty()){
                int begin = matrix[i][j][0];
                int next = matrix[j][i][0];
                if(begin == next && size(matrix[i][j]) == 1 && size(matrix[j][i]) == 1) {
                    continue;
                }
                if(begin == next)next = matrix[j][i][1];
                swap(s[begin] , s[next]);
                if(s == goal)return true;
                swap(s[begin] , s[next]);
            }
          }  
        }
        return false;
    }
};