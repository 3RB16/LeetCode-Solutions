class Solution {
public:
    char findKthBit(int n, int k) {
        map<int ,string> hashing;
        hashing[0] = "0";
        for(int i = 1;i <= 20;i++) {
            string reversed_prefix = hashing[i - 1];
            reverse(reversed_prefix.begin() , reversed_prefix.end());
            for(char &cur : reversed_prefix){
                if(cur == '0')cur = '1';
                else cur = '0';
            }
            hashing[i] = hashing[i - 1] + "1" + reversed_prefix;
        }
        return hashing[n - 1][k - 1];
    }
};
