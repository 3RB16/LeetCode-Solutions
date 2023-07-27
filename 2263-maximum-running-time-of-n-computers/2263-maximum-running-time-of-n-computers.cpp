class Solution {
public:
    bool can(const vector<int>& batteries, long long time, int computers){
        long long ret = time * computers;
        for(long long bTime : batteries) {
            ret -= min(time, bTime);
        }
        return ret <= 0;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0, high = 0;        
        for(const int battery : batteries){
            high += battery;
        }
        
        long long ans = 0;
        while(low <= high){
            
            long long mid = low + high >> 1;
            
            if(can(batteries, mid, n)){//asking for max minutes => increase the time to check if that's possible
                ans = mid;
                low = mid + 1;
            } else {
                 high = mid - 1;//if this particular time isn't possible, reduce the range to mid-1
            }
        }
        
        return ans;
    }
	
	
};