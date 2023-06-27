class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int , vector<int>, greater<int>> left , right;
        long long ans = 0;
        int begin = 0 , end = int(costs.size()) - 1;
        int taken = 0;
        while(taken < k) {
           while((int)left.size() < candidates && begin <= end)
              left.push(costs[begin++]);
           while((int)right.size() < candidates && end >= begin)
              right.push(costs[end--]);
           int val_left = left.empty() ? INT_MAX : left.top();
           int val_right = right.empty() ? INT_MAX : right.top();
           if(val_left <= val_right) {
             ans += val_left;
             left.pop();
           } else {
             ans += val_right;
             right.pop();
           }
           ++taken;
        }
        return ans;
    }
};