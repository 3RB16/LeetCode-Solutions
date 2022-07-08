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


static constexpr int inf = 1e9;
static constexpr int MAXN = 1e2 + 5;
static constexpr int MOD = 1e9 + 7;
static constexpr int dx[] = {0, 0, 1, -1};
static constexpr int dy[] = {1, -1, 0, 0};

class Solution {
public:
    int cache[MAXN][MAXN];
    string a , b , c;
    bool solve(int i , int j) {
     if(i >= sz(a) && j >= sz(b) && i + j >= sz(c)){
       return true;
     }
     if(i + j >= sz(c)){
       return false;
     }
     bool ret = false;
     if(cache[i][j] != -1)return cache[i][j];
     if(a[i] == c[i + j] && i < sz(a)) {
      ret |= solve(i + 1 , j);
     }
     if(b[j] == c[i + j] && j < sz(b)) {
      ret |= solve(i, j + 1);
     }
     return cache[i][j] = ret;
    }
    bool isInterleave(string s1, string s2, string s3) {
     a = s1 , b = s2 , c = s3;
     memset(cache , -1 , sizeof cache);
     return solve(0 , 0);
    }
};
