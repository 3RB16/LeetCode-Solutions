class NumMatrix {
private: 
    vector<vector<int>>prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
       if(matrix.size() == 0 || matrix[0].size() == 0)return;
       prefix.resize(matrix.size() + 1 , vector<int>(matrix[0].size() + 1));
       prefix[0][0] = matrix[0][0];
       for(int i = 1;i < matrix[0].size();i++)
           prefix[0][i] = prefix[0][i - 1] + matrix[0][i];
       for(int i = 1;i < matrix.size();i++)
           prefix[i][0] = prefix[i - 1][0] + matrix[i][0];
        for(int i = 1;i < matrix.size();i++)
            for(int j = 1;j < matrix[0].size();j++)
                prefix[i][j] = matrix[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       int answer = prefix[row2][col2];
       if(row1 - 1 >= 0)answer -= prefix[row1 - 1][col2];
       if(col1 - 1 >= 0)answer -= prefix[row2][col1 - 1];
       if(row1 >= 1 && col1 >= 1)answer += prefix[row1 - 1][col1 - 1];
       return answer;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */