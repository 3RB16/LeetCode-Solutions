class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int , vector<int>> pos;
        int index =  0;
        for(int t : time) {
            pos[t].push_back(index++);
        }
        int ans = 0;
        for(int u = 1;u <= 500;u++){
          for(int v = 1;v <= 500;v++){
            if((u + v) % 60)continue;
            if(!pos[u].empty() && !pos[v].empty()){
               int n = pos[v].size();
               for(int it : pos[u]){
                   int next = upper_bound(begin(pos[v]) , end(pos[v]) , it) - begin(pos[v]);
                   ans += (n - next);
               }
            }
          }
        }
        return ans;
    }
};