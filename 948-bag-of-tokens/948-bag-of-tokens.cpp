class Solution {
public:
 int bagOfTokensScore(vector<int>& tokens, int power) {
  sort(begin(tokens) , end(tokens));
  int points = 0;
  int start = 0 , end = tokens.size() - 1;
  int answer = 0;
  while(start <= end) {
    if(power >= tokens[start]) {
      ++points;
      power -= tokens[start++];
      answer = max(answer , points);
    } else if(points > 0) {
      --points;
      power += tokens[end--];
    } else {
      break;
    }
  }
  return answer;
 }
};