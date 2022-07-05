class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int ans = 0;
       unordered_set <int> have;
       for(auto item : nums) {
           have.insert(item);
       }
       for(auto item : have){
         if(!have.count(item - 1)){
          int cnt = 1 , cur = item;
          while(have.count(cur + 1))++cur , ++cnt;
          ans = max(ans , cnt);
         }  
       } 
       return ans;
    }
};