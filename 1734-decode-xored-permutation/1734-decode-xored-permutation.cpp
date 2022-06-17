class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
       int n = (int)encoded.size() + 1;
       vector <int> perm(n , 0);
       int xors = 0;
       for(int item = 1;item <= n;item++){
           xors ^= item;
           if(item < n && item % 2 == 1)
               xors ^= encoded[item];
       }
       perm[0] = xors;
       for(int i = 1;i < n;i += 1)
           perm[i] = (perm[i - 1] ^ encoded[i - 1]);
       return perm;
    }
};