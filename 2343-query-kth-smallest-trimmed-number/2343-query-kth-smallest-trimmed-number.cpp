class Solution {
  public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
      vector <int> answer;

      for(const auto query : queries){
        int idx = query[0];
        int k = query[1];
        priority_queue<pair<string , int>> heap;
        for(int i = 0;i < (int)nums.size();i++){
         int st = nums[i].size() - k;
         string cur = nums[i].substr(st , k);
         if(heap.size() < idx)
           heap.push(make_pair(cur , i));
         else {
           if(heap.top().first > cur)
             heap.pop() , heap.push(make_pair(cur , i));
         }
        }
        int index = heap.top().second;
        answer.push_back(index);
      }

      return answer;
    }
};