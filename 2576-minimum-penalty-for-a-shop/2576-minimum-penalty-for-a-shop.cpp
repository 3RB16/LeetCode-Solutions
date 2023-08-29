class Solution {
public:
    int bestClosingTime(string customers) {
        int n = int(customers.size());
        vector <int> closed(n + 1) , opened(n + 1);
        closed[0] = 0;
        for(int i = 1;i <= n;i++) {
            closed[i] = closed[i - 1] + (customers[i - 1] == 'N');
        }
        opened.back() = (customers.back() == 'Y');
        for(int i = n - 1;i >= 0;i--) {
            opened[i] = opened[i + 1] + (customers[i] == 'Y');
        }
        int ans = INT_MAX , res = INT_MAX;
        for(int i = 0;i <= n;i++) {
            int cur_res = opened[i] + (i == 0 ? 0 : closed[i - 1]);
            if(cur_res < res) {
                res = cur_res;
                ans = i;
            } else if(cur_res == res) {
               ans = min(ans, i);
            }
        }
        return ans;
    }
};