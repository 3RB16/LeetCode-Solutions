class Solution {
public:
    int memo[1005][1005];
    int solve(int steps , int val , int copy , int n) {
     if(val > n || steps > n)return INT_MAX;
     if(val == n)return steps;
     int &ret = memo[steps][val];
     if(~ret)return ret;
     int paste = solve(steps + 1 , val + copy , copy , n);
     int copies = solve(steps + 2 , val * 2 , val , n); // step + 2 cuz we will copy & paste
     return ret = min(paste , copies);
    }
    int minSteps(int n) {
      memset(memo , -1 , sizeof(memo));
      return(n == 1 ? 0 : solve(0 , 0 , 1 , n));
    }
};