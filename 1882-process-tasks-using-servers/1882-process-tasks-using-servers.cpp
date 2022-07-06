class Solution {
  public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<array<long, 3>, vector<array<long, 3>>,
                       greater<array<long, 3>>> available_servers, busy_servers;
        for(int index = 0; index < (int)servers.size(); ++index) {
            available_servers.push({0, servers[index], index});
        }
        vector <int> answer(tasks.size(), 0);
        for(long index = 0; index < tasks.size(); ++index) {
            while(!busy_servers.empty() && (busy_servers.top()[0] <= index || available_servers.empty())) {
                auto [time, weight, i] = busy_servers.top();
                busy_servers.pop();
                available_servers.push({time <= index ? 0 : time, weight, i});
            }
            auto [time, weight, i] = available_servers.top();
            available_servers.pop();
            busy_servers.push({max(time, index) + tasks[index], weight, i});
            answer[index] = i;
        }
        return answer;
    }
};