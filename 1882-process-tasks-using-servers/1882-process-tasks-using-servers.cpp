class Solution {
  public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<long , long> ,  vector<pair<long , long>> ,
                       greater<pair<long , long>>> available_servers, busy_servers;
        for(int index = 0; index < (int)servers.size(); ++index) {
            available_servers.push({servers[index], index});
        }
        vector <int> answer(tasks.size(), 0);
        long seconds = 0;
        for(long index = 0; index < tasks.size(); ++index) {
            seconds = max(seconds , index);
            if(available_servers.empty() && busy_servers.top().first > seconds){
                seconds = busy_servers.top().first;
            }
            while(!busy_servers.empty() && busy_servers.top().first <= seconds){
                auto [time , idx] = busy_servers.top();
                available_servers.push({servers[idx] , idx});
                busy_servers.pop();
            }
            auto [time , idx] = available_servers.top();
            busy_servers.push({seconds + tasks[index] , idx});
            answer[index] = idx;
            available_servers.pop();
        }
        return answer;
    }
};