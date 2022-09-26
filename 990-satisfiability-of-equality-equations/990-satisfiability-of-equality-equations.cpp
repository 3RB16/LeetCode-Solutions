/** one day i will say " I DID IT " , TRUST ME**/
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
using namespace std;


// NEED FOR SPEED
#define ll long long
#define ld long double
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pb push_back
#define UN(x) sort(all(x)),x.erase(unique(all(x)),x.end())


static constexpr int inf = INT_MAX;
static constexpr int MAXN = 1e4 + 5;
static constexpr int MOD = 1e9 + 7;
static constexpr int dx[] = {0, 0, 1, -1};
static constexpr int dy[] = {1, -1, 0, 0};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
      map<char, vector<char>> adj;
      auto add_edge = [&] (char u , char v) -> void{
        adj[u].push_back(v);
        adj[v].push_back(u);
      };
      for(auto equation : equations) {
        char u = equation[0];
        char v = equation.back();
        if(equation[1] == '='){
         add_edge(u , v);
        }
      }
      map<char , bool> vis;
      set <char> comp;
      
      function <void(char )> dfs = [&] (char node) {
       if(vis[node])return;
       vis[node] = 1;
       comp.insert(node);
       for(auto child : adj[node])dfs(child);
      };
      for(auto equation : equations) {
        char u = equation[0];
        char v = equation.back();
        if(equation[1] == '!'){
         vis.clear();
         comp.clear();
         dfs(u);
         if(comp.count(v))return false;
        }
      }
      return true;
    }
};

