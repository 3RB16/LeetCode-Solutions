class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> heap;
        for(const long long value : nums) {
            heap.push(value);
        }
        int operations_count = 0;
        while(heap.size() > 1) {
            long long x = heap.top();
            heap.pop();
            if (x >= k)break;
            long long y = heap.top();
            heap.pop();
            heap.push(min(x, y) * 2LL + max(x, y));
            operations_count += 1;
        }
        return operations_count;
    }
};