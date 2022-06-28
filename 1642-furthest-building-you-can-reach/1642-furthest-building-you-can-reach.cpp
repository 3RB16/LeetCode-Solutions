class Solution {
public:
    
    bool can(vector<int> heights, int bricks, int ladders, int mid){
		vector<int> diff;
        for(int i = 1; i <= mid; i++){
            if(heights[i] > heights[i-1]){
                diff.push_back(heights[i]-heights[i-1]);
            }
        }
        sort(diff.begin(), diff.end(), greater<int>());
        int l = diff.size();
        for(int i = ladders; i < l; i++){
            if(diff[i] > bricks) return false;
            bricks -= diff[i];
        }
        return true;
    }
    
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int lo = 0, hi = n - 1;
        while(lo < hi){
            int mid = (lo + hi + 1) / 2;
            if(can(heights, bricks, ladders, mid)){
                lo = mid; 
            } else{
                hi = mid - 1;
            }
        }
        return lo;
    }
};
