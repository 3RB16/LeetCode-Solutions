class Solution {
public:
 
vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
  set <int> has[105];
  for(int i = 0;i < 105;i++){
    has[i].clear();
  }
  for(int i = 0;i < (int)nums.size();i++){
    has[nums[i]].insert(i);
  }
  vector <int> answer;
  for(int idx = 0;idx < (int)queries.size();idx++) {
   int l = queries[idx][0];
   int r = queries[idx][1];
   int prv = -1;
   int res = INT_MAX;
   for(int i = 1;i <= 100;i++) {
    if(has[i].empty())continue;
    if(*has[i].rbegin() < l)continue;
    auto nxt = has[i].lower_bound(l);
    if(*nxt > r)continue;
    if(prv == -1){
     prv = i;
     continue;
    }
    res = min(res , i - prv);
    prv = i;
   }
   if(res == INT_MAX)res = -1;
   answer.push_back(res);
  }
  return answer;
}
};