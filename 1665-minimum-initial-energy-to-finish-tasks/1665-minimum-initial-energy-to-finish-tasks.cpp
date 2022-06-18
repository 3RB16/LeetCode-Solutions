class Solution {
    bool can(int energy, vector<vector<int>>&tasks){
        for(int i = 0;i < tasks.size();i++){
            if(energy >= tasks[i][1])
                energy -= tasks[i][0];
            else
                return false;
        }
        return energy >= 0;
    }
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int>&a, vector<int>&b){
           return (a[1] - a[0]) > (b[1] - b[0]); 
        });
        int answer = 0;
        int low = 1, high = 1e9;
        while(low <= high){
            int mid = low + high >> 1;
            if(can(mid , tasks))
            {
                answer = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return answer;
        
    }
};
