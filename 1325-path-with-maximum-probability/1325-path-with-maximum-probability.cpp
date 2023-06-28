class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector <double> dist(n , 0.0);
        vector<vector<pair<int , double>>> graph(n);
        int index = 0;
        for(vector<int> edge : edges) {
            int u = edge[0] , v = edge[1];
            graph[u].push_back(make_pair(v , succProb[index]));
            graph[v].push_back(make_pair(u , succProb[index++]));
        }

        queue<int> q;
        q.push(start);
        dist[start] = 1.0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto [child , Probability] : graph[node]){
                double newProbability = dist[node] * Probability;
                if(newProbability > dist[child]){
                    dist[child] = newProbability;
                    q.push(child);                
                }
            }
        }

        return dist[end];
    }
};