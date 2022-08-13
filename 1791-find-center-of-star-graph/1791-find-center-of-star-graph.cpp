class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
       ios_base::sync_with_stdio(0);
       map<int , int>cnt_edges;
       int n = (int)edges.size();
       int answer = 0 , maxFrequency = 0;
       for(int i = 0;i < n;i++){
          int u = edges[i][0];
          int v = edges[i][1];
          cnt_edges[u]++ , cnt_edges[v]++;
       }

        for(const auto [node , value] : cnt_edges){
           if(value > maxFrequency){
               maxFrequency = value;
               answer = node;
           }
       }
      return answer;
    }
};