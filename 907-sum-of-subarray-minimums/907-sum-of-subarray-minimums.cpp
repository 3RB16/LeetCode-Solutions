class Solution {
public:
static constexpr int inf = (int)1e9;
static constexpr int MAXN = 2e5 + 5;
static constexpr int MOD = 1e9 + 7;
static constexpr int dx[] = {0, 0, 1, -1};
static constexpr int dy[] = {1, -1, 0, 0};

struct segTree {
    vector <pair<long long, long long>> tree;
    vector <int> data;
    segTree(int n,vector <int> data) : data(data) {
        tree.resize(4 * n, make_pair(inf, inf));
        build(1, 0, n - 1);
    }
    void build(int node, int left, int right) {
        if(left == right) {
            tree[node] = make_pair(left, data[left]);
            return;
        }
        int mid = left + (right - left) / 2;
        build(node * 2, left, mid);
        build(node * 2 + 1, mid + 1, right);
        if(tree[node * 2].first < tree[node * 2 + 1].first) {
            tree[node] = tree[node * 2];
        } else {
            tree[node] = tree[node * 2 + 1];
        }
    }
    pair<long long, long long> query(int node, int i, int j, int l, int r) {
        if(i >= l && j <= r) {
            return tree[node];
        }
        if(j < l || i > r)return make_pair(-1, inf);
        int mid = i + (j - i) / 2;
        pair<long long, long long> left = query(node * 2, i, mid, l, r);
        pair<long long, long long> right = query(node * 2 + 1, mid + 1, j, l, r);
        if(left.first < right.first) {
            return left;
        } else {
            return right;
        }
    }
    long long solve(int l, int r) {
        if(l <= r) {
            int n = data.size();
            pair<long long, long long> res = query(1, 0, n - 1, l, r);
            int index = res.first;
            long long ans = (index - l + 1) *1LL* (r - index + 1) * 1LL * data[index];
            return (solve(l, index - 1) + solve(index + 1, r) + ans % MOD) % MOD;
        }
        return 0;
    }
};

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<pair<int, int>> stk;
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (!stk.empty() && stk.top().first > arr[i]) {
            count += stk.top().second;
            stk.pop();
        }
        stk.push(make_pair(arr[i], count));
        left[i] = count;
    }
    while(!stk.empty())stk.pop();
    for (int i = n - 1; i >= 0; --i) {
        int count = 1;
        while (!stk.empty() && stk.top().first >= arr[i]) {
            count += stk.top().second;
            stk.pop();
        }
        stk.push(make_pair(arr[i], count));
        right[i] = count;
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = (ans + arr[i] *1LL* left[i] *1LL* right[i]) % MOD;
    }
    return ans;
 }
};