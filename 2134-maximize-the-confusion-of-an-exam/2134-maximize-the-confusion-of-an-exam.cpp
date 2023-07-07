class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
      int max_answers = 0;
      int n = int(answerKey.size());

      for(const char target : {'T' , 'F'}) {
        int begin = 0 , end = 0;
        int cur_k = k;
        while(end < n) {
          if(answerKey[end] != target){
            cur_k--;
          }
          while(cur_k < 0){
            if(answerKey[begin] != target){
              ++cur_k;
            }
            ++begin;
          }
          max_answers = max(max_answers , end - begin + 1); 
          ++end;
        }          
      }
      return max_answers;
    }
};