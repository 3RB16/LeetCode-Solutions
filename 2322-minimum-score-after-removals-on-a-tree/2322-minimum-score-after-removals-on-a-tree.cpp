class Solution {
private:
    vector <int> nums;
    unordered_map <int, vector<int>> graph;
    unordered_map <int, bool> seen;
    map<int, int> xors, in, out;
    int timer = 1;
    void dfs(int node) {
        seen[node] = true;
        in[node] = timer++;
        xors[node] = nums[node];
        for(auto child : graph[node]) {
            if(!seen[child]) {
                dfs(child);
                xors[node] ^= xors[child];
            }
        }
        out[node] = timer - 1;
    }
    bool is_ancestor(int u, int v) {
        return in[u] <= in[v] && out[u] >= out[v];
    }
public:
    int minimumScore(vector<int>& _nums, vector<vector<int>>& edges) {
        nums = _nums;
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(0);
        int n = _nums.size();
        int ans = INT_MAX;
        for(int u = 1; u < n; u++) {
            for(int v = u + 1; v < n; v++) {
                int first = xors[0] ^ xors[u] ^ xors[v];
                int second = xors[u];
                int third = xors[v];
                if(is_ancestor(u, v)) {
                    first = xors[0] ^ xors[u];
                    second = xors[u] ^ xors[v];
                }
                if(is_ancestor(v, u)) {
                    first = xors[0] ^ xors[v];
                    second = xors[v] ^ xors[u];
                    third = xors[u];
                }
                ans = min(ans, max(first, max(second, third))
                          - min(first, min(second, third))
                         );

            }
        }
        return ans;
    }
};