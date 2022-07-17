class Solution {
public:
    int memo[1001][1001];
    bool init = true;
    int kInversePairs(int n, int k) {
        
        if(init){
            memset(memo , -1 , sizeof memo);
            init = false;
        }
            
        if (n == 0)
            return 0;
        if (k == 0)
            return 1;
        if (memo[n][k] != -1)
            return memo[n][k];
        int inv = 0;
        for (int i = 0; i <= min(k, n - 1); i++)
            inv = (inv + kInversePairs(n - 1, k - i)) % 1000000007;
        return  memo[n][k] = inv;
    }
};