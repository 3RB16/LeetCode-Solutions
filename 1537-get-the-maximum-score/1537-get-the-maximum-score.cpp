class Solution {
private:
    unordered_map <int,vector<int>> graph;
    unordered_map <int, long long> indeg, dist;
    int MOD = 1e9 + 7;
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums1.size() - 1; i++) {
            int u = nums1[i], v = nums1[i + 1];
            graph[u].push_back(v);
            indeg[v]++;
            dist[u] = dist[v] = INT_MIN;
        }
        
        for(int i = 0; i < nums2.size() - 1; i++) {
            int u = nums2[i], v = nums2[i + 1];
            graph[u].push_back(v);
            indeg[v]++;
            dist[u] = dist[v] = INT_MIN;
        }
        
        queue <int> q;
        
        for(const auto it : graph) {
            int node = it.first;
            if(!indeg[node]) {
                q.push(node);
                dist[node] = node;
            }
        }
        
        long long ans = -1;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            ans = max(ans, dist[u]);
            
            for(const auto v : graph[u]) {
                dist[v] = max(dist[v], dist[u] + v);       
                if(--indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return (int)(ans % MOD);
    }
};
