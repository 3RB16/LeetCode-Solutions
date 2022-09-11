class Solution {
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        vector<pair<int, int>> engineers;
        for (int i = 0; i < n; ++i){
            engineers.emplace_back(efficiency[i], speed[i]);
        }
        sort(rbegin(engineers), rend(engineers));
        long speed_sum = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (const auto[efficiency, speed] : engineers) {
            speed_sum += speed;
            min_heap.emplace(speed);
            if (min_heap.size() > k) { 
                speed_sum -= min_heap.top();
                min_heap.pop();
            }
            ans = max(ans, speed_sum * efficiency);
        }
        return ans % (int)(1e9 + 7);
    }
};