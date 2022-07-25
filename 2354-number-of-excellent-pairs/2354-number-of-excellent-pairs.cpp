class Solution {
public:
 long long countExcellentPairs(vector<int>& A, int k) {
    long long bits[30] = {}, ans = 0;
    for (int n : unordered_set<int>(begin(A), end(A)))
        ++bits[__builtin_popcount(n)];
    for (int i = 1; i < 30; ++i)
        for (int j = 1; j < 30; ++j)
            if (i + j >= k)
                ans += bits[i] * bits[j];
    return ans;
 }
};