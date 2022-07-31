class Solution {
public:
    void addedges(vector<int>&edges,vector<int>adj[]){
        for(int i=0;i<edges.size();i++){
            if(edges[i] == -1)continue;
            adj[i].push_back(edges[i]);
        }
    }
    void bfs(vector<int>adj[],int node,vector<bool>&visited,vector<int>&level){
        visited[node] = true;
        int distance = 0;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            level[u] = distance;
            for(auto i : adj[u]){
                if(visited[i] == false){
                    visited[i] = true;
                    q.push(i);
                }
            }
            distance++;
        }        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>adj[n];
        
        addedges(edges,adj);
        
        vector<int>fromn1(n,INT_MAX),fromn2(n,INT_MAX);    
        
        vector<bool>visited1(n,false),visited2(n,false);
        
        bfs(adj,node1,visited1,fromn1);
        
        bfs(adj,node2,visited2,fromn2);

        int res= INT_MAX, node=-1;
        for(int i=0;i<n;i++){
          if(fromn1[i] == INT_MAX or fromn2[i] == INT_MAX) 
                      continue;
          if(res > max(fromn1[i],fromn2[i])) 
              node = i,res = max(fromn1[i],fromn2[i]);
        }
        return res == INT_MAX? -1 : node;
    }
};