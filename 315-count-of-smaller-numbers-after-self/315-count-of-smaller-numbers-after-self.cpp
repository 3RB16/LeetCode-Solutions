#include <bits/stdtr1c++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace __gnu_cxx;

class Solution {
public:
 struct Treap{ /// hash = 96814
    int len;
    const int ADD = 1000010;
    const int MAXVAL = 1000000010;
    tr1::unordered_map <long long, int> mp; /// Change to int if only int in treap
    tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;
 
    Treap(){
        len = 0;
        T.clear(), mp.clear();
    }
    inline void erase(long long x){
        x += MAXVAL;
        int c = mp[x];
        if (c){
            c--, mp[x]--, len--;
            T.erase((x * ADD) + c);
        }
    }

    inline void clear(){
        len = 0;
        T.clear(), mp.clear();
    }
 
    inline void insert(long long x){
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c);
    }
 
 
    /// Count of value < x in treap
    inline int count(long long x){
        x += MAXVAL;
        int c = mp[--x];
        return (T.order_of_key((x * ADD) + c));
    }
 
    /// Number of elements in treap
    inline int size(){
        return len;
    }
};

    vector<int> countSmaller(vector<int>& nums) {
       Treap have;
       for(const int num : nums)
           have.insert(num);
        vector <int> ans;
        for(const int num : nums){
            int index = have.count(num);
            ans.push_back(index);
            have.erase(num);
        }
        return ans;
    }
};