class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>bitCount(32 , 0);
        for(int bit = 0;bit < 32;bit++) {
           for(const int num : nums){
             if(num & (1 << bit)){
                bitCount[bit]++; 
             }  
           } 
        }

        int distinctNumber = 0;
        for(int bit = 0;bit < 32;bit++)if(bitCount[bit] % 3 != 0){
            distinctNumber |= (1 << bit);
        }

        return distinctNumber;
    }
};