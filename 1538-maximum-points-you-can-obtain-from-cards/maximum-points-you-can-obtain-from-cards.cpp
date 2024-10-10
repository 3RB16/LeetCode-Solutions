class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = int(cardPoints.size());
        vector<long long> prefix(n + 1, 0), suffix(n + 1, 0);
        for(int i = 0;i < n;i++) {
            prefix[i + 1] = prefix[i] + cardPoints[i];
        }
        for(int i = n - 1;i >= 0;i--) {
            suffix[i] = suffix[i + 1] + cardPoints[i];
        }
        //reverse(begin(suffix), end(suffix));
        long long max_score = 0;
        for(int i = 0;i <= k;i++) {
            int rem = n - (k - i);
            max_score = max(max_score, prefix[i] + (rem < 0 ? 0 : suffix[rem]));
        }

        return max_score;
    }
};