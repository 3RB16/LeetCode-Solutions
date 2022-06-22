class Solution {
public:
    int findMinFibonacciNumbers(int k) {
      vector <long long> fib;
      fib.push_back(1);
      fib.push_back(1);
      while(fib.back() <= 1e9){
       int cur_size = (int)fib.size();
       fib.push_back(
        fib[cur_size - 1] + fib[cur_size - 2]
        );
      }
      int cnt = 0;
      while(k > 0) {
        ++cnt;
        int idx = upper_bound(begin(fib) , end(fib) , k) - fib.begin();
        --idx;
        k -= fib[idx];
      }
      return cnt;
    }
};