class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int n = int(mat.size());
        int m = int(mat[0].size());
        int ans = 0;
        for(int mask = 1;mask <= (1 << m);++mask){
            set <int> covered;
            for(int i = 0;i < m;i++)
                if(mask & (1 << i))
                  covered.insert(i);
            if((int)covered.size() != cols)
                continue;
            int cnt = 0;
            for(int i = 0;i < n;i++){
                bool found = true;
                for(int j = 0;j < m;j++){
                   if(mat[i][j] == 0)continue;
                   found &= (mat[i][j] == 1 && covered.count(j));
                }
               cnt += found;
            }
            ans = max(ans , cnt);
        }
        return ans;
    }
};