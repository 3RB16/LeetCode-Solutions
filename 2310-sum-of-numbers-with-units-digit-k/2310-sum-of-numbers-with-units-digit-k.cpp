class Solution {
  public:
    long long cache[310][3001];
    long long solve(vector<int>& array, int i, long long capacity) {
        if(capacity == 0) return 0;
        if(i >= array.size() || capacity < 0) return INT_MAX;
        if(~cache[i][capacity])
            return cache[i][capacity];
        long long take = solve(array , i , capacity - array[i]) + 1;
        long long skip = solve(array , i + 1 , capacity);
        return cache[i][capacity] = min(take, skip);
    }
    int minimumNumbers(int num, int k) {
        vector <int> array;
        for(int i = 1;i <= num;i++)
            if(i % 10 == k)
             array.push_back(i);
        memset(cache, -1, sizeof cache);
        long long ans = solve(array , 0, num);
        return ans >= INT_MAX ? -1 : ans;
    }
};