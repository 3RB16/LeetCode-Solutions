class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    
	//the points from where its possible to flow water to pacific
    vector<vector<bool> > pacific(n, vector<bool> (m,false));
	//same for atlantic
    vector<vector<bool> > atlantic(n, vector<bool> (m,false));
    
	//utility queues for both oceans
    queue<pair<int,int> > pq;
    queue<pair<int,int>> aq;
    
	//push the respective boundary elements to the pacific and atlantic queue and bool array
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0 || j == 0){
                pq.push({i,j});
                pacific[i][j] = true;
            }
            
            if(i == n-1 || j == m-1){
                aq.push({i,j});
                atlantic[i][j] = true;
            }
        }
    }
    
	//final answer array containing commom points
    vector<vector<int> > ans;
    
    bfs(heights, pq, pacific);
    bfs(heights, aq, atlantic);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(pacific[i][j] && atlantic[i][j]){
                ans.push_back({i,j});
            }
        }
    }
    
    return ans;
                                   
}

void bfs(vector<vector<int>> &heights, queue<pair<int,int> > q, vector<vector<bool> > &vis){
    int n = heights.size();
    int m = heights[0].size();
    
	//direction arrays
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {-1,1,0,0};
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
		//iterate all 4 directions
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
			//along with all the eligibility criteria the next coordinates height must be greater than or equal to the current coordinates heights cause we are moving from ocean to island and
			//we want the water to go from island to ocean.
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] == false && heights[nx][ny] >= heights[x][y]){
                q.push({nx,ny});
                vis[nx][ny] = true;
            }
        }
    }
    
    return ;
  }
};