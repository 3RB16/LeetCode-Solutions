class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<int , vector<int>> graph;
        int is_direct[101][101] = {};

        auto create_edge = [&](int u , int v) -> void{
            graph[u].push_back(v);
            graph[v].push_back(u);
            is_direct[u][v] = is_direct[v][u] = 1;
        };
        
        for(auto road : roads) {
            int u = road[0] , v = road[1];
            create_edge(u , v);
        }

        int ans = 0;
        for(int u = 0;u <= 100;u++){
            for(int v = u + 1;v <= 100;v++){
                int res = graph[u].size() + graph[v].size() - is_direct[u][v];
                ans = max(ans, res);
            }
        }

        return ans;
    }
};