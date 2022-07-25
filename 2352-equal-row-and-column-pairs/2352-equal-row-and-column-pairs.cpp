class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int> , int> freq;
        for(int row = 0;row <  grid.size();++row){
            freq[grid[row]]++;
        }
        int count = 0;
        for(int row = 0;row <  grid.size();++row){
          vector <int> extract;
          for(int col = 0;col < grid.size();++col)
              extract.push_back(grid[col][row]);
          count += freq[extract];
        }
        return count;
    }
};