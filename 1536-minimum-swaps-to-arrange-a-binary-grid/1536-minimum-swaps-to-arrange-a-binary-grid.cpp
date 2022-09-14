class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = int(grid.size());
        vector <int> ones(n , 0);
        for(int i = 0;i < n;i++) {
           for(int j = 0;j < grid[i].size();j++)
                if(grid[i][j] == 1)
                  ones[i] = j;
        }
        int cnt = 0;
        for(int i = 0;i < n;i++) {
            int j = i + 1;
            while(ones[i] > i){
              if(j >= n)
                 return -1;
              swap(ones[i] , ones[j++]) , ++cnt;
            }
        }
        return cnt;
    }
};