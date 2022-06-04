class Solution {
public:
    int findGCD(vector<int>& nums) {
       int minimum = 1001 , maximum = 0;
       for(auto &num : nums) {
        minimum = min(minimum , num);
        maximum = max(maximum , num);
       }
       return __gcd(minimum , maximum);
    }
};