class Solution { 
public:                                    
    int rangeBitwiseAnd(int left, int right) { 
        int ans = 0;
        for(int bit = 30;bit >= 0;bit--){
            if((left & (1 << bit)) != (right & (1 << bit)))
                break;
            else
                if(left & (1 << bit))ans |= (1 << bit);
        }
        return ans;
    }
};