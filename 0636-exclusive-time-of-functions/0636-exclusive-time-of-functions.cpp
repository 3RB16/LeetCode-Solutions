class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<pair<int,int>> cur;
        int prevTime = 0;
        for (string& log : logs){
            int num = stoi(log.substr(0, log.find(':')));
            int time = stoi(log.substr(log.rfind(':') + 1));
            if (log.find('e') != -1){
                ans[num] += time - prevTime + 1;
                cur.pop();
                prevTime = time + 1;
            } else {
                if (!cur.empty()) {
                    ans[cur.top().first] += time - prevTime;
                }
                cur.push(make_pair(num, time));
                prevTime = time;
            }
        }
        return ans;
    }
};