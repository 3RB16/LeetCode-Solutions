class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = int(s.size());
        int cnt = 0;
        while(true){
            bool changed = false;
            for(int i = 1;i < n;i++){
                if(s[i] == '1' and s[i - 1] == '0')
                    swap(s[i] , s[i - 1]) , i += 1 , changed = true;
            }
            if(changed == false)
                break;
            ++cnt;
        }
        return cnt;
    }
};
