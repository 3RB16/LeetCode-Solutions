/**
  @1 - AC from first time [super testing].
  @2 - Clean Code.
  @3 - Speed.
**/
struct SegmentTreeNode {
    int min_val;
    int max_val;
};

struct SegmentTree {
    vector<int> arr;
    vector<SegmentTreeNode> tree;
    int n;

    SegmentTree(const vector<int>& nums) {
        arr = nums;
        n = nums.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node].min_val = arr[start];
            tree[node].max_val = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node].min_val = min(tree[2 * node + 1].min_val, tree[2 * node + 2].min_val);
            tree[node].max_val = max(tree[2 * node + 1].max_val, tree[2 * node + 2].max_val);
        }
    }

    SegmentTreeNode query(int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return {INT_MAX, INT_MIN};
        }
        if (left <= start && right >= end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        SegmentTreeNode left_child = query(2 * node + 1, start, mid, left, right);
        SegmentTreeNode right_child = query(2 * node + 2, mid + 1, end, left, right);
        return {
            min(left_child.min_val, right_child.min_val),
            max(left_child.max_val, right_child.max_val)
        };
    }
};


class Solution {
  public:
    long long continuousSubarrays(vector<int>& nums) {
        int count = 0;
        SegmentTree st(nums);
        int n = int(nums.size());
        long long ans = 0;
        int p1 = 0;
        for(int p2 = 1; p2 < n; p2++)while(p1 < p2) {
                SegmentTreeNode res = st.query(0, 0, st.n - 1, p1, p2 - 1);
                int mini = res.min_val , maxi = res.max_val;
                if(abs(nums[p2] - mini) <= 2 && abs(nums[p2] - maxi) <= 2) break;
                ans += p2 - p1;
                p1++;
        }
        long long left = n - p1;
        return ans + (left *1LL* (left + 1) >> 1);
    }
};