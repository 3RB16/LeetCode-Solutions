const long long mod = 1e9 + 7;

long long Add(int x, int y) {
    int z = x + y ;
    if(z >= mod)
        z -= mod ;
    return z ;
}

long long Sub(int x, int y) {
    int z = x - y ;
    if(z < 0)
        z += mod ;
    return z ;
}

long long Mul(int x, int y) {
    return (x * 1ll * y) % mod ;
}

long long powlog(int base, int power) {
    if(power == 0)
        return 1 ;
    long long x = powlog(base, power / 2) ;
    x = Mul(x, x) ;
    if(power & 1)
        x = Mul(x, base) ;
    return x ;
}

long long modinv(int x) {
    return powlog(x, mod-2) ;
}

long long Div(int x, int y) {
    return Mul(x, modinv(y)) ;
}

struct combination {
    vector<long long>fact, inv ;
    combination(int sz) : fact(sz + 1), inv(sz + 1) {
        fact[0] = 1 ;
        inv[0] = 1 ;
        for(int i = 1 ; i <= sz ; ++i)
            fact[i] = Mul(fact[i-1], i) ;
        inv[sz] = modinv(fact[sz]) ;
        for(int i = sz-1 ; i >= 1 ; --i)
            inv[i] = Mul(inv[i+1], i+1);
    }
    long long choose(int n, int k) const {
        if(k < 0 || n < k)
            return 0 ;
        return Mul(Mul(fact[n], inv[k]), inv[n - k]) ;
    }
};


class Solution {
  public:
    int idealArrays(int n, int maxValue) {
        combination comb(1e5 + 5);
        long long ans = 0;
        for (int i = 1; i <= maxValue; ++i) {

            int x = i;
            map <int, int> mp;

            for (int j = 2; j *1LL* j <= maxValue; ++j) {
                while (x % j == 0) {
                    ++mp[j];
                    x /= j;
                }
            }

            if (x > 1) ++mp[x];

            long long cur = 1;

            for (const auto [k, v] : mp) {
               cur = cur * 1LL* comb.choose(n + v - 1, v);
               cur %= mod;
            }

            (ans += cur) %= mod;
        }

        return ans;
    }
};