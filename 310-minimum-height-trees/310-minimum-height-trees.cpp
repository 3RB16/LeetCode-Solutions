class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>> graph;
        unordered_map<int , int> inDegree;
        for(auto &edge : edges){
         graph[edge[0]].push_back(edge[1]);
         graph[edge[1]].push_back(edge[0]);
         ++inDegree[edge[0]];
         ++inDegree[edge[1]];
        }
        queue<int> Q;
        for(int i = 0;i < n;i++)
            if(inDegree[i] == 1)
              Q.push(i);
       vector <int> roots;
       while(!Q.empty()){
        int sizes = Q.size();
        roots.clear();
        while(sizes--){
          auto node = Q.front();
          Q.pop();
          roots.push_back(node);
          for(auto neighbours : graph[node])
            if(--inDegree[neighbours] == 1)
              Q.push(neighbours);
        }
       }
       if(roots.empty())
           roots.push_back(0);
       return roots;
    }
};
