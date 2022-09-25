struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};


class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        long long n = vals.size();
        vector<vector<int>> adj(n); 
        map<int, vector<int>> pos; 
        set<int> stvals; 
        vector<int> sorted; 

        for (auto u: edges) {
            adj[u[0]].push_back(u[1]); 
            adj[u[1]].push_back(u[0]); 
        }
        
        for (int i = 0; i < n; ++i) {
            if (pos.find(vals[i]) == pos.end()) pos[vals[i]] = {}; 
            pos[vals[i]].push_back(i); 
            stvals.insert(vals[i]); 
        }
        
        for (auto u: stvals) 
            sorted.push_back(u); 
        
        sort(sorted.begin(), sorted.end()); 
        long long ans = n;
        DSU dsu(n); 
        
        for (auto v: sorted) {
            for (auto node: pos[v]) {
                for (auto u: adj[node]) {
                    if (vals[u] <= v) {
                        dsu.unite(node, u); 
                    }
                }
            }
            
            set<int> heads; 
            map<int, int> size;
            for (auto node: pos[v]) {
                int head = dsu.get(node); 
                if (heads.find(head) == heads.end()) {
                    heads.insert(head); 
                    size[head] = 0; 
                }
                size[head]++; 
            }
            
            for (const auto head : heads) {
                ans += (size[head] * (size[head] - 1))/2; 
            }
        }
        return ans;
    }
};
