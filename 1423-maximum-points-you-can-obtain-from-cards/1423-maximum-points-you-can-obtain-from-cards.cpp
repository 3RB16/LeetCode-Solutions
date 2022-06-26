class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int sum = 0;
      for(int cardPoint : cardPoints){
          sum += cardPoint;
      }
      if(k == (int)cardPoints.size())return sum;
      for(int i = 1;i < (int)cardPoints.size();i++)
          cardPoints[i] += cardPoints[i - 1];
      int ans = 1e9;
      int target = (int)cardPoints.size() - k;
      for(int i = 0;i + target - 1 < (int)cardPoints.size();i++) {
         int value = cardPoints[i + target - 1] - (i == 0 ? 0 : cardPoints[i - 1]);
         ans = min(ans , value);
      }
      return sum - ans;
    }
};