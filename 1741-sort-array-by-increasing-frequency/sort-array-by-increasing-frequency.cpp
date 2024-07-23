class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int , int> map;
        
        for(const auto item : nums) {
            map[item] += 1;
        }

        auto cmp = [&](const auto &x , const auto &y){
            return (map[x] == map[y] ? x > y : map[x] < map[y]);
        };

        sort(nums.begin() , nums.end() , cmp);

        return nums;
    }
};