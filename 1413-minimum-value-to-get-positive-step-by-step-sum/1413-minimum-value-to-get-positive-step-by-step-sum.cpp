class Solution {
public:
    bool can(int val , vector <int> &arr) {
     for(int it : arr){
        val += it;
        if(val < 1)
            return false;
     }
     return true;
    }
    int minStartValue(vector<int>& nums) {
        int low = 1 , high = 1e5;
        while(low <= high){
            int mid = low + high >> 1;
            if(can(mid , nums))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};