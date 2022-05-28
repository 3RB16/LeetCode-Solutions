class Solution {
public:
    void markNodes(int node , int source) {
      for(auto childs : graph[node]){
       if(visited[childs])continue;
       relations.emplace_back(source , childs);
      }
      visited[node] = true;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
      for(auto road : roads){
       int u = road[0];
       int v = road[1];
       graph[u].push_back(v);
       graph[v].push_back(u);
      }
      for(int node = 1;node <= n;++node){
        markNodes(node , node);
      }
      unordered_map<int , int> frequency;
      for(auto [u , v] : relations){
       ++frequency[u];
       ++frequency[v];
      }
      vector <int> cities(n);
      iota(begin(cities) , end(cities) , 0);
      sort(begin(cities) , end(cities) , [&](const auto &u , const auto &v){
        return frequency[u] > frequency[v];
      });
      unordered_map <int , int> hashValue;
      for(auto city : cities)
        hashValue[city] = n--;
      for(auto &[u , v] : relations){
        u = hashValue[u];
        v = hashValue[v];
      }
      long long ans = 0;
      for(auto &[u , v] : relations){
        ans += (u + v);
      }
      return ans;
    }
private:
    unordered_map<int , vector<int>> graph;
    unordered_map<int , bool> visited;
    vector<pair<int , int>> relations;
};