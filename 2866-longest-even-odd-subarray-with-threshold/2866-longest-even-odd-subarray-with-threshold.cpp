/**
  @1 - AC from first time [super testing].
  @2 - Clean Code.
  @3 - Speed.
**/

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = int(nums.size());
        vector<int> alternatings;
        
        for(int begin = 0;begin < n;begin++) if(nums[begin] % 2 == 0 and nums[begin] <= threshold){
            alternatings.push_back(begin);
        }
        
        int longest = 0;
        for(int alternating : alternatings){
            int count = 1;
            for(int next = alternating + 1;next < n;next++){
                if(nums[next] % 2 != nums[next - 1] % 2 and nums[next] <= threshold){
                    count += 1;
                } else {
                    break;
                }
            }
            longest = max(longest , count);
        }
        
        return longest;
    }
};