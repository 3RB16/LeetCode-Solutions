class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_set <int> levels;
        unordered_map <int , int> frequency_tasks;
        for(const int task : tasks){
            levels.insert(task);
            ++frequency_tasks[task];
        }
        int cnt_rounds = 0;
        for(const int level : levels){
            if(frequency_tasks[level] < 2){
                return -1;
            }    
            cnt_rounds += (frequency_tasks[level] + 2) / 3;
        }
        return cnt_rounds;
    }
};