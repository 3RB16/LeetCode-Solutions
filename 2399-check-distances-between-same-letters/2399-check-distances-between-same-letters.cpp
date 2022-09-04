class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<int ,vector<int>> pos;
        int n = int(s.size());
        for(int i = 0;i < n;i++)
            pos[s[i] - 'a'].push_back(i);

        for(int i = 0;i < 26;i++){
            if(pos[i].empty())continue;
            for(int j = 1;j < pos[i].size();j++){
              int cur_distance = pos[i][j] - pos[i][j - 1] - 1;
              if(cur_distance != distance[i])
                return false;
            }
        }
        return true;
    }
};
