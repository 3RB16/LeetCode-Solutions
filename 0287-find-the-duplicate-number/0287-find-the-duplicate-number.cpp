class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto valid = [&](int cur) {
         int count = 0;
         for(auto &item : nums) {
             count += (cur >= item);
         }
         return count;
        };
        int answer = -1;
        int low = 1 , high = nums.size();
        while(low <= high) {
            int mid = (low + high) / 2;
            int val = valid(mid);
            if(val > mid)
                answer = mid , high = mid - 1;
            else
                low = mid + 1;
        }
        return answer;
    }
};