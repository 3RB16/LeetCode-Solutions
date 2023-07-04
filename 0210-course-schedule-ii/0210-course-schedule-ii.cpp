class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);                   
        vector<int> ans, indegree(numCourses);               
        for(const auto& prerequisite : prerequisites) {
            int u = prerequisite[0] , v = prerequisite[1];
            graph[v].push_back(u),          
            indegree[u]++;
        }                     
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0) q.push(i);        
        
        while(!q.empty()) {
            auto node = q.front(); q.pop();
            ans.push_back(node);                     
            for(auto nextCourse : graph[node]) 
                if(--indegree[nextCourse] == 0)     
                    q.push(nextCourse);            
        }
        if(size(ans) != numCourses) {
            ans = vector<int>();
        }             
        return ans;                      
    }
};