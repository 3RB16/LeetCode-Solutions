class Solution {
public:
    static const int MAXN = 1e2 + 1;
    int cache[MAXN] , n;
    string message;
    int ways(int index) {
        if(index == n){
            return 1;
        }
        if(message[index] == '0'){
            return 0;
        }
        if(cache[index] != -1){
            return cache[index];
        }
        int ret = ways(index + 1);

      if (index + 1 < n and 
            (message[index] == '1' || message[index] == '2' 
            and message[index + 1] <= '6')){
            ret += ways(index + 2);
        }
        return cache[index] = ret;
    }
    int numDecodings(string s) {
        memset(cache , -1 , sizeof cache);
        message = s , n = int(s.size());
        return ways(0);
    }
};