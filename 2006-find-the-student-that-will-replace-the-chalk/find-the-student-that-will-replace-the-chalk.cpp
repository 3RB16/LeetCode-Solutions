class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
      long long sum = accumulate(begin(chalk), end(chalk), 0LL);
      int rem = k % sum;
      for(int i = 0;i < chalk.size();i++) {
        if(chalk[i] > rem) {
            return i;
        }
        rem -= chalk[i];
      }
      return 0;
    }
};