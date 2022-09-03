class Solution {
  public:
    bool ok(int number, int base) {
        vector<int> arr;
        while (number) {
            arr.push_back(number % base);
            number /= base;
        }
        vector<int> cur = arr;
        reverse(arr.begin(), arr.end());
        return cur == arr;
    }

    bool isStrictlyPalindromic(int n) {
        for(int base = 2; base <= n - 2; ++base) {
            if(ok(n, base) == false)
                return false;
        }
        return true;
    }
};