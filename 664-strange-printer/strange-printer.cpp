/***
    There is a strange printer with the following two special properties:

    The printer can only print a sequence of the same character each time.
    At each turn, the printer can print new characters starting from and ending
    at any place and will cover the original existing characters.

    Given a string s, return the minimum number of turns the printer needed to print it.
***/


class Solution {
  public:
    int solve(int i,int j,const string& s, vector<vector<int>>& dp) {
        //Base Case
        if(i == j) {
            return 1; // if only one character is present just return 1
        }
        if(~dp[i][j]) {
            return dp[i][j];
        }
        int ret = INT_MAX;
        for(int index = i; index < j; index += 1) {
            ret = min(ret,solve(i, index, s,dp) + solve(index + 1, j, s, dp));
        }
        ret = (s[i] == s[j] ? ret - 1 : ret);
        return dp[i][j] = ret;
    }
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n - 1, s, dp);

    }
};