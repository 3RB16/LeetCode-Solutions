class Solution {
public:
     int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1;
        vector<bool> visited(n,false);
        vector<int> dist_from_start(n,-1);
        
        function<void(int, int)> dfs = [&](int node, int curlen) {
            if(!visited[node]) {
                visited[node] = true;
                dist_from_start[node] = curlen;
                if(edges[node] != -1) dfs(edges[node], curlen+1);
                dist_from_start[node] = -1;
            }
            else {
                if(dist_from_start[node] != -1)
                    ans = max(ans, curlen - dist_from_start[node]);
            }
        };
        
        for(int i=0; i<n; ++i) {
            if(visited[i]) continue;
            dfs(i , 0);
        }
        return ans;
    }
};