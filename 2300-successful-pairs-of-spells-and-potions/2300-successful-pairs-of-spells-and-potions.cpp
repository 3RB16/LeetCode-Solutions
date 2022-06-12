class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = (int)spells.size();
        sort(potions.begin() , potions.end());
        vector <int> queries(n);
        for(int i = 0;i < n;i++) {
          long long targetValue =  (success + spells[i] - 1) / spells[i];
          int index = lower_bound(potions.begin() , potions.end() , targetValue) - potions.begin();
          queries[i] = (int)potions.size() - index;
        }
        return queries;
    }
};