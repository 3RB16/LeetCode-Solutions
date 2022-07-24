class Solution {
private:
  int getSubMats(vector<int>& arr, int target){
    unordered_map <int, int> mp;
    int sum = 0, count = 0;
    mp[0] = 1;
    for(int i : arr){
        sum += i;
        if(mp.count(sum - target)){
            count += mp[sum - target];
        }
        mp[sum]++;
    }
    return count;
  }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& arr, int target) {
        int r = arr.size(), c = arr[0].size(), answer = 0;
        if(r == 0 or c == 0)
            return 0;

        for(int i = 0; i < r; i++){
            vector<int> rows(c, 0);
            for(int j = i; j < r; j++){
                for(int k = 0; k < c; k++){
                    rows[k] += arr[j][k];
                }
                answer += getSubMats(rows, target);
            }
        }
        return answer;
    }
};
