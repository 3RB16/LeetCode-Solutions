class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int ,int> next_greater;
        stack <int> previous_values;

        for(const int num : nums2) {
            while(previous_values.size() and previous_values.top() < num) {
                int cur_value = previous_values.top();
                next_greater[cur_value] = num;
                previous_values.pop();
            }
            previous_values.push(num);
        }
        int n = int(nums1.size());
        vector <int> next_greater_values(n , -1);
        for(int i = 0;i < n;i++) if(next_greater.count(nums1[i])){
            next_greater_values[i] = next_greater[nums1[i]];
        }

        return next_greater_values;
    }
};