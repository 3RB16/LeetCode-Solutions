class Solution {
public:
    bool valid(int need , vector<vector<int>>matrix , int k) {
     int n = matrix.size();
     int count = 0;
     for(int i = 0;i < n;i++){
      count += upper_bound(matrix[i].begin() , matrix[i].end() , need) - matrix[i].begin();
     }
     return count >= k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int left = matrix[0][0] , right = matrix[n - 1][n - 1];
        int answer = 0;
        while(left <= right) {
         int mid = (left + right) / 2;
         if(valid(mid , matrix, k)) {
           right = mid - 1; 
           answer = mid;
         } else {
            left = mid + 1;
         }
        }
        
        return answer;
    }
};