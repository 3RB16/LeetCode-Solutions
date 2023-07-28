class Solution {
public:
    bool winner(int begin,int end , int turn , int player1_sum , int player2_sum, const vector<int> &nums) {
        if(begin > end) {
            return player1_sum >= player2_sum;
        }
        if(turn == 0) {
            return winner(begin + 1 , end , turn ^ 1 , player1_sum + nums[begin] , player2_sum , nums) | 
            winner(begin , end - 1 , turn ^ 1 , player1_sum + nums[end] , player2_sum , nums);
        }
        return winner(begin + 1 , end , turn ^ 1 , player1_sum , player2_sum + nums[begin] , nums) & 
        winner(begin , end - 1 , turn ^ 1 , player1_sum , player2_sum + nums[end] , nums);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = int(nums.size());
        return winner(0 , n - 1 , 0 , 0 , 0 , nums);
    }
};