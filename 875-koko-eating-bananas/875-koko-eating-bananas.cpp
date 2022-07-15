class Solution {
public:
    bool can(int mid ,vector<int>& piles , int h){
       int cnt = 0;
       for(int i = 0;i < (int)piles.size();i++){
           cnt += (piles[i] / mid) + (piles[i] % mid != 0);
       }
       return (cnt <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        ios_base::sync_with_stdio(0);
        int l = 1 , r = 1e9;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(can(mid ,piles,h))
                r = mid;
            else l = mid + 1;
        }
        return l;
    }
};