class Solution {
public:
    int minSetSize(vector<int>& arr) {
      unordered_map<int , int> frequency;
      for(int item : arr)frequency[item]++;
      priority_queue<pair<int , int>> maxHeap;
      for(auto [key , value] : frequency) {
         maxHeap.push(make_pair(value , key));
      }
      int removed = 0 , answer = 0;
      while(!maxHeap.empty() and removed < arr.size() / 2){
          removed += maxHeap.top().first;
          ++answer;
          maxHeap.pop();
      }
      return answer;
    }
};