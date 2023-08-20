class Solution {
public:
    int dp[2][2][13][13][13][21];
    
    int countBeautifulIntegers(bool isStarted, bool isLower, int pos, int oddDigits, int evenDigits, int mod, string &ub, int k)
    {
        if(pos >= ub.size()){
            return (isStarted == 1 && (oddDigits == evenDigits) && mod == 0);
        }
        
        if(dp[isStarted][isLower][pos][oddDigits][evenDigits][mod] != -1)
            return dp[isStarted][isLower][pos][oddDigits][evenDigits][mod];
        
        int maxDigit = isLower? 9 : ub[pos] - '0';
        int minDigit = isStarted? 0 : 1;
        
        int ret = 0;
        
        if(!isStarted)
            ret += countBeautifulIntegers(isStarted, 1, pos+1, oddDigits, evenDigits, mod, ub, k);
        
        for(int digit = minDigit ; digit <= maxDigit ; digit++) {
            
            bool isOdd = (digit & 1);
            ret += countBeautifulIntegers(1, isLower | (digit < maxDigit), pos+1, oddDigits + isOdd, evenDigits + (isOdd == 0), ((mod * 10) + digit)%k, ub, k);
        }
        
        return dp[isStarted][isLower][pos][oddDigits][evenDigits][mod] = ret;
    }
    
    int numberOfBeautifulIntegers(int low, int high, int k) {
        
        string ub = to_string(high);
        memset(dp, -1, sizeof(dp));
        
        int countTillUb = countBeautifulIntegers(0, 0, 0, 0, 0, 0, ub, k);
        
        string lb = to_string(low-1);
        memset(dp, -1, sizeof(dp));
        
        int countTillLb = countBeautifulIntegers(0, 0, 0, 0, 0, 0, lb, k);
                
        return countTillUb - countTillLb;
    }
};
