class Solution {
public:
    string getPermutation(int n, int k) {
      string cur = "";
      char value = '1';
      for(int i = 1;i <= n;i++){
         cur += value++;
      }
      int index = 0;
      string ans = "";
      do{
          ans = cur;
          ++index;
      }while(next_permutation(begin(cur) , end(cur)) && index < k);
      return ans;
    }
};