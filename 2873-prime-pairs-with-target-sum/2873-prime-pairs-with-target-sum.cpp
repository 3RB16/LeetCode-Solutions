/**
  @1 - AC from first time [super testing].
  @2 - Clean Code.
  @3 - Speed.
**/

class Solution {
  private:
    set <int> getPrimes(int n) {
        set <int> primes;
        vector <bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;

        for(int i = 2; i <= n; i++) {
            if(is_prime[i]) {
                primes.insert(i);
                for(int j = i + i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        return primes;
    }

  public:
    vector<vector<int>> findPrimePairs(int n) {
        set <int> primes = getPrimes(n);
        map<int,map<int , bool>> taken;
        vector<vector<int>> pairs;

        for(const int prime : primes) if(primes.count(n - prime) && !taken[prime][n - prime]) {
                pairs.push_back(vector <int> {prime , n - prime});
                taken[prime][n - prime] = taken[n - prime][prime] = true;
        }

        return pairs;
    }
};