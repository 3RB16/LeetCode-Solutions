class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)return false;
        long long cur = 1;
        while(cur <= n) {
            if (cur == n)
                return true;
            cur *= 4;
        }
        return false;
    }
};