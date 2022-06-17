class Solution {
public:
    /**
     perm[0] = totalXor XOR perm[1] XOR perm[2] XOR perm[3] XOR perm[4] XOR ... perm[n]
     encoded[1] = perm[1] XOR perm[2]
     encoded[3] = perm[3] XOR perm[4]
    **/
    vector<int> decode(vector<int>& encoded) {
       int n = (int)encoded.size() + 1;
       vector <int> perm(n , 0);
       int xors = 0;
       for(int item = 1;item <= n;item++)
           xors ^= item;
       for(int i = 1;i < n - 1;i += 2)
           xors ^= encoded[i];
       perm[0] = xors;
       for(int i = 1;i < n;i += 1)
           perm[i] = (perm[i - 1] ^ encoded[i - 1]);
       return perm;
    }
};