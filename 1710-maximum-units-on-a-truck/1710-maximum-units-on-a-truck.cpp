class Solution {
public:
 int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
  auto compare = [&](const auto &x , const auto &y) {
   return x[1] > y[1];
  };
  sort(begin(boxTypes) , end(boxTypes) , compare);
  int answer = 0;
  for(int i = 0;i < boxTypes.size() && truckSize > 0;i++){
    int mini = boxTypes[i][0];
    mini = min(mini , truckSize);
    answer += (mini * boxTypes[i][1]);
    truckSize -= mini;
  }
  return answer;
 }

};