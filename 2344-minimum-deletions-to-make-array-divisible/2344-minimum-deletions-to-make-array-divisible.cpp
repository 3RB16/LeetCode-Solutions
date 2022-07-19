class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int , int> freq;
        for(const int num : nums)
            ++freq[num];
        int gcd = 0;
        for(const int num : numsDivide)
            gcd = __gcd(gcd , num);
        long long ans = 0;
        bool found = false;
        for(const auto [key , value] : freq){
           found |= (gcd % key == 0);
           if(gcd % key == 0)break;
           ans += value;
        }
        return found ? ans : -1;
    }
};