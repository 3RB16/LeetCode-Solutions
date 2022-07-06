class Solution {
public:
    map<int , int> cache;
    int solve(int value){
     if(value == 1)return 0;
     if(cache.count(value))return cache[value];
     if(value & 1)
         return 1 + solve(3 * value + 1);
     return 1 + solve(value >> 1);
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> pairs;
        for(int i = lo;i <= hi;i++){
          pairs.push_back(make_pair(
            solve(i) , i
          ));  
        }
        sort(begin(pairs) , end(pairs));
        return pairs[k - 1].second;
    }
};